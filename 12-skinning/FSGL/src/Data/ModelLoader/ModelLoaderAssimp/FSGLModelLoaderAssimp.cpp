/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSModelLoaderObj.cpp
 * Author: demensdeum
 * 
 * Created on July 9, 2017, 10:07 AM
 */

#include "FSGLModelLoaderAssimp.h"

#include <fstream>
#include <iostream>
#include <regex>

#include <string>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "../../NodeAnimation/FSGLNodeAnimation.h"

using namespace std;

FSGLModelLoaderAssimp::FSGLModelLoaderAssimp() {
}

FSGLModelLoaderAssimp::FSGLModelLoaderAssimp(const FSGLModelLoaderAssimp& orig) {
}

shared_ptr<FSGLModel> FSGLModelLoaderAssimp::loadModel(shared_ptr<string> modelPath) {

    auto modelPathString = modelPath->c_str();

    auto model = make_shared<FSGLModel>();

    model->path = modelPath;

    Assimp::Importer importer;
    auto scene = importer.ReadFile(modelPathString, aiProcessPreset_TargetRealtime_Fast);

    if (scene == NULL) {

        cout << "FSGLModelLoaderAssimp: cannot load model at path " << modelPath->c_str() << endl;

        exit(1);
    }

    if (scene->HasMeshes() == true) {

        for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; meshIndex++) {

            auto mesh = scene->mMeshes[meshIndex];

            auto convertedMesh = make_shared<FSGLMesh>();

            for (unsigned int vertexIndex = 0; vertexIndex < mesh->mNumVertices; vertexIndex++) {

                auto vertex = mesh->mVertices[vertexIndex];

                auto x = vertex.x;
                auto y = vertex.y;
                auto z = vertex.z;

                auto u = 0.f;
                auto v = 0.f;

                if (mesh->HasTextureCoords(0) == true) {

                    auto uv = mesh->mTextureCoords[0][vertexIndex];

                    u = uv.x;
                    v = 1 - uv.y;
                }

		auto convertedVertex = make_shared<FSGLVertex>(x, y, z, u, v);

		convertedMesh->verticesObjects.push_back(convertedVertex);

                convertedMesh->vertices.push_back(x);
                convertedMesh->vertices.push_back(y);
                convertedMesh->vertices.push_back(z);

                convertedMesh->vertices.push_back(u);
                convertedMesh->vertices.push_back(v);
                
                // unit matrix
                
                convertedMesh->vertices.push_back(1);
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(0);
                
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(1);
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(0);
                
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(1);
                convertedMesh->vertices.push_back(0);
                
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(0);
                convertedMesh->vertices.push_back(1);

            }
            
            convertedMesh->parentModel = model;
            
            model->meshes.push_back(convertedMesh);

            if (mesh->HasFaces()) {

                for (unsigned int faceIndex = 0; faceIndex < mesh->mNumFaces; faceIndex++) {

                    auto face = mesh->mFaces[faceIndex];

                    if (face.mNumIndices >= 3) {

                        auto faceIndices = face.mIndices;

                        auto a = faceIndices[0];
                        auto b = faceIndices[1];
                        auto c = faceIndices[2];

                        convertedMesh->indices.push_back(a);
                        convertedMesh->indices.push_back(b);
                        convertedMesh->indices.push_back(c);

                    }

                }

            }

            if (mesh->HasBones()) {

                for (unsigned int boneIndex = 0; boneIndex < mesh->mNumBones; boneIndex++) {

                    auto convertedBone = make_shared<FSGLBone>();

                    auto bone = mesh->mBones[boneIndex];

                    auto boneName = bone->mName.C_Str();

			cout << "Bone loaded " << boneName << endl;

                    convertedBone->name = make_shared<string>(boneName);

                    convertedBone->mesh = convertedMesh;
                    
                    for (int boneIndex = 0; boneIndex < bone->mNumWeights; boneIndex++) {

                        auto weight = bone->mWeights[boneIndex];

                        auto convertedWeight = make_shared<FSGLVertexWeight>();

                        convertedWeight->vertex = convertedMesh->vertexWithID(weight.mVertexId);
                        convertedWeight->weight = weight.mWeight;

                        convertedBone->vertexWeights.push_back(convertedWeight);

                    }
                    
                    convertedMesh->bones.push_back(convertedBone);

                }

            }

            convertedMesh->updateGlData();

        }

    }

    if (scene->HasMaterials()) {

        vector<shared_ptr<FSGLMaterial> > rawMaterials;

        for (unsigned int i = 0; i < scene->mNumMaterials; i++) {

            auto material = scene->mMaterials[i];

            auto texturesCount = material->GetTextureCount(aiTextureType_DIFFUSE);

            for (unsigned int textureIndex = 0; textureIndex < texturesCount; textureIndex++) {

                aiString texturePath;

                material->GetTexture(aiTextureType_DIFFUSE, textureIndex, &texturePath);

                cout << "FSGLModelLoaderAssimp loading texture : " << texturePath.data << endl;

                auto convertedTexturePath = make_shared<string>(texturePath.data);

                auto convertedMaterial = make_shared<FSGLMaterial>(convertedTexturePath);

                auto surface = SDL_LoadBMP(convertedMaterial->texturePath->c_str());

                if (surface == nullptr) {

                    cout << "FSGLModelLoaderAssimp: cannot load texture: " << convertedMaterial->texturePath->c_str() << endl;

                }

                auto surfaceLength = surface->w * surface->h * 3;

                // swap bgr -> rgb

                for (auto i = 0; i < surfaceLength; i += 3) {

                    auto pixels = (Uint8 *) surface->pixels;

                    auto blueComponent = pixels[i];
                    auto greenComponent = pixels[i + 1];
                    auto redComponent = pixels[i + 2];

                    pixels[i] = redComponent;
                    pixels[i + 1] = greenComponent;
                    pixels[i + 2] = blueComponent;

                }

                convertedMaterial->surface = surface;

                rawMaterials.push_back(convertedMaterial);
            }

            if (texturesCount < 1) {

                rawMaterials.push_back(shared_ptr<FSGLMaterial>());

            }

        }

        for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; meshIndex++) {

            auto mesh = scene->mMeshes[meshIndex];
            auto convertedMesh = model->meshes[meshIndex];

            auto materialIndex = mesh->mMaterialIndex;

            auto meshMaterial = rawMaterials[materialIndex];

            convertedMesh->material = meshMaterial;

        }

    }

    auto rootNode = scene->mRootNode;

    auto convertedRootNode = FSGLModelLoaderAssimp::convertNode(rootNode, nullptr, model);

    model->rootNode = convertedRootNode;    
    
    if (scene->HasAnimations()) {

        for (unsigned int animationIndex = 0; animationIndex < scene->mNumAnimations; animationIndex++) {

            auto animation = scene->mAnimations[animationIndex];

            auto animationName = animation->mName.C_Str();

		cout << "converted animation name: " << animationName << endl;

            auto convertedAnimation = make_shared<FSGLAnimation>();

            convertedAnimation->name = make_shared<string>(animationName);
            convertedAnimation->duration = animation->mDuration;
            convertedAnimation->ticksPerSecond = animation->mTicksPerSecond;

		cout << "convertedAnimation duration:" << convertedAnimation->duration << endl;

            for (auto nodeAnimationIndex = 0; nodeAnimationIndex < animation->mNumChannels; nodeAnimationIndex++) {

                auto nodeAnimation = animation->mChannels[nodeAnimationIndex];

                auto nodeAnimationName = nodeAnimation->mNodeName.C_Str();

                auto convertedNodeAnimation = make_shared<FSGLNodeAnimation>();

                convertedNodeAnimation->name = make_shared<string>(nodeAnimationName);
                
                convertedNodeAnimation->node = convertedRootNode->findNode(convertedNodeAnimation->name);

                for (auto positionKeyframeIndex = 0; positionKeyframeIndex < nodeAnimation->mNumPositionKeys; positionKeyframeIndex++) {

                    auto positionKeyframe = nodeAnimation->mPositionKeys[positionKeyframeIndex];

                    auto convertedPositionKeyframe = make_shared<FSGLVectorKeyframe>();

                    convertedPositionKeyframe->time = positionKeyframe.mTime;

                    auto vector = positionKeyframe.mValue;

                    float vectorX = vector.x;
                    float vectorY = vector.y;
                    float vectorZ = vector.z;

			cout << "Animation " << positionKeyframeIndex << " Position vector: " << vector.x << "; " << vector.y << "; " << vector.z << endl;

                    auto convertedVector = make_shared<FSGLVector>(vectorX, vectorY, vectorZ);

                    convertedPositionKeyframe->vector = convertedVector;

                    convertedNodeAnimation->positions.push_back(convertedPositionKeyframe);
                }
                
                for (auto rotationKeyframeIndex = 0; rotationKeyframeIndex < nodeAnimation->mNumRotationKeys; rotationKeyframeIndex++) {
                    
                    auto rotationKeyframe = nodeAnimation->mRotationKeys[rotationKeyframeIndex];
                    
                    auto convertedRotationKeyframe = make_shared<FSGLQuaternionKeyframe>();
                    
                    auto quaternion = rotationKeyframe.mValue;
                    
                    auto convertedQuaternion = make_shared<FSGLQuaternion>();
                    
                    convertedQuaternion->x = quaternion.x;
                    convertedQuaternion->y = quaternion.y;
                    convertedQuaternion->z = quaternion.z;
                    convertedQuaternion->w = quaternion.w;
                    
			cout << "Animation " << rotationKeyframeIndex << " Quaternion: " << quaternion.x << "; " << quaternion.y << "; " << quaternion.z << "; " << quaternion.w << ";" << endl;

                    convertedRotationKeyframe->quaternion = convertedQuaternion;
                    
                    convertedNodeAnimation->rotations.push_back(convertedRotationKeyframe);
                }

                for (auto scalingKeyframeIndex = 0; scalingKeyframeIndex < nodeAnimation->mNumScalingKeys; scalingKeyframeIndex++) {
                    
                    auto scalingKeyframe = nodeAnimation->mScalingKeys[scalingKeyframeIndex];
                    
                    auto convertedScalingKeyframe = make_shared<FSGLVectorKeyframe>();
                    
                    auto vector = scalingKeyframe.mValue;

                    float vectorX = vector.x;
                    float vectorY = vector.y;
                    float vectorZ = vector.z;
                    
			cout << "Animation " << scalingKeyframeIndex << " Scaling vector: " << vector.x << "; " << vector.y << "; " << vector.z << endl;

                    auto convertedVector = make_shared<FSGLVector>(vectorX, vectorY, vectorZ);

                    convertedScalingKeyframe->vector = convertedVector;
                    
                    convertedNodeAnimation->scalings.push_back(convertedScalingKeyframe);
                }

                convertedAnimation->nodeAnimations.push_back(convertedNodeAnimation);
                
            }

            model->animations.push_back(convertedAnimation);
        }
    }

    return model;
}

shared_ptr<FSGLNode> FSGLModelLoaderAssimp::convertNode(aiNode* node, shared_ptr<FSGLNode> parentNode, shared_ptr<FSGLModel> model) {

    // model->node<->animation.nodeAnimation.name<->meshes<->vertices
    
    auto convertedNode = make_shared<FSGLNode>();

    auto convertedNodeName = node->mName.C_Str();

    convertedNode->name = make_shared<string>(convertedNodeName);
    
    convertedNode->parent = parentNode;
    
    convertedNode->bone = model->findBone(convertedNode->name);

    for (auto meshIndex = 0; meshIndex < node->mNumMeshes; meshIndex++) {
        
        auto meshSceneIndex = node->mMeshes[meshIndex];
        
        auto mesh = model->meshes[meshSceneIndex];
        
        convertedNode->meshes.push_back(mesh);
        
    }
    
    for (auto childNodeIndex = 0; childNodeIndex < node->mNumChildren; childNodeIndex++) {

        auto childNode = node->mChildren[childNodeIndex];

        auto convertedChildNode = FSGLModelLoaderAssimp::convertNode(childNode, convertedNode, model);

        convertedNode->childs.push_back(convertedChildNode);

    }

    return convertedNode;
}

FSGLModelLoaderAssimp::~FSGLModelLoaderAssimp() {
}

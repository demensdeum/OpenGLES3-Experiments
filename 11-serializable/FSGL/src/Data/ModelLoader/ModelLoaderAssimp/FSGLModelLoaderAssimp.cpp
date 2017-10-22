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
#include <assimp/scene.h>
#include <assimp/postprocess.h>

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
            
            model->meshes.push_back(convertedMesh);

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

                convertedMesh->vertices.push_back(x);
                convertedMesh->vertices.push_back(y);
                convertedMesh->vertices.push_back(z);

                convertedMesh->vertices.push_back(u);
                convertedMesh->vertices.push_back(v);

            }

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
    
    return model;
}

FSGLModelLoaderAssimp::~FSGLModelLoaderAssimp() {
}

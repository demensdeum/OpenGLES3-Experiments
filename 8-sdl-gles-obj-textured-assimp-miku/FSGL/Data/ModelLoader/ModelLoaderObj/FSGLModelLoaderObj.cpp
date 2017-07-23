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

#include "FSGLModelLoaderObj.h"

#include <fstream>
#include <iostream>
#include <regex>

#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//#include "objLoader/tiny_obj_loader.h"

using namespace std;

FSGLModelLoaderObj::FSGLModelLoaderObj() {
}

FSGLModelLoaderObj::FSGLModelLoaderObj(const FSGLModelLoaderObj& orig) {
}

shared_ptr<FSGLModel> FSGLModelLoaderObj::loadModel(shared_ptr<string> modelPath) {

    auto modelPathString = modelPath->c_str();

    auto model = make_shared<FSGLModel>();

    Assimp::Importer importer;
    auto *scene = importer.ReadFile(modelPath->c_str(), aiProcessPreset_TargetRealtime_Fast);

    auto *mesh = scene->mMeshes[0];

    auto uvIndex = 0;

    for (auto i = 0; i < mesh->mNumVertices; i++) {

        auto vertex = mesh->mVertices[i];

        auto x = vertex.x;
        auto y = vertex.y;
        auto z = vertex.z;

        auto uv = mesh->mTextureCoords[0][i];

        auto u = uv.x;
        auto v = 1 - uv.y;

        model->vertices.push_back(x);
        model->vertices.push_back(y);
        model->vertices.push_back(z);
        
        model->vertices.push_back(u);
        model->vertices.push_back(v);

    }

    for (auto i = 0; i < mesh->mNumFaces; i++) {

        const struct aiFace * face = &mesh->mFaces[i];

        if (face->mNumIndices == 3) {

            model->indices.push_back(face->mIndices[0]);
            model->indices.push_back(face->mIndices[1]);
            model->indices.push_back(face->mIndices[2]);

        }

    }

    return model;
}

FSGLModelLoaderObj::~FSGLModelLoaderObj() {
}

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

using namespace std;

FSGLModelLoaderObj::FSGLModelLoaderObj() {
}

FSGLModelLoaderObj::FSGLModelLoaderObj(const FSGLModelLoaderObj& orig) {
}

shared_ptr<FSGLModel> FSGLModelLoaderObj::loadModel(shared_ptr<string> modelPath) {

    auto modelPathString = modelPath->c_str();

    auto model = make_shared<FSGLModel>();

    ifstream modelFile(modelPathString);
    string line;

    auto vertexRegex = regex("(v)\\s([-+]?[0-9]*\\.?[0-9]*)\\s([-+]?[0-9]*\\.?[0-9]*)\\s([-+]?[0-9]*\\.?[0-9]*)");
    auto faceRegex = regex("(f)\\s(\\d+)\\s(\\d+)\\s+(\\d)+");

    smatch smatch;

    while (getline(modelFile, line)) {

        if (regex_search(line, smatch, vertexRegex)) {

            for (auto i = 0; i < smatch.size(); ++i) {
                
                cout << i << ": " << smatch[i] << endl;
                
            }
        }        
        
        if (regex_search(line, smatch, faceRegex)) {

            for (auto i = 0; i < smatch.size(); ++i) {
                
                cout << i << ": " << smatch[i] << endl;
                
            }
        }
    }

    return model;
}

FSGLModelLoaderObj::~FSGLModelLoaderObj() {
}

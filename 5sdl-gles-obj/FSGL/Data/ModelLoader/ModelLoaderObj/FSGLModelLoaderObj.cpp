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

FSGLModelLoaderObj::FSGLModelLoaderObj() {
}

FSGLModelLoaderObj::FSGLModelLoaderObj(const FSGLModelLoaderObj& orig) {
}

shared_ptr<FSGLModel> FSGLModelLoaderObj::loadModel(shared_ptr<string> modelPath) {
    
    auto modelPathString = modelPath->c_str();
    
    auto model = make_shared<FSGLModel>();
    
    ifstream modelFile(modelPathString);
    string line;
    
    while (getline(modelFile, line)) {
        
        cout << line << endl;
        
    }
    
    return model;
}

FSGLModelLoaderObj::~FSGLModelLoaderObj() {
}

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

using namespace std;

FSGLModelLoaderObj::FSGLModelLoaderObj() {
}

FSGLModelLoaderObj::FSGLModelLoaderObj(const FSGLModelLoaderObj& orig) {
}

shared_ptr<FSGLModel> FSGLModelLoaderObj::loadModel(shared_ptr<string> modelPath) {

    auto modelPathString = modelPath->c_str();

    auto model = make_shared<FSGLModel>();
    
    std::ifstream inputFile(modelPathString);
    
    std::string line;
    
    std::smatch smatch;
    
    while (std::getline(inputFile, line)) {
        
        auto vertexRegex = regex("(v)\\s([-+]?[0-9]*\\.?[0-9]*)\\s([-+]?[0-9]*\\.?[0-9]*)\\s([-+]?[0-9]*\\.?[0-9]*)");
        
        if (regex_search(line, smatch, vertexRegex)) {
            
            cout << smatch.size() << endl;
            
            cout << line << endl;
            
            cout << smatch[2] << " " << smatch[3] << " " << smatch[4] << endl;
            
            GLfloat x = std::stof(smatch[2]);
            GLfloat y = std::stof(smatch[3]);
            GLfloat z = std::stof(smatch[4]);
            
            model->vertices.push_back(x);
            model->vertices.push_back(y);
            model->vertices.push_back(z);
            
        }
        
        auto faceRegex = regex("(f)\\s(\\d*)\\s(\\d*)\\s(\\d*)");
        
        if (regex_search(line, smatch, faceRegex)) {
            
            cout << smatch.size() << endl;
            
            cout << smatch[2] << endl;
            cout << smatch[3] << endl;
            cout << smatch[4] << endl;
            
            GLint x = std::stoi(smatch[2]);
            GLint y = std::stoi(smatch[3]);
            GLint z = std::stoi(smatch[4]);
            
            cout << line << endl;        
            
            model->indices.push_back(x);
            model->indices.push_back(y);
            model->indices.push_back(z);
        }
        
    }
    
    return model;
}

FSGLModelLoaderObj::~FSGLModelLoaderObj() {
}

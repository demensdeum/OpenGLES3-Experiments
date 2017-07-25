/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLModel.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 10:39 AM
 */

#include "FSGLModel.h"

#include <fstream>
#include <iostream>

using namespace std;

FSGLModel::FSGLModel() {
    
}

GLushort* FSGLModel::glIndices() {
    
    _glIndices = (GLushort *) malloc(indices.size() * sizeof(GLushort));
    
    for (auto i = 0; i < indices.size(); i++) {
        
        _glIndices[i] = indices[i];
        
    }
    
    return _glIndices;
    
}

GLfloat* FSGLModel::glVertices() {

    _glVertices = (GLfloat *) malloc((vertices.size()) * sizeof(GLfloat));
    
    for (auto i = 0; i < vertices.size(); i += vertexSize) {
        
        _glVertices[i] = vertices[i];
        _glVertices[i + 1] = vertices[i + 1];
        _glVertices[i + 2] = vertices[i + 2];
        _glVertices[i + 3] = vertices[i + 3];
        _glVertices[i + 4] = vertices[i + 4];
    }
    
    return _glVertices;
    
}

void FSGLModel::dumpIntoHeaderFile() {
    
    ofstream dumpFile;
    
    dumpFile.open ("dump.h");
    
    dumpFile <<"#include <GLES3/gl3.h>" << endl << endl;
    
    dumpFile << "GLushort verticesCount = " << vertices.size() << ";" << endl << endl;
    
    dumpFile << "GLushort indicesCount = " << indices.size() << ";" << endl << endl;    
    
    dumpFile << "GLfloat vertices[] = {" << endl << endl;
    
    for (auto i = 0; i < vertices.size(); i += 1) {

        dumpFile << vertices[i] << ", ";
        
        dumpFile << endl;
    }
    
    dumpFile << "};" << endl << endl;
    
    dumpFile << "GLushort indices[] = {" << endl << endl;
    
    for (auto i = 0; i < indices.size(); i += 1) {

        dumpFile << indices[i] << ", ";

        dumpFile << endl;
    }
    
    dumpFile << "};" << endl;    
    
    dumpFile.close();
    
}

FSGLModel::FSGLModel(const FSGLModel& orig) {
}

FSGLModel::~FSGLModel() {
}


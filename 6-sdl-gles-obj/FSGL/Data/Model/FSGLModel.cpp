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

    vertices = make_unique<FSGLVertices>();
    faces = make_unique<FSGLFaces>();
}

void FSGLModel::addVertex(float x, float y, float z) {

    vertices->addVertex(x, y, z);
}

void FSGLModel::addFace(int x, int y, int z) {

    faces->addFace(x, y, z);
}

GLfloat* FSGLModel::glVertices() {

    _glVertices = (GLfloat *) malloc(sizeof(GLfloat) * vertices->count());
    
    for (auto i = 0; i < vertices->count(); i++) {
        
        _glVertices[i] = vertices->coordinateAtIndex(i);
        
    }
    
//    _glVertices = (GLfloat *) malloc(sizeof(GLfloat) * 9);
//    
//    _glVertices[0] = 0.f;
//    _glVertices[1] = 0.5f;
//    _glVertices[2] = 0.f;
//    
//    _glVertices[3] = 0.5f;
//    _glVertices[4] = -0.5f;
//    _glVertices[5] = 0.f;
//            
//    _glVertices[6] = -0.5f;
//    _glVertices[7] = -0.5f;
//    _glVertices[8] = -0.f;

    return _glVertices;
}

FSGLModel::FSGLModel(const FSGLModel& orig) {
}

FSGLModel::~FSGLModel() {
}


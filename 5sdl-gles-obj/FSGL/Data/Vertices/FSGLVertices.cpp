/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVertices.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 12:39 PM
 */

#include "FSGLVertices.h"

FSGLVertices::FSGLVertices() {
}

FSGLVertices::FSGLVertices(const FSGLVertices& orig) {
}

void FSGLVertices::addVertex(float x, float y, float z) {
    
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
    
}

FSGLVertices::~FSGLVertices() {
}


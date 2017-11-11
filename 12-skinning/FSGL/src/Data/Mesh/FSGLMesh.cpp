/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLMesh.cpp
 * Author: demensdeum
 * 
 * Created on August 1, 2017, 11:02 PM
 */

#include <glm/detail/type_vec.hpp>

#include "FSGLMesh.h"

#include "../Object/FSGLObject.h"

#include <iostream>

FSGLMesh::FSGLMesh() {
}

FSGLMesh::FSGLMesh(const FSGLMesh& orig) {
}

shared_ptr<FSGLVector> FSGLMesh::currentAnimationPositionVector() {
    
    auto vector = parentModel->currentAnimationPositionVectorForMesh(shared_from_this());
    
    return vector;
}

void FSGLMesh::updateGlAnimationTransformation() {
    
    auto positionVector = currentAnimationPositionVector();
        
    if (positionVector.get() == nullptr) {
            
        return;
            
    }
    
    for (unsigned int i = 0; i < vertices.size(); i += glVertexCount) {
        
        // mat4 - translation
        
        glVertices[i + 5] = 1;
        glVertices[i + 6] = 0;
        glVertices[i + 7] = 0;
        glVertices[i + 8] = positionVector->x;
        
        glVertices[i + 9] = 0;
        glVertices[i + 10] = 1;
        glVertices[i + 11] = 0;
        glVertices[i + 12] = positionVector->y;
        
        glVertices[i + 13] = 0;
        glVertices[i + 14] = 0;
        glVertices[i + 15] = 1;
        glVertices[i + 16] = positionVector->z;
        
        glVertices[i + 17] = 0;
        glVertices[i + 18] = 0;
        glVertices[i + 19] = 0;
        glVertices[i + 20] = 1;
        
        
    }
}

void FSGLMesh::updateGlData() {

    glVertices = new GLfloat[vertices.size() * glVertexCount];

    for (unsigned int i = 0; i < vertices.size(); i += glVertexCount) {

        glVertices[i] = vertices[i];         // x
        glVertices[i + 1] = vertices[i + 1]; // y
        glVertices[i + 2] = vertices[i + 2]; // z
        
        glVertices[i + 3] = vertices[i + 3]; // u
        glVertices[i + 4] = vertices[i + 4]; // v
        
        // mat4
        
        glVertices[i + 5] = 1;
        glVertices[i + 6] = 0;
        glVertices[i + 7] = 0;
        glVertices[i + 8] = 0;
        
        glVertices[i + 9] = 0;
        glVertices[i + 10] = 1;
        glVertices[i + 11] = 0;
        glVertices[i + 12] = 0;
        
        glVertices[i + 13] = 0;
        glVertices[i + 14] = 0;
        glVertices[i + 15] = 1;
        glVertices[i + 16] = 0;
        
        glVertices[i + 17] = 0;
        glVertices[i + 18] = 0;
        glVertices[i + 19] = 0;
        glVertices[i + 20] = 1;
    }

    glIndices = new GLushort[indices.size() * sizeof (GLushort)];

    for (unsigned int i = 0; i < indices.size(); i++) {

        glIndices[i] = indices[i];

    }

    glVerticesBufferSize = vertices.size() * sizeof (GLfloat);
    glIndicesBufferSize = indices.size() * sizeof (GLushort);
    glIndicesCount = indices.size();
    
}

FSGLMesh::~FSGLMesh() {

    if (glIndices != NULL) {

        delete glIndices;

    }

    if (glVertices != NULL) {

        delete glVertices;

    }

}


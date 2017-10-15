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

#include "FSGLMesh.h"

FSGLMesh::FSGLMesh() {
}

FSGLMesh::FSGLMesh(const FSGLMesh& orig) {
}

void FSGLMesh::updateGlData() {

    glVertices = new GLfloat[vertices.size() * sizeof (GLfloat)];

    for (unsigned int i = 0; i < vertices.size(); i += glVertexCount) {

        glVertices[i] = vertices[i];
        glVertices[i + 1] = vertices[i + 1];
        glVertices[i + 2] = vertices[i + 2];
        glVertices[i + 3] = vertices[i + 3];
        glVertices[i + 4] = vertices[i + 4];
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


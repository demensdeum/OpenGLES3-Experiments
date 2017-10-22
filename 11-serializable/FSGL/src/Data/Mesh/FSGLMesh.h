/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLMesh.h
 * Author: demensdeum
 *
 * Created on August 1, 2017, 11:02 PM
 */

#ifndef FSGLMESH_H
#define FSGLMESH_H

#include <vector>

#if MSVC

#include <GL/glew.h>

#else

#include <GLES3/gl3.h>

#endif

#include "../Material/FSGLMaterial.h"

using namespace std;

class FSGLMesh {
public:
    FSGLMesh();
    FSGLMesh(const FSGLMesh& orig);
    virtual ~FSGLMesh();
    
    vector<GLfloat> vertices;
    vector<GLushort> indices;
    
    GLushort* glIndices = NULL;
    GLfloat* glVertices = NULL;

    GLsizeiptr glVerticesBufferSize = 0;
    GLsizeiptr glIndicesBufferSize = 0;
    GLsizei glIndicesCount = 0;

    static const int glVertexCount = 5;
    static const GLsizei glVertexSize = sizeof(GLfloat) * glVertexCount;
    
    void updateGlData();
    
    shared_ptr<FSGLMaterial> material;
    
    
private:

};

#endif /* FSGLMESH_H */


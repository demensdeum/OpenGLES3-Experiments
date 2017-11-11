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
#include "../Bone/FSGLBone.h"
#include <glm/glm.hpp>
#include "../Vector/FSGLVector.h"
#include "../Quaternion/FSGLQuaternion.h"

class FSGLModel;

using namespace std;

class FSGLMesh: public std::enable_shared_from_this<FSGLMesh> {
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

    // x, y, z, u, v, mat4
    
    static const int glVertexCount = 5 + 16;
    static const GLsizei glVertexSize = sizeof(GLfloat) * glVertexCount;
    
    void updateGlData();
    void updateGlAnimationTransformation();
    
    shared_ptr<FSGLMaterial> material;
    
    vector< shared_ptr <FSGLBone> > bones;
    
    shared_ptr<FSGLModel> parentModel;
    
private:

    shared_ptr<FSGLVector> currentAnimationPositionVector();
    shared_ptr<FSGLQuaternion> currentAnimationRotationQuaternion();
    
};

#endif /* FSGLMESH_H */


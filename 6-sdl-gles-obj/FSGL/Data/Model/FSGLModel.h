/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLModel.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 10:39 AM
 */

#ifndef FSEOGLMODEL_H
#define FSEOGLMODEL_H

#include <memory>

#include "../Resource/FSGLResource.h"

#include <GLES3/gl3.h>

#include <vector>

using namespace std;

class FSGLModel: public FSGLResource {
    
public:
    FSGLModel();
    FSGLModel(const FSGLModel& orig);
    virtual ~FSGLModel();
    
    GLfloat* glVertices();
    GLushort* glIndices();
    
    vector<GLfloat> vertices;
    vector<GLushort> indices;
    
    GLushort *_glIndices;
    GLfloat *_glVertices;
};

#endif /* FSEOGLMODEL_H */


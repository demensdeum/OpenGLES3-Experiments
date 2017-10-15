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
#include "../Material/FSGLMaterial.h"
#include "../Mesh/FSGLMesh.h"

#if MSVC

#include <GL/glew.h>

#else

#include <GLES3/gl3.h>

#endif

#include <vector>

using namespace std;

class FSGLModel: public FSGLResource {
    
public:
    FSGLModel();
    FSGLModel(const FSGLModel& orig);
    virtual ~FSGLModel();
  
    vector< shared_ptr<FSGLMesh> > meshes;  

private:
    
    
    
};

#endif /* FSEOGLMODEL_H */


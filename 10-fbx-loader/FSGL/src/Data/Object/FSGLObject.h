/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLObject.h
 * Author: demensdeum
 *
 * Created on July 29, 2017, 11:45 AM
 */

#ifndef FSGLOBJECT_H
#define FSGLOBJECT_H

#include "../Model/FSGLModel.h"
#include "../Vector/FSGLVector.h"

#include <glm/glm.hpp>

#include <memory>

using namespace std;

class FSGLObject {
public:
    FSGLObject(shared_ptr<FSGLModel> model);
    FSGLObject() : FSGLObject(shared_ptr<FSGLModel>()) {};
    FSGLObject(const FSGLObject& orig);
    virtual ~FSGLObject();
    
    int id;
    
    shared_ptr<FSGLModel> model;    
    
    shared_ptr<FSGLVector> scaleVector;
    shared_ptr<FSGLVector> rotationVector;
    shared_ptr<FSGLVector> positionVector;   
  
    virtual glm::mat4 matrix();
};

#endif /* FSGLOBJECT_H */


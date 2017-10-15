/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLCamera.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 10:46 AM
 */

#ifndef FSGLCAMERA_H
#define FSGLCAMERA_H

#include "../../Data/Object/FSGLObject.h"

class FSGLCamera: public FSGLObject {
public:
    FSGLCamera();
    FSGLCamera(const FSGLCamera& orig);
    virtual ~FSGLCamera();
    
    virtual glm::mat4 matrix();
    
private:

};

#endif /* FSGLCAMERA_H */


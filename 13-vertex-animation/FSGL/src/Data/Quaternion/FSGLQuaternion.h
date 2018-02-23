/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLQuaternion.h
 * Author: demensdeum
 *
 * Created on November 5, 2017, 2:33 PM
 */

#ifndef FSGLQUATERNION_H
#define FSGLQUATERNION_H

#include "../Serializable/FSGLSerializable.h"

class FSGLQuaternion: FSGLSerializable {
public:
    FSGLQuaternion();
    FSGLQuaternion(const FSGLQuaternion& orig);
    virtual ~FSGLQuaternion();
    
    float w;
    float x;
    float y;
    float z;
    
private:

};

#endif /* FSGLQUATERNION_H */


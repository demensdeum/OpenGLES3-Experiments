/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVector.h
 * Author: demensdeum
 *
 * Created on July 29, 2017, 11:47 AM
 */

#ifndef FSGLVECTOR_H
#define FSGLVECTOR_H

#include "../Serializable/FSGLSerializable.h"

class FSGLVector: public FSGLSerializable {
public:
    FSGLVector();
    FSGLVector(float x, float y, float z);
    FSGLVector(const FSGLVector& orig);
    virtual ~FSGLVector();
    
    shared_ptr<FSGLVector> copy();
    
    float x;
    float y;
    float z;
        
    virtual shared_ptr<string> serializeIntoString();
    virtual shared_ptr<FSGLSerializable> deserializeFromString(shared_ptr<string> serializedData);     
    
private:

};

#endif /* FSGLVECTOR_H */


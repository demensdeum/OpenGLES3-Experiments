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

class FSGLVector {
public:
    FSGLVector(float x, float y, float z);
    FSGLVector(const FSGLVector& orig);
    virtual ~FSGLVector();
    
    float x;
    float y;
    float z;
        
private:

};

#endif /* FSGLVECTOR_H */


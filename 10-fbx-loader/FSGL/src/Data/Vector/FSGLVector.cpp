/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVector.cpp
 * Author: demensdeum
 * 
 * Created on July 29, 2017, 11:47 AM
 */

#include "FSGLVector.h"

FSGLVector::FSGLVector(float x, float y, float z) {
    
    this->x = x;
    this->y = y;
    this->z = z;
    
}

FSGLVector::FSGLVector(const FSGLVector& orig) {
}

FSGLVector::~FSGLVector() {
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLMatrix.cpp
 * Author: demensdeum
 * 
 * Created on November 12, 2017, 12:51 PM
 */

#include "FSGLMatrix.h"

FSGLMatrix::FSGLMatrix() {
    
    matrix = glm::mat4(1.0);
    
}

FSGLMatrix::FSGLMatrix(const FSGLMatrix& orig) {
}

FSGLMatrix::~FSGLMatrix() {
}


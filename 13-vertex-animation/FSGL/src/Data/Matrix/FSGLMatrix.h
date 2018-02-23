/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLMatrix.h
 * Author: demensdeum
 *
 * Created on November 12, 2017, 12:51 PM
 */

#ifndef FSGLMATRIX_H
#define FSGLMATRIX_H

#include <glm/glm.hpp>

class FSGLMatrix {
public:
    FSGLMatrix();
    FSGLMatrix(const FSGLMatrix& orig);
    virtual ~FSGLMatrix();
    
    glm::mat4 matrix;
    
private:

};

#endif /* FSGLMATRIX_H */


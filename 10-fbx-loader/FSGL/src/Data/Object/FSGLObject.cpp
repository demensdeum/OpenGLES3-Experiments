/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLObject.cpp
 * Author: demensdeum
 * 
 * Created on July 29, 2017, 11:45 AM
 */

#include "FSGLObject.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

using namespace std;

FSGLObject::FSGLObject(shared_ptr<FSGLModel> model) {
    
    scaleVector = make_shared<FSGLVector>(1.f, 1.f, 1.f);
    rotationVector = make_shared<FSGLVector>(0.f, 0.f, 0.f);
    positionVector = make_shared<FSGLVector>(0.f, 0.f, 0.f);     
    
    this->model = model;

}

FSGLObject::FSGLObject(const FSGLObject& orig) {
}

glm::mat4 FSGLObject::matrix() {
    
    glm::mat4 matrix;
    
    matrix = glm::scale(matrix, glm::vec3(scaleVector->x, scaleVector->y, scaleVector->z));

    matrix = glm::translate(matrix, glm::vec3(positionVector->x, positionVector->y, positionVector->z));

    matrix = glm::rotate(matrix, rotationVector->x, glm::vec3(1.f, 0.f, 0.f));
    matrix = glm::rotate(matrix, rotationVector->y, glm::vec3(0.f, 1.f, 0.f));
    matrix = glm::rotate(matrix, rotationVector->z, glm::vec3(0.f, 0.f, 1.f));    
    
    return matrix;
}

FSGLObject::~FSGLObject() {
    
    cout << "FSGLObject destructed" << endl;
    
}


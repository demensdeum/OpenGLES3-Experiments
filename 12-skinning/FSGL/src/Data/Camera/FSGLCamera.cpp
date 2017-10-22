/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLCamera.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 10:46 AM
 */

#include <glm/gtc/quaternion.hpp>

#include "FSGLCamera.h"

FSGLCamera::FSGLCamera() {
}

FSGLCamera::FSGLCamera(const FSGLCamera& orig) {
}

glm::mat4 FSGLCamera::matrix() {
    
    auto matrix = FSGLObject::matrix();
    
    return glm::inverse(matrix);
}

FSGLCamera::~FSGLCamera() {
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLAnimation.cpp
 * Author: demensdeum
 * 
 * Created on October 22, 2017, 8:14 PM
 */

#include "FSGLAnimation.h"

FSGLAnimation::FSGLAnimation() {
}

FSGLAnimation::FSGLAnimation(const FSGLAnimation& orig) {
}

void FSGLAnimation::increment() {
    
    currentOffset += 1;
    
    if (currentOffset > duration) {
        
        currentOffset = 0;
        
    }
}

shared_ptr<FSGLVector> FSGLAnimation::positionVector() {
    
    auto nodeAnimation = nodeAnimations[0]; // ?
    
    auto positionVectorKeyframe = nodeAnimation->positions[currentOffset];
    
    return positionVectorKeyframe->vector;
}

FSGLAnimation::~FSGLAnimation() {
}


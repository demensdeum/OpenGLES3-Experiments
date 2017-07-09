/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLFaces.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 12:39 PM
 */

#include "FSGLFaces.h"

FSGLFaces::FSGLFaces() {
}

FSGLFaces::FSGLFaces(const FSGLFaces& orig) {
}

void FSGLFaces::addFace(int x, int y, int z) {
    
    faces.push_back(x);
    faces.push_back(y);
    faces.push_back(z);
    
}

FSGLFaces::~FSGLFaces() {
}


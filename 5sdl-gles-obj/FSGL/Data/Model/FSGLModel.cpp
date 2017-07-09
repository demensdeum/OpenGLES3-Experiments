/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLModel.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 10:39 AM
 */

#include "FSGLModel.h"

#include <fstream>
#include <iostream>

using namespace std;

FSGLModel::FSGLModel() {

}

void FSGLModel::addVertex(float x, float y, float z) {
    
    vertices->addVertex(x, y, z);
}

void FSGLModel::addFace(int x, int y, int z) {
    
    faces->addFace(x, y, z);
}

FSGLModel::FSGLModel(const FSGLModel& orig) {
}

FSGLModel::~FSGLModel() {
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLMaterial.cpp
 * Author: demensdeum
 * 
 * Created on July 31, 2017, 10:36 PM
 */

#include "FSGLMaterial.h"

FSGLMaterial::FSGLMaterial(shared_ptr<string> texturePath) {
    
    this->texturePath = texturePath;
    
    surface = NULL;
}

FSGLMaterial::FSGLMaterial(const FSGLMaterial& orig) {
}

FSGLMaterial::~FSGLMaterial() {
    
    if (surface != NULL) {
    
        SDL_FreeSurface(surface);
    
    }
    
}


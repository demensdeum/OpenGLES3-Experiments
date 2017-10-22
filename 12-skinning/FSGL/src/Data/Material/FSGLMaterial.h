/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLMaterial.h
 * Author: demensdeum
 *
 * Created on July 31, 2017, 10:36 PM
 */

#ifndef FSGLMATERIAL_H
#define FSGLMATERIAL_H

#include <memory>
#include <string>

#include <SDL2/SDL.h>

using namespace std;

class FSGLMaterial {
public:
    FSGLMaterial(shared_ptr<string> texturePath);
    FSGLMaterial(const FSGLMaterial& orig);
    virtual ~FSGLMaterial();
    
    shared_ptr<string> texturePath;
    
    SDL_Surface *surface;
    
private:

};

#endif /* FSGLMATERIAL_H */


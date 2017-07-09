/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLCore.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 10:10 AM
 */

#ifndef FSEOGLCORE_H
#define FSEOGLCORE_H

#include <SDL2/SDL.h>

#include <memory>

#include "../Data/Model/FSGLModel.h"

using namespace std;

class FSGLCore {
public:
    FSGLCore();
    FSGLCore(const FSGLCore& orig);
    virtual ~FSGLCore();
    
    void run();
    
    void addModel(shared_ptr<FSGLModel> model);
    
    void render();
    
    void stop();
    
private:

    SDL_GLContext context;
    SDL_Window *window;
    
    void loadBasicShaderProgram();
};

#endif /* FSEOGLCORE_H */


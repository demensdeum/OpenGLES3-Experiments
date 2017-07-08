/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLCore.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 10:10 AM
 */

#include "FSGLCore.h"

#include <GLES3/gl3.h>

FSGLCore::FSGLCore() {
}

void FSGLCore::run() {

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
            "SDL2 - OGLES",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_OPENGL
            );


    context = SDL_GL_CreateContext(window);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();

    SDL_GL_SwapWindow(window);
}

void FSGLCore::stop() {

    SDL_GL_DeleteContext(context);

    SDL_Quit();
}

FSGLCore::FSGLCore(const FSGLCore& orig) {
}

FSGLCore::~FSGLCore() {
}


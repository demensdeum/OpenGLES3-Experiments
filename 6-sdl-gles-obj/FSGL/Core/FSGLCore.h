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

#include <GLES3/gl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
    
    GLint common_get_shader_program(const char *vertex_shader_source, const char *fragment_shader_source);

    SDL_GLContext context;
    SDL_Window *window;
    
    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    glm::mat4 modelMatrix;
};

#endif /* FSEOGLCORE_H */


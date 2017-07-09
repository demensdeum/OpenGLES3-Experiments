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

#include "../Data/Model/FSGLModel.h"

static const GLfloat vertices[] = {
    0.0f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
};

static const GLchar* vertex_shader_source =
        "#version 100\n"
        "attribute vec3 position;\n"
        "void main() {\n"
        "   gl_Position = vec4(position, 1.0);\n"
        "}\n";

static const GLchar* fragment_shader_source =
        "#version 100\n"
        "void main() {\n"
        "   gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";  

GLint common_get_shader_program(const char *vertex_shader_source, const char *fragment_shader_source) {

    enum Consts {
        INFOLOG_LEN = 512
    };
    
    GLchar infoLog[INFOLOG_LEN];
    GLint fragment_shader;
    GLint shader_program;
    GLint success;
    GLint vertex_shader;

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, INFOLOG_LEN, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
    }

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, INFOLOG_LEN, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
    }

    shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program, INFOLOG_LEN, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", infoLog);
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    return shader_program;
}


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

    

}

void FSGLCore::render() {
    
    
    SDL_GL_SwapWindow(window);
}

void FSGLCore::addModel(shared_ptr<FSGLModel> model) {

    GLuint vbo;
    GLint pos;
    
    auto shader_program = common_get_shader_program(vertex_shader_source, fragment_shader_source);
    pos = glGetAttribLocation(shader_program, "position");
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, 640, 480);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof (vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);
    glEnableVertexAttribArray(pos);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader_program);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDeleteBuffers(1, &vbo);

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


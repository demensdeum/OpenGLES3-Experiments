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

#include "../Data/Model/FSGLModel.h"

#include <glm/gtc/type_ptr.hpp>

//#include "newell_teapot.h"

#include <chrono>
#include <thread>

#include <iostream>

using namespace std;

static const GLchar* vertexShaderSource =
        "#version 100\n"
        "uniform mat4 projectionMatrix;\n"
        "uniform mat4 viewMatrix;\n"
        "uniform mat4 modelMatrix;\n"
        "attribute vec4 position;\n"
        "void main() {\n"
        "   gl_Position = projectionMatrix * modelMatrix * viewMatrix * position;\n"
        "}\n";

static const GLchar* fragmentShaderSource =
        "#version 100\n"
        "void main() {\n"
        "   gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";

GLint FSGLCore::common_get_shader_program(const char *vertex_shader_source, const char *fragment_shader_source) {

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

    shader_program = common_get_shader_program(vertexShaderSource, fragmentShaderSource);
    pos = glGetAttribLocation(shader_program, "position");

    GLfloat *vertices = model->glVertices();
    GLushort *indices = model->glIndices();
    
    cout << "--- Vertices ---" << endl;
    
    cout << model->vertices.size() << endl;
    
    for (auto i = 0; i < model->vertices.size(); i+=3 ) {
        
        cout << model->vertices[i] << " " << model->vertices[i + 1] << " " << model->vertices[i + 2] << endl;
        
    }
    
    cout << "--- Indices ---" << endl;
    
    cout << model->indices.size() << endl;
    
    for (auto i = 0; i < model->indices.size(); i+= 3) {
        
        cout << model->indices[i] << " " << model->indices[i + 1] << " " << model->indices[i + 2] << endl;
        
    }
    
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, 640, 480);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * model->vertices.size(), vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLint) * model->indices.size(), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(pos);

    glUseProgram(shader_program);

    GLint projectionMatrixUniform;
    GLint modelMatrixUniform;
    GLint viewMatrixUniform;

    glm::mat4 projectionMatrix;
    glm::mat4 modelMatrix;
    glm::mat4 viewMatrix;

    projectionMatrix = glm::perspective(90.0f, float(640.0 / 480.0), 0.0f, 100.0f);
    projectionMatrixUniform = glGetUniformLocation(shader_program, "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixUniform, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    modelMatrix = glm::mat4(1.0);
    modelMatrixUniform = glGetUniformLocation(shader_program, "modelMatrix");
    glUniformMatrix4fv(modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    viewMatrix = glm::mat4(1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.f, 0.f, -1.f));
    viewMatrixUniform = glGetUniformLocation(shader_program, "viewMatrix");
    glUniformMatrix4fv(viewMatrixUniform, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawElements(GL_TRIANGLES, model->indices.size(), GL_UNSIGNED_SHORT, 0);

    SDL_GL_SwapWindow(window);

    this_thread::sleep_for(chrono::milliseconds(50));
    
}

void FSGLCore::stop() {

    SDL_GL_DeleteContext(context);

    SDL_Quit();
    
}

FSGLCore::FSGLCore(const FSGLCore& orig) {
}

FSGLCore::~FSGLCore() {
}


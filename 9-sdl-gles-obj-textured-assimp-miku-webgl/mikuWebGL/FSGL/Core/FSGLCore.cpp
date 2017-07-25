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

#include <chrono>
#include <thread>

#include "../../dump.h"
#include "../../textureDump.h"

#include <iostream>

#include <emscripten.h>

using namespace std;

static GLint viewMatrixUniform;

static glm::mat4 viewMatrix;

static bool setViewMatrixOnce = false;

static void drawLoop() {

	if (setViewMatrixOnce == false) {
	
		viewMatrix = glm::translate(viewMatrix, glm::vec3(0.f, -0.3f, -1.0f));	
	
		setViewMatrixOnce = true;
	}

        viewMatrix = glm::rotate(
                viewMatrix,
                0.02f,
                glm::vec3(0.f, 1.f, 0.f)
                );

        glUniformMatrix4fv(viewMatrixUniform, 1, GL_FALSE, glm::value_ptr(viewMatrix));

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearDepthf(1.0f);
        
        glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_SHORT, 0);

    SDL_GL_SwapBuffers();

}

static const GLchar* vertexShaderSource =
        "#version 100\n"
        "uniform mat4 projectionMatrix;\n"
        "uniform mat4 viewMatrix;\n"
        "uniform mat4 modelMatrix;\n"
        "attribute vec4 position;\n"
        "attribute vec2 uvIn;\n"
        "varying vec2 uvOut;\n"
        "void main() {\n"
        "   gl_Position = projectionMatrix * modelMatrix * viewMatrix * position;\n"
        "   uvOut = uvIn;\n"
        "}\n";

static const GLchar* fragmentShaderSource =
        "#version 100\n"
        "precision highp float;\n"
        "varying lowp vec2 uvOut;\n"
        "uniform sampler2D texture;\n"
        "void main() {\n"
        "   gl_FragColor = texture2D(texture, uvOut);\n"
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

    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 0, SDL_OPENGL);
}

void FSGLCore::render() {

    SDL_GL_SwapWindow(window);
}

void FSGLCore::addModel(shared_ptr<FSGLModel> model) {

    shader_program = common_get_shader_program(vertexShaderSource, fragmentShaderSource);
    pos = glGetAttribLocation(shader_program, "position");

    //GLfloat *vertices = model->glVertices();
    //GLushort *indices = model->glIndices();

//    cout << "--- Vertices ---" << endl;
//
//    cout << model->vertices.size() << endl;
//
//    for (auto i = 0; i < model->vertices.size(); i += model->vertexSize) {
//
//        cout << model->vertices[i] << " ";
//        cout << model->vertices[i + 2] << " ";
//        cout << model->vertices[i + 1] << " ";
//        cout << model->vertices[i + 3] << " ";
//        cout << model->vertices[i + 4] << " ";
//        cout << endl;
//
//    }

//    cout << "--- Indices ---" << endl;
//
//    cout << model->indices.size() << endl;
//
//    for (auto i = 0; i < model->indices.size(); i += 3) {
//
//        cout << model->indices[i] << " " << model->indices[i + 1] << " " << model->indices[i + 2] << endl;
//
//    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, 640, 480);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //glBufferData(GL_ARRAY_BUFFER, sizeof (GLfloat) * model->vertices.size(), vertices, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, sizeof (GLfloat) * verticesCount, vertices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (GLint) * model->indices.size(), indices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (GLushort) * indicesCount, indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, sizeof (GLfloat) * model->vertexSize, 0);
    glEnableVertexAttribArray(pos);

    glUseProgram(shader_program);

    GLint uvSlot = glGetAttribLocation(shader_program, "uvIn");
    glVertexAttribPointer(uvSlot, 2, GL_FLOAT, GL_FALSE, sizeof (GLfloat) * model->vertexSize, (GLvoid*) (sizeof (GLfloat) * 3));
    glEnableVertexAttribArray(uvSlot);

    auto palleteMode = GL_RGB;

    GLuint textureBinding;
    glGenTextures(1, &textureBinding);
    glBindTexture(GL_TEXTURE_2D, textureBinding);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, palleteMode, surfaceWidth, surfaceHeight, 0, palleteMode, GL_UNSIGNED_BYTE, pixels);
    glActiveTexture(GL_TEXTURE0);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    GLint textureSlot = glGetUniformLocation(shader_program, "texture");
    glUniform1i(textureSlot, 0);

    GLint projectionMatrixUniform;
    GLint modelMatrixUniform;
    

    glm::mat4 projectionMatrix;
    glm::mat4 modelMatrix;
    

    projectionMatrix = glm::perspective(90.0f, float(640.0 / 480.0), 0.001f, 200.0f);
    projectionMatrixUniform = glGetUniformLocation(shader_program, "projectionMatrix");
    glUniformMatrix4fv(projectionMatrixUniform, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

    modelMatrix = glm::mat4(1.0);
    modelMatrixUniform = glGetUniformLocation(shader_program, "modelMatrix");
    glUniformMatrix4fv(modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    viewMatrix = glm::mat4(1.0);

    viewMatrix = glm::translate(viewMatrix, glm::vec3(0.f, -0.3f, -3.0f));
    viewMatrixUniform = glGetUniformLocation(shader_program, "viewMatrix");

    emscripten_set_main_loop(drawLoop, 60, 1);
}

void FSGLCore::stop() {

    SDL_GL_DeleteContext(context);

    SDL_Quit();

}

FSGLCore::FSGLCore(const FSGLCore& orig) {
}

FSGLCore::~FSGLCore() {
}


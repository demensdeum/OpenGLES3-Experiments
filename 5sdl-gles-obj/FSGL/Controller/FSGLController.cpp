/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLController.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 10:37 AM
 */

#include "FSGLController.h"

#include "../Data/ResourcesLoader/FSGLResourceLoader.h"

FSGLController::FSGLController() {
}

FSGLController::FSGLController(const FSGLController& orig) {
}

void FSGLController::run() {
    
    core = make_unique<FSGLCore>();
    core->run();
}

void FSGLController::addModel(shared_ptr<FSGLModel> model) {
    
    core->addModel(model);
    
}

void FSGLController::setCamera(shared_ptr<FSGLCamera> camera) {
    
}

void FSGLController::render() {

    core->render();
    
}

void FSGLController::stop() {
    
    core->stop();
    
}

FSGLController::~FSGLController() {
}


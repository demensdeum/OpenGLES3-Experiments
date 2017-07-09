/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLController.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 10:37 AM
 */

#ifndef FSEOGLCONTROLLER_H
#define FSEOGLCONTROLLER_H

//#include <FSEGL/Data/FSGLModel.h>
#include "../Data/Model/FSGLModel.h"
#include "../Data/Camera/FSGLCamera.h"

#include "../Core/FSGLCore.h"

#include <memory>

using namespace std;

class FSGLController {
    
public:
    FSGLController();
    FSGLController(const FSGLController& orig);
    virtual ~FSGLController();
    
    void run();
    
    void addModel(shared_ptr<FSGLModel> model);
    void removeModel(shared_ptr<FSGLModel> model);
    
    void setCamera(shared_ptr<FSGLCamera> camera);
    
    void render();
    
    void stop();
    
private:

    unique_ptr<FSGLCore> core;
};

#endif /* FSEOGLCONTROLLER_H */


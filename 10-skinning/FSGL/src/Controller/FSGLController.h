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

#include "../Data/Model/FSGLModel.h"
#include "../Data/Camera/FSGLCamera.h"

#include "../Core/FSGLCore.h"

#include <memory>

#include "../Data/Camera/FSGLCamera.h"

using namespace std;

class FSGLController {
    
public:
    FSGLController();
    FSGLController(const FSGLController& orig);
    virtual ~FSGLController();
    
    void initialize();
    
    void addObject(shared_ptr<FSGLObject> object);

    shared_ptr<FSGLObject> getObjectWithID(int id);
    
    void removeAllObjects();
    
    void removeObject(shared_ptr<FSGLObject> object);
    
    void render();
    
    void addRenderID(int id);
    void cleanRenderIDs();    
    
    void stop();
    
    void setCameraX(float x);
    void setCameraY(float y);
    void setCameraZ(float z);
    
    void setCameraRotationX(float x);
    void setCameraRotationY(float y);
    void setCameraRotationZ(float z);    
    
private:

    unique_ptr<FSGLCore> core;
};

#endif /* FSEOGLCONTROLLER_H */


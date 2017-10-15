/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: demensdeum
 *
 * Created on October 15, 2017, 12:07 PM
 */

#include <cstdlib>
#include <memory>
#include <chrono>
#include <thread>

#include "../FSGL/src/Controller/FSGLController.h"
#include "../FSGL/src/Data/ResourcesLoader/FSGLResourceLoader.h"

using namespace std;

int main(int argc, char** argv) {

    auto controller = make_shared<FSGLController>();
    controller->initialize();
    
    //auto model = static_pointer_cast<FSGLModel>(FSGLResourceLoader::loadResource(std::make_shared<string>("data/models/durotan/Durotan.obj")));
    auto model = static_pointer_cast<FSGLModel>(FSGLResourceLoader::loadResource(std::make_shared<string>("data/models/skinnedCube/skinnedCube.obj")));
    
    auto object = std::make_shared<FSGLObject>(model);
    
    controller->addObject(object);
    
    object->positionVector->x = 0.f;
    object->positionVector->y = 0.f;
    object->positionVector->z = 0.f;    
    
    controller->setCameraY(0.f);
    controller->setCameraZ(5.f);    
    
    controller->render();
    
    this_thread::sleep_for(2s);
    
    return 0;
}


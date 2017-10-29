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
#include <iostream>

#include "../FSGL/src/Controller/FSGLController.h"

using namespace std;

int main(int argc, char** argv) {

    cout << "Skinning animation... work in progress" << endl;
    
    auto controller = make_shared<FSGLController>();
    controller->initialize();
    
    auto path = std::make_shared<string>("cube.fso");
    auto rawObject = FSGLObject().deserializeFromFile(path);
    auto object = static_pointer_cast<FSGLObject>(rawObject);

    controller->addObject(object);
    
    controller->render();  
    
    this_thread::sleep_for(2s);
    
    return 0;
}


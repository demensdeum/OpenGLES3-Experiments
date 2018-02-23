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

    cout << "Vertex animation - plain and simple" << endl;

    auto controller = make_shared<FSGLController>();
    controller->initialize();

	for (auto i = 0; i <2; i++)
{
	string pathh = "frame";
	pathh += std::to_string(i);
	pathh +=".fso";

	cout << pathh << endl;

    auto path = std::make_shared<string>(pathh);
    auto rawObject = FSGLObject().deserializeFromFile(path);
    auto object = static_pointer_cast<FSGLObject>(rawObject);

    controller->addObject(object);
    controller->render();
	controller->removeObject(object);

	this_thread::sleep_for(3s);
}

    return 0;
}


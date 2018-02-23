/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLSerializable.cpp
 * Author: demensdeum
 * 
 * Created on October 21, 2017, 1:13 PM
 */

#include "FSGLSerializable.h"

#include <iostream>
#include <fstream>
#include <sstream>

void FSGLSerializable::serializeIntoFile(shared_ptr<string> path) {
    
    auto filePath = path->c_str();
    
    ofstream outputFile;
    outputFile.open(filePath);
    
    outputFile << serializeIntoString() -> c_str();
    
    outputFile.close();    
}

shared_ptr<FSGLSerializable> FSGLSerializable::deserializeFromFile(shared_ptr<string> path) {
    
    auto filePath = path->c_str();
    
    ifstream file;
    file.open(filePath);
    
    std::stringstream content;
    content << file.rdbuf(); 
    
    auto stringContainer = make_shared<string>(content.str()); 
    
    auto object = this->deserializeFromString(stringContainer);
    
    return object;
}
    
shared_ptr<string> FSGLSerializable::serializeIntoString() {
    
}

shared_ptr<FSGLSerializable> FSGLSerializable::deserializeFromString(shared_ptr<string> serializedData) {
    
    return shared_ptr<FSGLSerializable>();
}

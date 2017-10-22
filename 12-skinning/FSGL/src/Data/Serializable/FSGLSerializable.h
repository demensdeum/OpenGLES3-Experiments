/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLSerializable.h
 * Author: demensdeum
 *
 * Created on October 21, 2017, 1:13 PM
 */

#ifndef FSGLSERIALIZABLE_H
#define FSGLSERIALIZABLE_H

#include <string>
#include <memory>

using namespace std;

class FSGLObject;

class FSGLSerializable {
public:
    
    void serializeIntoFile(shared_ptr<string> path);
    virtual shared_ptr<FSGLSerializable> deserializeFromFile(shared_ptr<string> path);
    
    virtual shared_ptr<string> serializeIntoString();
    virtual shared_ptr<FSGLSerializable> deserializeFromString(shared_ptr<string> serializedData);    
    
private:

};

#endif /* FSGLSERIALIZABLE_H */


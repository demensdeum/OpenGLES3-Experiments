/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSModelLoaderObj.h
 * Author: demensdeum
 *
 * Created on July 9, 2017, 10:07 AM
 */

#ifndef FSMODELLOADEROBJ_H
#define FSMODELLOADEROBJ_H

#include "../FSGLModelLoader.h"

#include <memory>

using namespace std;

class FSGLModelLoaderObj: public FSGLModelLoader {
public:
    FSGLModelLoaderObj();
    FSGLModelLoaderObj(const FSGLModelLoaderObj& orig);
    virtual ~FSGLModelLoaderObj();
    
    static shared_ptr<FSGLModel> loadModel(shared_ptr<string> modelPath);
    
private:

};

#endif /* FSMODELLOADEROBJ_H */


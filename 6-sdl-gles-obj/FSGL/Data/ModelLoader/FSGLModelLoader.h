/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSModelLoader.h
 * Author: demensdeum
 *
 * Created on July 9, 2017, 10:03 AM
 */

#ifndef FSMODELLOADER_H
#define FSMODELLOADER_H

#include "../Model/FSGLModel.h"

#include <memory>

using namespace std;

class FSGLModelLoader {
    
public:
    FSGLModelLoader();
    FSGLModelLoader(const FSGLModelLoader& orig);
    virtual ~FSGLModelLoader();

    static shared_ptr<FSGLModel> loadModel(shared_ptr<string> modelPath);
    
private:

};

#endif /* FSMODELLOADER_H */


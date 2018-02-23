/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVectorKeyframe.h
 * Author: demensdeum
 *
 * Created on November 5, 2017, 3:29 PM
 */

#ifndef FSGLVECTORKEYFRAME_H
#define FSGLVECTORKEYFRAME_H

#include "../Vector/FSGLVector.h"

#include <memory>

using namespace std;

class FSGLVectorKeyframe {
public:
    FSGLVectorKeyframe();
    FSGLVectorKeyframe(const FSGLVectorKeyframe& orig);
    virtual ~FSGLVectorKeyframe();
    
    shared_ptr <FSGLVector> vector;
    double time;
    
private:

};

#endif /* FSGLVECTORKEYFRAME_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLQuaternionKeyframe.h
 * Author: demensdeum
 *
 * Created on November 5, 2017, 3:30 PM
 */

#ifndef FSGLQUATERNIONKEYFRAME_H
#define FSGLQUATERNIONKEYFRAME_H

#include "../Quaternion/FSGLQuaternion.h"

#include <memory>

using namespace std;

class FSGLQuaternionKeyframe {
public:
    FSGLQuaternionKeyframe();
    FSGLQuaternionKeyframe(const FSGLQuaternionKeyframe& orig);
    virtual ~FSGLQuaternionKeyframe();
    
    shared_ptr<FSGLQuaternion> quaternion;
    double time;
    
private:

};

#endif /* FSGLQUATERNIONKEYFRAME_H */


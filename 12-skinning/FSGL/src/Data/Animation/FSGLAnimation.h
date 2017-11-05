/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLAnimation.h
 * Author: demensdeum
 *
 * Created on October 22, 2017, 8:14 PM
 */

#ifndef FSGLANIMATION_H
#define FSGLANIMATION_H

#include <string>
#include <memory>

#include "../NodeAnimation/FSGLNodeAnimation.h"

using namespace std;

class FSGLAnimation {
public:
    FSGLAnimation();
    FSGLAnimation(const FSGLAnimation& orig);
    virtual ~FSGLAnimation();
    
    shared_ptr<string> name;
    
    double duration;
    double ticksPerSecond;
    
    vector< shared_ptr<FSGLNodeAnimation> >  nodeAnimations;
    
private:

};

#endif /* FSGLANIMATION_H */


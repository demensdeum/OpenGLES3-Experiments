/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLNodeAnimation.h
 * Author: demensdeum
 *
 * Created on November 5, 2017, 2:32 PM
 */

#ifndef FSGLNODEANIMATION_H
#define FSGLNODEANIMATION_H

#include <memory>
#include <string>
#include <vector>

#include "../Matrix/FSGLMatrix.h"
#include "../VectorKeyframe/FSGLVectorKeyframe.h"
#include "../QuaternionKeyframe/FSGLQuaternionKeyframe.h"

class FSGLNode;

using namespace std;

class FSGLNodeAnimation {
public:
    FSGLNodeAnimation();
    FSGLNodeAnimation(const FSGLNodeAnimation& orig);
    virtual ~FSGLNodeAnimation();
    
    shared_ptr<string> name;
    
    vector <shared_ptr<FSGLVectorKeyframe> > positions;
    vector <shared_ptr<FSGLQuaternionKeyframe> > rotations;
    vector <shared_ptr<FSGLVectorKeyframe> > scalings;
    
    shared_ptr<FSGLNode> node;
    
	shared_ptr<FSGLMatrix> transformationMatrix();

private:

};

#endif /* FSGLNODEANIMATION_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVertexWeight.h
 * Author: demensdeum
 *
 * Created on November 5, 2017, 1:31 PM
 */

#ifndef FSGLVERTEXWEIGHT_H
#define FSGLVERTEXWEIGHT_H

#include "../Bone/FSGLBone.h"

class FSGLBone;
class FSGLMatrix;

using namespace std;

class FSGLVertexWeight {
public:
    FSGLVertexWeight();
    FSGLVertexWeight(const FSGLVertexWeight& orig);
    virtual ~FSGLVertexWeight();
    
    int vertexID;
    float weight;
    
	shared_ptr<FSGLBone> bone;

	shared_ptr<FSGLMatrix> transformationMatrix();

private:

};

#endif /* FSGLVERTEXWEIGHT_H */


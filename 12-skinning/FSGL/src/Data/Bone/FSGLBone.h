/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLBone.h
 * Author: demensdeum
 *
 * Created on October 22, 2017, 7:37 PM
 */

#ifndef FSGLBONE_H
#define FSGLBONE_H

#include <string>
#include <memory>

#include "../VertexWeight/FSGLVertexWeight.h"

#include <vector>

using namespace std;

class FSGLBone {
public:
    FSGLBone();
    FSGLBone(const FSGLBone& orig);
    virtual ~FSGLBone();
    
    shared_ptr<string> name;
    
    vector<shared_ptr<FSGLVertexWeight> > vertexWeights;
    
private:

};

#endif /* FSGLBONE_H */


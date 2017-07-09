/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVertices.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 12:39 PM
 */

#ifndef FSGLVERTICES_H
#define FSGLVERTICES_H

#include <list>

using namespace std;

class FSGLVertices {
public:
    FSGLVertices();
    FSGLVertices(const FSGLVertices& orig);
    virtual ~FSGLVertices();
    
    void addVertex(float x, float y, float z);
    
private:

    list<float> vertices;
    
};

#endif /* FSGLVERTICES_H */


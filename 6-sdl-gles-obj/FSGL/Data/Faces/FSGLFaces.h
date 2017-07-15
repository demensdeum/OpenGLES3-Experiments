/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLFaces.h
 * Author: demensdeum
 *
 * Created on July 8, 2017, 12:39 PM
 */

#ifndef FSGLFACES_H
#define FSGLFACES_H

#include <list>

using namespace std;

class FSGLFaces {
public:
    FSGLFaces();
    FSGLFaces(const FSGLFaces& orig);
    virtual ~FSGLFaces();
    
    void addFace(int x, int y, int z);
    
private:

    list<int>faces;
};

#endif /* FSGLFACES_H */


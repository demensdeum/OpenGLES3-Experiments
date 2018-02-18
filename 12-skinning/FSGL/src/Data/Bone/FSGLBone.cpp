/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLBone.cpp
 * Author: demensdeum
 * 
 * Created on October 22, 2017, 7:37 PM
 */

#include "FSGLBone.h"
 
#include <iostream>

#include "../Mesh/FSGLMesh.h"

FSGLBone::FSGLBone() {
}

FSGLBone::FSGLBone(const FSGLBone& orig) {
}

void FSGLBone::applyTransformationMatrix(shared_ptr<FSGLMatrix> transformationMatrix) {
    
    cout << "applyAnimationTransformations for bone: " << name->c_str() << endl;
    
	cout << "bone child vertexWeights count: " << vertexWeights.size() << endl;
    
	if (transformationMatrix.get() == nullptr)
{
	cout << "FSGLBone::applyTransformationMatrix transformationMatrix - nullptr" << endl;

	exit(2);
}

	for (auto vertexWeight : vertexWeights) {

		vertexWeight->applyTransformationMatrix(transformationMatrix);

	}

}

shared_ptr<FSGLMatrix> FSGLBone::transformationMatrix() {

	return node->transformationMatrix();

}

FSGLBone::~FSGLBone() {
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLNode.cpp
 * Author: demensdeum
 * 
 * Created on November 5, 2017, 2:03 PM
 */

#include "FSGLNode.h"

#include <iostream>

FSGLNode::FSGLNode() {
}

FSGLNode::FSGLNode(const FSGLNode& orig) {
}

void FSGLNode::applyTransformationMatrix(shared_ptr<FSGLMatrix> transformationMatrix) {
    
    cout << "FSGLNode::applyTransformationMatrix - for node: " << name->c_str() << endl;

	if (transformationMatrix.get() == nullptr) {

		cout << "FSGLNode::applyTransformationMatrix - transformationMatrix is nullptr" << endl;

		return;

	}

        if (bone.get() != nullptr) {
            
            bone->applyTransformationMatrix(transformationMatrix);
            
        }

    for (auto child : childs) {
        
	cout << "applyAnimationTransformations for child node: " << child->name->c_str() << endl;

        child->applyTransformationMatrix(transformationMatrix);
        
    }
}

shared_ptr<FSGLMatrix> FSGLNode::transformationMatrix() {

	return nodeAnimation->transformationMatrix();

}


shared_ptr<FSGLNode> FSGLNode::findNode(shared_ptr<string> nodeName) {
    
    if (name->compare(nodeName->c_str()) == 0) { 
        
        return shared_from_this();
                    
    }
    
    for (auto child : childs) {

        auto foundNode = child->findNode(nodeName);
        
        if (foundNode.get() != nullptr) {
            
            return foundNode;
            
        }
        
    }    
    
    return shared_ptr<FSGLNode>();
}

FSGLNode::~FSGLNode() {
}


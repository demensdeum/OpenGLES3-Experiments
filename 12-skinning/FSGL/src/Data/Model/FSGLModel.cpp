/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSEOGLModel.cpp
 * Author: demensdeum
 * 
 * Created on July 8, 2017, 10:39 AM
 */

#include "FSGLModel.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../ResourcesLoader/FSGLResourceLoader.h"

using namespace std;

FSGLModel::FSGLModel() {
    
}

FSGLModel::FSGLModel(const FSGLModel& orig) {
}
   
shared_ptr<string> FSGLModel::serializeIntoString() {
    
    stringstream serializedData;
    
    serializedData << this->path->c_str();
    
    auto stringContainer = make_shared<string>(serializedData.str());    
    
    return stringContainer;    
}

shared_ptr<FSGLSerializable> FSGLModel::deserializeFromString(shared_ptr<string> serializedData) {

    auto model = static_pointer_cast<FSGLModel>(FSGLResourceLoader::loadResource(serializedData));
    
    auto object = model;
    
    
    cout << serializedData << endl;
    
    return object;
}

shared_ptr<FSGLVector> FSGLModel::currentAnimationPositionVectorForMesh(shared_ptr<FSGLMesh> mesh) {
    
    if (currentAnimation == nullptr) {
        
        return shared_ptr<FSGLVector>();
        
    }
    
    auto nodeAnimation = currentAnimation->nodeAnimations[0]; // only one node right now
    
    auto positionVector = nodeAnimation->positions[currentAnimation->currentOffset];
    
    return positionVector->vector;
}

void FSGLModel::playAnimation(shared_ptr<string> animationName, double animationOffset) {
    
    if (currentAnimation != nullptr && currentAnimation->name->compare(animationName->c_str())== 0) {
        
        currentAnimation->currentOffset = animationOffset;
        
        return;
    }
    
    for (auto animation : animations) {
        
        if (animation->name->compare(animationName->c_str()) == 0) {
            
            currentAnimation = animation;
            
        }
    }
    
}

void FSGLModel::incrementAnimation() {
    
    currentAnimation->increment();
    
}

FSGLModel::~FSGLModel() {

}


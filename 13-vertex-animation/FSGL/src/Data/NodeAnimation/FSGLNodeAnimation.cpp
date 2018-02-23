/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLNodeAnimation.cpp
 * Author: demensdeum
 * 
 * Created on November 5, 2017, 2:32 PM
 */

#include "FSGLNodeAnimation.h"

#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

FSGLNodeAnimation::FSGLNodeAnimation() {

	currentOffset = 0;

}

FSGLNodeAnimation::FSGLNodeAnimation(const FSGLNodeAnimation& orig) {
}

FSGLNodeAnimation::~FSGLNodeAnimation() {
}

shared_ptr<FSGLMatrix> FSGLNodeAnimation::transformationMatrix() {

	cout << "FSGLNodeAnimation "<< name->c_str() << " transformationMatrix for node, animationOffset " << currentOffset << endl;

	auto animationOffset = currentOffset;

    if (animationOffset >= positions.size()) {
        
	cout << "FSGLNodeAnimation::transformationMatrix() animationOffset " << animationOffset << " >= positions.size " << positions.size() << " - return nullptr" << endl;

        return shared_ptr<FSGLMatrix>();
        
    }
    
    // translation

    auto positionVector = positions[animationOffset]->vector;

    if (positionVector.get() == nullptr) {

        return shared_ptr<FSGLMatrix>();

    }

    // rotation

    auto rotationQuaternion = rotations[animationOffset]->quaternion;

    if (rotationQuaternion.get() == nullptr) {

        return shared_ptr<FSGLMatrix>();

    }

    glm::quat rotation;
    rotation.x = rotationQuaternion->x;
    rotation.y = rotationQuaternion->y;
    rotation.z = rotationQuaternion->z;
    rotation.w = rotationQuaternion->w;

    auto rotationMatrix = glm::mat4_cast(rotation);

    // scale
    auto scaleVector = scalings[animationOffset]->vector;
    auto transformationMatrix = glm::mat4(1.0);

    transformationMatrix = glm::translate(transformationMatrix, glm::vec3(positionVector->x, positionVector->y, positionVector->z));
    transformationMatrix = glm::scale(transformationMatrix, glm::vec3(scaleVector->x, scaleVector->y, scaleVector->z));
    transformationMatrix = transformationMatrix * rotationMatrix;

	auto outputMatrix = make_shared<FSGLMatrix>();
	outputMatrix->matrix = transformationMatrix;

	return outputMatrix;

}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLVector.cpp
 * Author: demensdeum
 * 
 * Created on July 29, 2017, 11:47 AM
 */

#include "FSGLVector.h"

#include <iostream>
#include <sstream>

enum {
    FSGLVectorXSerializationIndex,
    FSGLVectorYSerializationIndex,
    FSGLVectorZSerializationIndex,
    FSGLVectorSerializationCount

};

FSGLVector::FSGLVector() {

    x = 0;
    y = 0;
    z = 0;

}

FSGLVector::FSGLVector(float x, float y, float z) {

    this->x = x;
    this->y = y;
    this->z = z;

}

FSGLVector::FSGLVector(const FSGLVector& orig) {
}

shared_ptr<string> FSGLVector::serializeIntoString() {

    stringstream serializedData;

    serializedData << x << "," << y << "," << z;

    auto stringContainer = make_shared<string>(serializedData.str());

    return stringContainer;
}

shared_ptr<FSGLVector> FSGLVector::copy() {
    
    auto vector = make_shared<FSGLVector>(x,y,z);
    
    return vector;
}

shared_ptr<FSGLSerializable> FSGLVector::deserializeFromString(shared_ptr<string> serializedData) {

    auto outputVector = make_shared<FSGLVector>();

    auto serializedDataString = serializedData->c_str();

    std::stringstream serializedDataStringStream(serializedDataString);

    for (auto i = 0; i < FSGLVectorSerializationCount; i++) {

        float value;

        serializedDataStringStream >> value;

        cout << value << endl;

        switch (i) {

            case FSGLVectorXSerializationIndex:
                
                outputVector->x = value;
                
                break;

            case FSGLVectorYSerializationIndex:
                
                outputVector->y = value;
                
                break;

            case FSGLVectorZSerializationIndex:
                
                outputVector->z = value;
                
                break;
        }

        if (serializedDataStringStream.peek() == ',') {

            serializedDataStringStream.ignore();

        }
    }

    return outputVector;
}

FSGLVector::~FSGLVector() {
}


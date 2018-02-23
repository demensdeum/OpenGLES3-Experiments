/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLMesh.cpp
 * Author: demensdeum
 * 
 * Created on August 1, 2017, 11:02 PM
 */

#include <glm/detail/type_vec.hpp>

#include "FSGLMesh.h"

#include "../Object/FSGLObject.h"

#include <iostream>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define SKINNING_ENABLED 1

FSGLMesh::FSGLMesh() {
}

FSGLMesh::FSGLMesh(const FSGLMesh& orig) {
}

shared_ptr<FSGLVertex> FSGLMesh::vertexWithID(int index) {

	return verticesObjects[index];

}

void FSGLMesh::resetTransformationMatrix() {

	    for (auto vertexObject : verticesObjects) {

		vertexObject->resetTransformationMatrix();

	}

}

shared_ptr<FSGLBone> FSGLMesh::findBone(shared_ptr<string> boneName) {

    for (auto bone : bones) {

        if (bone->name->compare(boneName->c_str()) == 0) {

            return bone;

        }

    }

    return shared_ptr<FSGLBone>();

}

void FSGLMesh::updateGlAnimationTransformation() {

    for (unsigned int i = 0; i < vertices.size(); i += glVertexCount) {

	auto vertexObject = verticesObjects[i / glVertexCount];

#if SKINNING_ENABLED

	if (vertexObject.get() == nullptr)
	{
		cout << "vertexObject is null" << endl;

		exit(1);

	}

	if (vertexObject->transformMatrix.get() == nullptr)
	{

	cout << "Vertex transform matrix is null, do not apply animation" << endl;

        glVertices[i + 5] = 1;
        glVertices[i + 6] = 0;
        glVertices[i + 7] = 0;
        glVertices[i + 8] = 0;

        glVertices[i + 9] = 0;
        glVertices[i + 10] = 1;
        glVertices[i + 11] = 0;
        glVertices[i + 12] = 0;

        glVertices[i + 13] = 0;
        glVertices[i + 14] = 0;
        glVertices[i + 15] = 1;
        glVertices[i + 16] = 0;

        glVertices[i + 17] = 0;
        glVertices[i + 18] = 0;
        glVertices[i + 19] = 0;
        glVertices[i + 20] = 1;

	}
else
{

	auto transformMatrix = vertexObject->transformMatrix;
	auto transformationMatrix = transformMatrix->matrix;

	//cout << "Vertex transform animation applied" << endl;

        glVertices[i + 5] = transformationMatrix[0][0];
        glVertices[i + 6] = transformationMatrix[1][0];
        glVertices[i + 7] = transformationMatrix[2][0];
        glVertices[i + 8] = transformationMatrix[3][0];

        glVertices[i + 9] = transformationMatrix[0][1];
        glVertices[i + 10] = transformationMatrix[1][1];
        glVertices[i + 11] = transformationMatrix[2][1];
        glVertices[i + 12] = transformationMatrix[3][1];

        glVertices[i + 13] = transformationMatrix[0][2];
        glVertices[i + 14] = transformationMatrix[1][2];
        glVertices[i + 15] = transformationMatrix[2][2];
        glVertices[i + 16] = transformationMatrix[3][2];

        glVertices[i + 17] = transformationMatrix[0][3];
        glVertices[i + 18] = transformationMatrix[1][3];
        glVertices[i + 19] = transformationMatrix[2][3];
        glVertices[i + 20] = transformationMatrix[3][3];
}

#else

        glVertices[i + 5] = 1;
        glVertices[i + 6] = 0;
        glVertices[i + 7] = 0;
        glVertices[i + 8] = 0;

        glVertices[i + 9] = 0;
        glVertices[i + 10] = 1;
        glVertices[i + 11] = 0;
        glVertices[i + 12] = 0;

        glVertices[i + 13] = 0;
        glVertices[i + 14] = 0;
        glVertices[i + 15] = 1;
        glVertices[i + 16] = 0;

        glVertices[i + 17] = 0;
        glVertices[i + 18] = 0;
        glVertices[i + 19] = 0;
        glVertices[i + 20] = 1;

#endif

}

}

void FSGLMesh::updateGlData() {

    glVertices = new GLfloat[vertices.size() * glVertexCount];

    for (unsigned int i = 0; i < vertices.size(); i += glVertexCount) {

	auto vertexObject = verticesObjects[i / glVertexCount];


        glVertices[i] = vertexObject->position->x;
        glVertices[i + 1] = vertexObject->position->y;
        glVertices[i + 2] = vertexObject->position->z;

        glVertices[i + 3] = vertexObject->uvTextureCoordinates->u;
        glVertices[i + 4] = vertexObject->uvTextureCoordinates->v;

        // mat4

        glVertices[i + 5] = 1;
        glVertices[i + 6] = 0;
        glVertices[i + 7] = 0;
        glVertices[i + 8] = 0;

        glVertices[i + 9] = 0;
        glVertices[i + 10] = 1;
        glVertices[i + 11] = 0;
        glVertices[i + 12] = 0;

        glVertices[i + 13] = 0;
        glVertices[i + 14] = 0;
        glVertices[i + 15] = 1;
        glVertices[i + 16] = 0;

        glVertices[i + 17] = 0;
        glVertices[i + 18] = 0;
        glVertices[i + 19] = 0;
        glVertices[i + 20] = 1;

    }

    glIndices = new GLushort[indices.size() * sizeof (GLushort)];

    for (unsigned int i = 0; i < indices.size(); i++) {

        glIndices[i] = indices[i];

    }

    glVerticesBufferSize = vertices.size() * sizeof (GLfloat);
    glIndicesBufferSize = indices.size() * sizeof (GLushort);
    glIndicesCount = indices.size();

}

FSGLMesh::~FSGLMesh() {

    if (glIndices != NULL) {

        delete glIndices;

    }

    if (glVertices != NULL) {

        delete glVertices;

    }

}


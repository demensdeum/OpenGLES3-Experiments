 
#include "FSGLVertex.h"

#include <iostream>
#include <string>

using namespace std;

FSGLVertex::FSGLVertex(float x, float y, float z, float u, float v) {

	position = make_shared<FSGLVector>(x, y, z);
	uvTextureCoordinates = make_shared<FSGLUVTextureCoordinates>(u , v);

}

void FSGLVertex::updateAnimatedPosition() {


}

void FSGLVertex::updateTransformMatrix() {

	

}

void FSGLVertex::applyTransformationMatrixWithWeight(shared_ptr<FSGLMatrix> transformationMatrix, float weight) {

	cout << "apply transformation matrix with weight" << endl;

	if (transformMatrix.get() == nullptr)
{
	cout << "transformMatrix = nullptr" << endl;
}

	this->transformMatrix = transformationMatrix;

}
 
#include "FSGLVertex.h"

FSGLVertex::FSGLVertex(float x, float y, float z, float u, float v) {

	position = make_shared<FSGLVector>(x, y, z);
	uvTextureCoordinates = make_shared<FSGLUVTextureCoordinates>(u , v);

	animatedPosition = position;
}

void FSGLVertex::updateAnimatedPosition() {

	animatedPosition = position;

	if (vertexWeights.size() > 0) {

		auto vertexWeight = vertexWeights[0];

		auto transformationMatrix = vertexWeight->transformationMatrix();

		
	}
}

void FSGLVertex::updateTransformMatrix() {

	

}
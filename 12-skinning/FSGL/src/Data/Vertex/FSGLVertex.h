#ifndef FSGLVERTEX_H
#define FSGLVERTEX_H


#include <memory>

#include "../Vector/FSGLVector.h"
#include "../Mesh/FSGLMesh.h"
#include "../Matrix/FSGLMatrix.h"
#include "../Bone/FSGLBone.h"
#include "../UVTextureCoordinates/FSGLUVTextureCoordinates.h"
#include "../VertexWeight/FSGLVertexWeight.h"

using namespace std;

class FSGLVertexWeight;
class FSGLMesh;
class FSGLBone;

class FSGLVertex {

	public:
		FSGLVertex(float x, float y, float z, float u, float v);

		shared_ptr<FSGLVector> position;
		shared_ptr<FSGLUVTextureCoordinates> uvTextureCoordinates;

		shared_ptr<FSGLMatrix> transformMatrix;

		weak_ptr<FSGLMesh> mesh;

		vector<shared_ptr<FSGLVertexWeight> > vertexWeights;

		vector<shared_ptr<FSGLBone> > bones;

		void updateTransformMatrix();

		void updateAnimatedPosition();

		void applyTransformationMatrixWithWeight(shared_ptr<FSGLMatrix> transformationMatrix, float weight);

};

#endif
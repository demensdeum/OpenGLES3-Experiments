/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLNode.h
 * Author: demensdeum
 *
 * Created on November 5, 2017, 2:03 PM
 */

#ifndef FSGLNODE_H
#define FSGLNODE_H

#include <string>
#include <memory>
#include <vector>

#include <glm/glm.hpp>

#include "../NodeAnimation/FSGLNodeAnimation.h"
#include "../Mesh/FSGLMesh.h"

#include "../Matrix/FSGLMatrix.h"

class FSGLMesh;

using namespace std;

class FSGLNode: public enable_shared_from_this<FSGLNode> {
public:
    FSGLNode();
    FSGLNode(const FSGLNode& orig);
    virtual ~FSGLNode();
    
    shared_ptr<string> name;
    
    shared_ptr<FSGLNode> parent;
    vector < shared_ptr<FSGLNode> > childs;
    
    vector< shared_ptr<FSGLMesh> > meshes;
    
    shared_ptr<FSGLBone> bone;
    
    glm::mat4 matrix;
    
    void applyAnimationTransformations(shared_ptr<FSGLNodeAnimation> nodeAnimation, shared_ptr<FSGLMatrix> transformationMatrix);
    
    shared_ptr<FSGLNode> findNode(shared_ptr<string> nodeName);
    
	shared_ptr<FSGLNodeAnimation> nodeAnimation;

	shared_ptr<FSGLMatrix> transformationMatrix();

private:

};

#endif /* FSGLNODE_H */


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLUtils.h
 * Author: demensdeum
 *
 * Created on October 15, 2017, 1:37 PM
 */

#ifndef FSGLUTILS_H
#define FSGLUTILS_H

#include <string>
#include <memory>

using namespace std;

class FSGLUtils {
public:
    FSGLUtils();
    FSGLUtils(const FSGLUtils& orig);
    virtual ~FSGLUtils();
    
    static shared_ptr<string> filePathExtension(shared_ptr<string> filePath);  
    
private:

};

#endif /* FSGLUTILS_H */


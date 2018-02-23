/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FSGLUtils.cpp
 * Author: demensdeum
 * 
 * Created on October 15, 2017, 1:37 PM
 */

#include "FSGLUtils.h"

FSGLUtils::FSGLUtils() {
}

shared_ptr<string> FSGLUtils::filePathExtension(shared_ptr<string> filePath) {

    auto index = filePath->find_last_of(".");
    
    auto extension = filePath->substr(index + 1);
    
    auto extensionContainer = make_shared<string>(extension.c_str());
    
    return extensionContainer;

}

FSGLUtils::FSGLUtils(const FSGLUtils& orig) {
}

FSGLUtils::~FSGLUtils() {
}


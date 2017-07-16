#include <memory>
#include <chrono>
#include <thread>

#include "FSGL/Data/ResourcesLoader/FSGLResourceLoader.h"
#include "FSGL/Controller/FSGLController.h"

using namespace std;

int main(int argc, char **argv) {

    auto controller = std::make_shared<FSGLController>();
    
    controller->run();
    
    auto model = static_pointer_cast<FSGLModel>(FSGLResourceLoader::loadResource(make_shared<string>("teapot.obj")));
    
    controller->addModel(model);
    
    controller->render();
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    
    controller->stop();
    
    return 0;
}
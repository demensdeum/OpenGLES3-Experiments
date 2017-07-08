#include <memory>
#include <chrono>
#include <thread>

#include "FSGL/FSGLController/FSGLController.h"

using namespace std;

int main(int argc, char **argv) {

    auto controller = std::make_shared<FSGLController>();
    
    controller->run();
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    
    controller->stop();
    
    return 0;
}
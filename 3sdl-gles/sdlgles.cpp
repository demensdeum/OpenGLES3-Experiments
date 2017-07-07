#include <SDL2/SDL.h>
#include <GLES3/gl3.h>

#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char **argv) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
            "SDL2 - OGLES",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_OPENGL
            );
	    

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
	    
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
	    
    SDL_GL_SwapWindow(window);
	    
    this_thread::sleep_for(chrono::milliseconds(2000));
    
    SDL_GL_DeleteContext(glContext);
    
    SDL_Quit();
}
#include <stdlib.h>
#include <unistd.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"

static EGLint const attribute_list[] = {
    EGL_RED_SIZE, 1,
    EGL_GREEN_SIZE, 1,
    EGL_BLUE_SIZE, 1,
    EGL_NONE
};

int main(int argc, char ** argv) {

    EGLDisplay display;
    EGLConfig config;
    EGLContext context;
    EGLSurface surface;

    EGLint num_config;

    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    eglInitialize(display, NULL, NULL);

    eglChooseConfig(display, attribute_list, &config, 1, &num_config);

    context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
            "An SDL2 window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_OPENGL
            );

    SDL_SysWMinfo info;

    SDL_VERSION(&info.version);

    SDL_GetWindowWMInfo(window, &info);
    surface = eglCreateWindowSurface(display, config, info.info.x11.window, NULL);

    eglMakeCurrent(display, surface, surface, context);

    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    eglSwapBuffers(display, surface);
    sleep(10);
    
    return EXIT_SUCCESS;
}
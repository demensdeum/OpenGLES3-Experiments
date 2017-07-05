cmake_minimum_required( VERSION 3.5 )

project( HelloTriangle )

find_library( OPENGLES3_LIBRARY GLESv2 "OpenGL ES v3.0 library")
find_library( EGL_LIBRARY EGL "EGL 1.4 library" )
 
file(GLOB SOURCE_FILES
    "hello-triangle.cpp"
)

add_executable(HelloTriangle ${SOURCE_FILES})
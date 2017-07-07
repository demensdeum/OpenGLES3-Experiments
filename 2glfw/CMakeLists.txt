cmake_minimum_required( VERSION 3.5 )

project( HelloGLFW )

find_library( GLFW3 GLESv2 )
 
file(GLOB SOURCE_FILES
    "glfw.c"
)

add_executable(HelloGLFW ${SOURCE_FILES})

target_link_libraries(HelloGLFW glfw GLESv2)
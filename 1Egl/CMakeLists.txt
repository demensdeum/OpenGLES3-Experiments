cmake_minimum_required( VERSION 3.5 )

project( HelloTriangle )

find_library( SDL2 EGL GLESv2 )
 
file(GLOB SOURCE_FILES
    "egl.c"
)

add_executable(HelloTriangle ${SOURCE_FILES})

target_link_libraries(HelloTriangle SDL2 EGL GLESv2)
cmake_minimum_required( VERSION 3.5 )

project( teapot )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library( SDL2 GLESv2 )
 
file(GLOB_RECURSE SOURCE_FILES
    "main.cpp"
)

add_executable(teapot ${SOURCE_FILES})

target_link_libraries(teapot SDL2 GLESv2)
cmake_minimum_required( VERSION 3.5 )

project( SDLGles )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library( SDL2 GLESv2 ASSIMP )
 
file(GLOB_RECURSE SOURCE_FILES
    "main.cpp",
    "FSGL/*.cpp"
)

add_executable(SDLGlesObj ${SOURCE_FILES})

target_link_libraries(SDLGlesObj SDL2 GLESv2 assimp)
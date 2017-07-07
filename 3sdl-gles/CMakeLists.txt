cmake_minimum_required( VERSION 3.5 )

project( SDLGles )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library( SDL2 GLESv2 )
 
file(GLOB SOURCE_FILES
    "sdlgles.cpp"
)

add_executable(SDLGles ${SOURCE_FILES})

target_link_libraries(SDLGles SDL2 GLESv2)
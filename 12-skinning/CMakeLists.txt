cmake_minimum_required( VERSION 3.5 )

set(PROJECT_NAME Skinning)

project( ${PROJECT_NAME} )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES
    "skinning/*.cpp",
    "FSGL/*.cpp"
)

set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(MSVC)

 target_link_libraries(${PROJECT_NAME} SDL2 opengl32 glew32s assimp)
 
else(MSVC)

 target_link_libraries(${PROJECT_NAME} SDL2 GL assimp)
#target_link_libraries(${PROJECT_NAME} SDL2 GLESv2 assimp)

endif(MSVC)
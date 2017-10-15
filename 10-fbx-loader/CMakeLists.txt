cmake_minimum_required( VERSION 3.5 )

set(PROJECT_NAME FBXLoader)

project( ${PROJECT_NAME} )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCE_FILES
    "fbxloader/*.cpp",
    "FSGL/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

if(MSVC)

 target_link_libraries(${PROJECT_NAME} SDL2 opengl32 glew32s assimp)
 
else(MSVC)

 target_link_libraries(${PROJECT_NAME} SDL2 GLESv2 assimp)

endif(MSVC)
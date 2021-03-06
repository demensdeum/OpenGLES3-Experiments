EMSCRIPTEN_SDK_PATH=~/emsdk/emsdk_portable

echo $EMSCRIPTEN_SDK_PATH

source $EMSCRIPTEN_SDK_PATH/emsdk_env.sh

FSEGT_PROJECT_NAME=WebFSGL

cd $FSEGT_PROJECT_NAME

FSEGT_PROJECT_FILES=`find . -name "*.cpp" | paste -s -d" "`

FSEGT_PROJECT_COMPILE_FLAGS="-s FULL_ES2=1 -I../3rdparty/ -O3 -o $FSEGT_PROJECT_NAME.html --std=c++14"

echo emcc $FSEGT_PROJECT_FILES $FSEGT_PROJECT_COMPILE_FLAGS

emcc $FSEGT_PROJECT_FILES $FSEGT_PROJECT_COMPILE_FLAGS
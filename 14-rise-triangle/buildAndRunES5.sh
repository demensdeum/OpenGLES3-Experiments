rm -rf build
mkdir build

cp -R data build
cp src/html/index.html build

python Rise/rise2es5.py src build/main.js
cd build
chromium-browser index.html &
rm -rf ./build

cmake -B ./build -G Ninja -DCMAKE_BUILD_TYPE=Rlease -DHERMES_SOURCE_DIR=/home/renyufei/code/hermes_worspace/hermes/ -DHERMES_BINARY_DIR=/home/renyufei/code/hermes_worspace/build_release
cmake --build ./build

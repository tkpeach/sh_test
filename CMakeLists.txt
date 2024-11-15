cmake_minimum_required(VERSION 3.26)
project(shermes_test)

set(CMAKE_CXX_STANDARD 17)

set(SHERMES ${HERMES_BINARY_DIR}/tools/shermes CACHE FILEPATH "shermes tool path")

add_subdirectory(number)

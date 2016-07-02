cmake_minimum_required(VERSION 2.8)
project(tmva-tensorflow-examples)

# Find ROOT
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})
list(APPEND ROOT_LIBRARIES)

# Build target
add_executable(TMVAUsage TMVAUsage.C)
target_link_libraries(TMVAUsage ${ROOT_LIBRARIES})

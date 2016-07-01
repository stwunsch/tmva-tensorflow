# Setup project
cmake_minimum_required(VERSION 2.8)

project(tmva-tensorflow CXX)
set(CMAKE_BUILD_TYPE Release)

# Find dependencies
find_package(ROOT)

# Build shared library/plugin for TMVA
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${ROOT_INCLUDE_DIRS})
add_library(MethodTensorflow SHARED src/MethodTensorflow.cxx)
target_link_libraries(MethodTensorflow ${ROOT_LIBRARIES})

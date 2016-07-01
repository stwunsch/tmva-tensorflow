# Setup project
cmake_minimum_required(VERSION 2.8)

project(tmva-tensorflow CXX)
set(CMAKE_BUILD_TYPE Release)

# Find dependencies
if(NOT DEFINED ENV{ROOTSYS})
    message(FATAL_ERROR "Please setup your ROOT installation to populate the ROOTSYS environment variable.")
endif()
if(NOT DEFINED ENV{TENSORFLOW_DIR})
    message(FATAL_ERROR "Please set TENSORFLOW_DIR environment variable to your local tensorflow installation path.")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
find_package(ROOT)
find_package(Tensorflow)

# Build shared library/plugin for TMVA
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${ROOT_INCLUDE_DIRS} ${TENSORFLOW_INCLUDE_DIRS})
add_library(MethodTensorflow SHARED src/MethodTensorflow.cxx)
target_link_libraries(MethodTensorflow ${ROOT_LIBRARIES} ${TENSORFLOW_LIBRARIES})

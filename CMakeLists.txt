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

# FIXME: remove this bugfix later on
list(APPEND TENSORFLOW_INCLUDE_DIRS /home/stefan/src/tensorflow/tensorflow/contrib/makefile/gen/proto)
list(APPEND TENSORFLOW_INCLUDE_DIRS /home/stefan/src/tensorflow/tensorflow/contrib/makefile/downloads)
list(APPEND TENSORFLOW_INCLUDE_DIRS /home/stefan/src/tensorflow/tensorflow/contrib/makefile/downloads/eigen-eigen-334b1d428283)
message(WARNING "TENSORFLOW_INCLUDE_DIRS: " ${TENSORFLOW_INCLUDE_DIRS})

# Build shared library/plugin for TMVA
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${ROOT_INCLUDE_DIRS} ${TENSORFLOW_INCLUDE_DIRS})
add_library(MethodTensorflow SHARED src/MethodTensorflow.cxx)
target_link_libraries(MethodTensorflow ${ROOT_LIBRARIES} ${TENSORFLOW_LIBRARIES})

# Build executable for testing # FIXME: remove me later on
add_executable(testApp apps/main.cc)
target_link_libraries(testApp ${TENSORFLOW_LIBRARIES})

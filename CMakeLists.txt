cmake_minimum_required(VERSION 2.8)
project(tmva-tensorflow)

if(NOT DEFINED ENV{ROOTSYS})
    message(FATAL_ERROR "Please setup your ROOT installation to populate the ROOTSYS environment variable.")
endif()
#if(NOT DEFINED ENV{TENSORFLOW_DIR})
#    message(FATAL_ERROR "Please set TENSORFLOW_DIR environment variable to your local tensorflow installation path.")
#endif()

# Find ROOT
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})

# Find Tensorflow
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
#find_package(Tensorflow REQUIRED)
#list(APPEND TENSORFLOW_INCLUDE_DIRS /home/stefan/src/tensorflow/tensorflow/contrib/makefile/gen/proto)
#list(APPEND TENSORFLOW_INCLUDE_DIRS /home/stefan/src/tensorflow/tensorflow/contrib/makefile/downloads)
#list(APPEND TENSORFLOW_INCLUDE_DIRS /home/stefan/src/tensorflow/tensorflow/contrib/makefile/downloads/eigen-eigen-334b1d428283)

# Build TMVA plugin
include_directories(${CMAKE_SOURCE_DIR}/inc)
ROOT_GENERATE_DICTIONARY(G__MethodTensorflow MethodTensorflow.h LINKDEF LinkDef.h)
add_library(TMVATensorflow SHARED src/MethodTensorflow.cxx G__MethodTensorflow.cxx)
target_link_libraries(TMVATensorflow ${ROOT_LIBRARIES})

FIND_PATH(
    TENSORFLOW_INCLUDE_DIRS
    NAMES tensorflow/core/public/session.h
    HINTS $ENV{TENSORFLOW_DIR}
)

FIND_LIBRARY(
    TENSORFLOW_LIBRARIES
    NAMES tensorflow_cc
    HINTS $ENV{TENSORFLOW_DIR}/bazel-bin/tensorflow
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Tensorflow DEFAULT_MSG TENSORFLOW_LIBRARIES TENSORFLOW_INCLUDE_DIRS)
MARK_AS_ADVANCED(TENSORFLOW_LIBRARIES TENSORFLOW_INCLUDE_DIRS)

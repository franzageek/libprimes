#!/bin/bash

#   *** LIBPRIMES 1.0.0 INSTALLER ***
#   *** developed by <franzageek> ***
#   
#  /*************************************************
#   *  libprimes is a free & open-source project    *
#   *  developed & maintained by <franzageek>.      *
#   *  You can discover it at the following link:   *
#   *  [https://github.com/franzageek/libprimes]    *
#   *                                               *
#   *  The code is licensed to you under the        *
#   *  MIT License (https://mit-license.org/).      *
#   *************************************************/

# Build subdirectory {$CURRENT_DIR/$BUILD_DIR}
BUILD_DIR="build"

# Build configuration [Release||Debug]
BUILD_CONFIG="Release"

# Decide whether or not to run tests [true||false]
RUN_TESTS="true"

echo "//   libprimes v1.0.0   //"
echo "// made by <franzageek> //"

for cmd in cmake make ctest; do
    if ! command -v $cmd &> /dev/null; then
        echo "Error: $cmd is not installed."
        exit 1
    fi
done

if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR"

if [ $RUN_TESTS == "true" ]; then
    cmake -DCMAKE_BUILD_TYPE=$BUILD_CONFIG ..
    make -j
    ctest -VV -j
    if [ $? -ne 0 ]; then
        echo "One or more tests failed. Aborting installation (build files will be kept)."
        exit 1
    fi
    echo "All tests passed, proceeding."
    make install -j
    exit 0
fi

cmake -DBUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=$BUILD_CONFIG ..

make install -j

exit 0

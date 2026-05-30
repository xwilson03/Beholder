#!/bin/bash -eux


while [[ $# -gt 0 ]]; do
case $1 in
    -c|--clean) CLEAN=; shift;;
esac
done

REPO_DIR=$(git rev-parse --show-toplevel)

SOURCE_DIR=$REPO_DIR
BUILD_DIR=$REPO_DIR/.build
INSTALL_DIR=$REPO_DIR/.install


[[ -v CLEAN ]] && rm -rf $BUILD_DIR $INSTALL_DIR

cmake \
    -G Ninja       \
    -S $SOURCE_DIR \
    -B $BUILD_DIR  \
    -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
    -DCMAKE_CXX_COMPILER:FILEPATH=$(which clang++)

cmake --build $BUILD_DIR
cmake --install $BUILD_DIR

#!/bin/bash
set -e

SCRIPT_DIR=$(cd $(dirname $0) && pwd)
REPO_DIR=$(dirname $SCRIPT_DIR)

SRC_DIR=$REPO_DIR
BUILD_DIR=$REPO_DIR/.build
INSTALL_DIR=$REPO_DIR/.install

cmake                                 \
  -G Ninja                            \
  -S $REPO_DIR                        \
  -B $BUILD_DIR                       \
  -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
  $SRC_DIR

cmake --build $BUILD_DIR
cmake --install $BUILD_DIR

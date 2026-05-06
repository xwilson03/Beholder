#!/bin/bash -eu

HERE=$(cd $(dirname $0) && pwd)
. $HERE/.env

cmake                                 \
  -G Ninja                            \
  -S $SOURCE_DIR                      \
  -B $BUILD_DIR                       \
  -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
  $SOURCE_DIR

cmake --build $BUILD_DIR
cmake --install $BUILD_DIR

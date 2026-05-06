#!/bin/bash -eu

HERE=$(cd $(dirname $0) && pwd)
. $HERE/.env

rm -rf           \
    $BUILD_DIR   \
    $INSTALL_DIR

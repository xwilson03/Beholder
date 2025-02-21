#!/bin/bash
set -e

SCRIPT_DIR=$(dirname $(realpath $0))
REPO_DIR=$(dirname $SCRIPT_DIR)

BUILD_DIR=$REPO_DIR/build
INSTALL_DIR=$REPO_DIR/install

rm -rf           \
    $BUILD_DIR   \
    $INSTALL_DIR

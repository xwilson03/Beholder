#!/bin/bash
set -e

SCRIPT_DIR=$(dirname $(realpath $0))
REPO_DIR=$(dirname $SCRIPT_DIR)

INSTALL_DIR=$REPO_DIR/install

if [[ ! -d $INSTALL_DIR ]]; then
    echo "ERROR: Missing install directory."
    exit -1
fi

$INSTALL_DIR/bin/Beholder

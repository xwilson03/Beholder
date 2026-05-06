#!/bin/bash
set -e

HERE=$(cd $(dirname $0) && pwd)
. $HERE/.env

if [[ ! -d $INSTALL_DIR ]]; then
    echo "ERROR: Missing install directory."
    exit -1
fi

$INSTALL_DIR/bin/Beholder

#!/bin/bash

cd ~/Beholder-Qt
if [[ ! -d build ]]; then
    echo "ERROR: Missing build directory."
    exit -1
fi

./build/src/app/beholder

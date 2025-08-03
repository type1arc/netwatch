#!/bin/zsh

cd build || { echo "[ERROR] build directory not found"; exit 1 }
cmake --build .
./netwatch

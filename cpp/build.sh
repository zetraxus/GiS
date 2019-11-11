#!/bin/bash
path=cpp/compile
rm -rf $path
mkdir $path
cd $path
cmake ..
make

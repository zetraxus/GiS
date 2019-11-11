#!/bin/bash
path=generator/compile
rm -rf examples/generate/*
mkdir $path
cd $path
cmake ../../cpp
make
./generator
cd ../../
rm -rf $path

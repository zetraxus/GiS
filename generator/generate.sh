#!/bin/bash
path=generator/compile
rm -rf examples/*

vertices=( 500 1000 2500 5000 7500 10000 12500 )
density=( 0.01 0.05 0.10 0.30 0.60 )

for i in "${vertices[@]}"
do
  mkdir 'examples/'$i
  for j in "${density[@]}"
  do
    mkdir 'examples/'$i/$j
  done
done

mkdir $path
cd $path
cmake ../../cpp
make
./generator
cd ../../
rm -rf $path

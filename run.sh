#!/bin/bash

PYTHON=python3
PYTHONTMP=tmp_python

for i in {0..9}
do
    echo -n "Test $i: "
    eval $PYTHON python/runner.py < "examples/in$i" > $PYTHONTMP
    if cmp -s $PYTHONTMP "examples/out$i";
    then
        echo [Py: OK]
    else
        echo [Py: FAILED]
    fi
done

rm -f $PYTHONTMP
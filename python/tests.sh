#!/bin/bash

PYTHON=python3
PYTHONTMP=tmp_python

TESTS_PATH=../examples/

let TESTS_COUNT=(`ls ${TESTS_PATH}in* -1 | wc -l`)-1

for i in $(seq 0 $TESTS_COUNT)
do
    echo -n "Test $i: "
    eval $PYTHON runner.py < "${TESTS_PATH}in$i" > $PYTHONTMP
    if cmp -s $PYTHONTMP "${TESTS_PATH}out$i";
    then
        echo [Py: OK]
    else
        echo [Py: FAILED]
    fi
done

rm -f $PYTHONTMP
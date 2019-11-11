#!/bin/bash
path=cpp/compile/cpp
generate_examples=examples/generate

action(){
    time=0
    iteration=`expr $iteration + 1`

    for f in "$examples"/*;
    do
        a=$(./$path $f)
        time=$(($time + $a))
    done

    all_time=$(($all_time + $time))
    avg_one_loop_before=$avg
    avg=$(($all_time / $iteration))
}


for directory in "$generate_examples"/*;
do
    examples=$directory/

    iteration=0
    all_time=0
    avg_one_loop_before=0
    avg=0

    action
    action
    while [ $avg -ne $avg_one_loop_before ] ; do
        action
        echo $avg_one_loop_before
        echo $avg
        echo 'delta (in microseconds)' $(($avg_one_loop_before-$avg)) | sed 's/-//'
    done
    echo 'iteration= ' $iteration
    echo $directory ' avg=' $avg
done


#!/bin/bash

rm -f output.txt

tarjan_algorithm_cpp=./cpp/compile/cpp
tarjan_algorithm_python="python3 python/runner.py"
tarjan_algorithm_paths=("$tarjan_algorithm_python" $tarjan_algorithm_cpp)
generate_data=./generator/compile/generator

vertices=(500 1000 1500 2000 2500)
density=(0.01 0.05 0.10 0.30 0.60)
path_to_package=0
current_implementation=0

run_all_tests_in_package() {
  time=0
  iteration=$(expr $iteration + 1)

  for file in "$path_to_package"/*; do
    a=$($current_implementation $file)
    time=$(($time + $a))
  done

  all_time=$(($all_time + $time))
  avg_one_loop_before=$avg
  avg=$(($all_time / $iteration))
  diff=$(($avg - $avg_one_loop_before))
  diff=${diff#-}
  diff=$((1000 * $diff))
  diff=$(($diff / $avg))
}

print_date() {
  dt=$(date '+%d/%m/%Y %H:%M:%S')
  echo $k "$dt"
}

generate_graphs() {
  ./generator/prepare_directory_tree.sh
  args="0 10 20 30 40"
  pids=""
  for arg in $args; do
    $generate_data $arg &
    pids+="$! "
  done

  # wait for all pids
  for pid in $pids; do
    wait $pid
  done
}

for k in {1..10}; do
  print_date
  generate_graphs
  for algorithm_path in "${tarjan_algorithm_paths[@]}"; do
    current_implementation=$algorithm_path
    echo $current_implementation
    for i in "${vertices[@]}"; do
      for j in "${density[@]}"; do
        path_to_package='examples'/$i/$j
        print_date
        iteration=0
        all_time=0
        avg_one_loop_before=0
        avg=0
        diff=0
        run_all_tests_in_package
        run_all_tests_in_package
        while [ $iteration -lt 15 ] || [ $diff -gt 0 ]; do
          run_all_tests_in_package
        done
        echo $k/10 $current_implementation $path_to_package ' avg=' $avg 'iteration= ' $iteration >>output.txt
      done
    done
  done
done

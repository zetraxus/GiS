#!/bin/bash

rm -f output.txt

tarjan_algorithm_cpp=./cpp/compile/cpp
tarjan_algorithm_python="python3 python/runner.py"
tarjan_algorithm_paths=($tarjan_algorithm_cpp "$tarjan_algorithm_python")

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
}

for k in {1..10} ; do
  dt=$(date '+%d/%m/%Y %H:%M:%S');
  echo $k "$dt"
#  ./generator/generate.sh
  for algorithm_path in "${tarjan_algorithm_paths[@]}"; do
    current_implementation=$algorithm_path
    echo $current_implementation
    for i in "${vertices[@]}"; do
      for j in "${density[@]}"; do
          path_to_package='examples'/$i/$j

            iteration=0
            all_time=0
            avg_one_loop_before=0
            avg=0
            diff=0
            run_all_tests_in_package
            run_all_tests_in_package
            while [ $iteration -lt 25 ] || [ $diff -gt 10 ]; do
              run_all_tests_in_package
            done
            echo $k/10 $current_implementation $path_to_package ' avg=' $avg 'iteration= ' $iteration >> output.txt
      done
    done
  done
done

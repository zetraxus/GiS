#!/bin/bash
tarjan_algorithm=cpp/compile/cpp

vertices=(500 1000 2500 5000 7500 10000 12500)
density=(0.01 0.05 0.10 0.30 0.60)
path_to_package=0

run_all_test_in_package() {
  time=0
  iteration=$(expr $iteration + 1)

  for file in "$path_to_package"/*; do
    a=$(./$tarjan_algorithm $file)
    time=$(($time + $a))
  done

  all_time=$(($all_time + $time))
  avg_one_loop_before=$avg
  avg=$(($all_time / $iteration))
}

for i in "${vertices[@]}"; do
  for j in "${density[@]}"; do
      path_to_package='examples'/$i/$j

        iteration=0
        all_time=0
        avg_one_loop_before=0
        avg=0

        run_all_test_in_package
        run_all_test_in_package
        while [ $avg -ne $avg_one_loop_before ]; do
          run_all_test_in_package
          echo $avg_one_loop_before
          echo $avg
          echo 'delta (in microseconds)' $(($avg_one_loop_before - $avg)) | sed 's/-//'
        done
        echo 'iteration= ' $iteration
        echo $path_to_package ' avg=' $avg
  done
done

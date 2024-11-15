#!/bin/bash

set -e
set -x

tsc ./number/bunny-mark.ts
commands=("./build/bin/number-calc" "./build/bin/number-calc-js" "node ./number/bunny-mark.js"  "./build/bin/number-calc-c-d" "./build/bin/number-calc-c-O0" "./build/bin/number-calc-c-O1")
joined_args=$(IFS=,; echo "${commands[*]}")
python3 stat.py "$joined_args"

tsc ./number_array/bunny-mark.ts
commands=("./build/bin/number-array-calc" "./build/bin/number-array-calc-js" "node ./number_array/bunny-mark.js"  "./build/bin/number-array-calc-c-d" "./build/bin/number-array-calc-c-O0" "./build/bin/number-array-calc-c-O1")
joined_args=$(IFS=,; echo "${commands[*]}")
python3 stat.py "$joined_args"

tsc ./class/bunny-mark.ts
commands=("./build/bin/number-class-calc" "./build/bin/number-class-calc-js" "node ./class/bunny-mark.js"  "./build/bin/number-class-calc-c-d" "./build/bin/number-class-calc-c-O0" "./build/bin/number-class-calc-c-O1")
joined_args=$(IFS=,; echo "${commands[*]}")
python3 stat.py "$joined_args"

# commands=("./build/bin/number-calc" "./build/bin/number-calc-js"  "./build/bin/number-calc-c-d" "./build/bin/number-calc-c-O0" "./build/bin/number-calc-c-O1")
# 
# times=()
# 
# for command in "${commands[@]}"; do
#     start=$(date +%s.%N)
#     $command
#     end=$(date +%s.%N)
#     execution_time=$(echo "scale=3; $end - $start" | bc)
#     times+=("$command $execution_time")
# done
# 
# echo "命令 执行时间"
# for time in "${times[@]}"; do
#     echo "$time"
# done

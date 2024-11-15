#!/bin/bash

tsc ./number/bunny-mark.ts
commands=("./build/bin/number-calc" "./build/bin/number-calc-js" "node ./number/bunny-mark.js"  "./build/bin/number-calc-c-d" "./build/bin/number-calc-c-O0" "./build/bin/number-calc-c-O1")
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

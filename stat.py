import time
import os
import sys
import pandas as pd

# 要执行的命令列表
# commands = ["./build/bin/number-calc", "./build/bin/number-calc-js", "./build/bin/number-calc-c-d", "./build/bin/number-calc-c-O0", "./build/bin/number-calc-c-O1"]
commands = sys.argv[1].split(',')

# 存储执行时间的数据结构
times = []

# 执行每个命令并记录时间
for command in commands:
    start_time = time.time()
    # 执行命令（这里可以使用 subprocess 模块来实际执行命令）
    # 这里只是模拟执行
    print(f"执行命令: {command}")
    # time.sleep(1)  
    os.system(command)
    end_time = time.time()
    execution_time = end_time - start_time
    times.append((command, execution_time))

# 创建数据框并展示统计表格
df = pd.DataFrame(times, columns=['命令', '执行时间（秒）'])
print(df)

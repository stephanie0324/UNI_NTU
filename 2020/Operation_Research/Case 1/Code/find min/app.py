from prerequisite import pre_output
from module3 import sum_of_month_lack
from pre import demand, csr, output
from check import *
from main import check_feasibility

import random, csv

days = 31
optimal_lack = 10000

for trial in range(10000000000000000000000):

    local_output = {}
    # swift 14 randomly to 1, 2, 3, 4
    for emp in output:
        temp = []
        for day in range(days + 1):
            if output[emp][day] == 14:
                temp.append(random.randint(1, 4))
            else:
                temp.append(output[emp][day])
        local_output[emp] = temp

    local_lack = sum_of_month_lack(local_output, days, demand)

    if local_lack < optimal_lack:
        optimal_lack = local_lack
        print(f"============================== Trial {trial} ==============================")
        print(local_output)
        print(local_lack)

        print(f"==============================      End      ==============================")

    if trial % 1000 == 0:
        print(f"****************************** Trial: {trial}")

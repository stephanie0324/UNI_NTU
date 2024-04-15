def sum_of_month_lack(output, days, demands):
    """
        input format:
            1. output ==> { employee_id: [ shift_id, ..., shift_id ] }
            2. days        ==> days of the month
            3. demands     ==> { date: [ demands_for_each_period, ..., demands_for_each_period ] }

        output: sum_of_lack<int>
    """
    lack_sum = 0

    for day in range(1, days + 1):
        daily_shifts = [] # record each day's shifts of all workers
        for emp in output:
            daily_shifts.append(output[emp][day])

        lack_sum += sum_of_daily_lack(daily_shifts, demands[day])

    return lack_sum

def sum_of_daily_lack(daily_shifts, daily_demand):
    daily_lack = 0
    for period in range(1, len(daily_demand) + 1):
        period_worker = worker_per_period(daily_shifts, period)
        period_lack = daily_demand[period - 1] - period_worker
        if period_lack > 0: daily_lack += period_lack

    return daily_lack


def worker_per_period(daily_shifts, period):
    worker_per_period = 0
    if period in range(1, 6):
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [1,2,3,4,5,7,8,9,10,11,12] else 0
    elif period == 6:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [1,2,3,4,5,7,8,9,10,12] else 0
    elif period == 7:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [2,3,4,5,8,9,10] else 0
    elif period == 8:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [3,4,9,10,11,13] else 0
    elif period == 9:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [1,4,7,10,11,12,13] else 0
    elif period == 10:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [1,2,6,7,8,11,12,13] else 0
    elif period == 11:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [1,2,3,6,7,8,9,11,12,13] else 0
    elif period in range(12, 16):
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [1,2,3,4,6,7,8,9,10,11,12,13] else 0
    elif period == 16:
        for shift in daily_shifts:
            worker_per_period += 1 if shift not in [-1,0,5,11,13] else 0
    elif period == 17:
        for shift in daily_shifts:
            worker_per_period += 1 if shift not in [-1,0,5,11,12,13] else 0
    elif period == 18:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [7,8,9,10,11,13] else 0
    elif period == 19:
        for shift in daily_shifts:
            worker_per_period += 1 if shift in range(7, 14) else 0
    elif period in range(20, 25):
        for shift in daily_shifts:
            worker_per_period += 1 if shift in [11,12,13] else 0

    return worker_per_period

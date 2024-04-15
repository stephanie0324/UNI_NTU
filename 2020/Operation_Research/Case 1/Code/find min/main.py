from function import senior_ratio, manager_count, check_shift_limit, check_leave_limit
from output import output

### Check Feasibility (Let Year = 2020)
def check_feasibility(output):

    ### Senior Ratio Request
    # Monday
    date = 2
    seniority = 1
    period = [20, 21, 22, 23, 24]
    while date <= 31:
        if senior_ratio(output, date, period, seniority) < 0.45:
            print("3/%d Monday False, Ratio: %.2f\n Return..." % (date, senior_ratio(output, date, period, seniority)))
            return False
        else:
            print("Senior Limit Check 3/%d Monday True" % date)
            date += 7

    # Wednesday Morning
    date = 4
    seniority = 2
    period = [1, 2, 3, 4, 5, 6]
    while date <= 31:
        if senior_ratio(output, date, period, seniority) < 0.55:
            print("3/%d Wednesday Morning False, Ratio: %.2f\n Return..." % (date, senior_ratio(output, date, period, seniority)))
            return False
        else:
            print("Senior Limit Check 3/%d Wednesday Morning True" % date)
            date += 7

    # Wednesday Night
    date = 4
    seniority = 1
    period = [20, 21, 22, 23, 24]
    while date <= 31:
        if senior_ratio(output, date, period, seniority) < 0.3:
            print("3/%d Wednesday Night False, Ratio: %.2f\n Return..." % (date, senior_ratio(output, date, period, seniority)))
            return False
        else:
            print("Senior Limit Check 3/%d Wednesday Night True" % date)
            date += 7

    # Thursday
    date = 5
    seniority = 2
    period = [20, 21, 22, 23, 24]
    while date <= 31:
        if senior_ratio(output, date, period, seniority) < 0.3:
            print("3/%d Thursday False, Ratio: %.2f\n Return..." % (date, senior_ratio(output, date, period, seniority)))
            return False
        else:
            print("Senior Limit Check 3/%d Thursday True" % date)
            date += 7

    # Friday
    date = 6
    seniority = 2
    period = [20, 21, 22, 23, 24]
    while date <= 31:
        if senior_ratio(output, date, period, seniority) < 0.3:
            print("3/%d Friday False, Ratio: %.2f\n Return..." % (date, senior_ratio(output, date, period, seniority)))
            return False
        else:
            print("Senior Limit Check 3/%d Friday True" % date)
            date += 7

    ### Manager Request
    # 3/1 Night
    date = 1
    if manager_count(output, date, 'night') < 1:
        return False
    # 3/10 Afternoon
    date = 10
    if manager_count(output, date, 'afternoon') < 2:
        return False
    # 3/15 Night
    date = 15
    if manager_count(output, date, 'night') < 1:
        return False
    # 3/22 Night
    date = 22
    if manager_count(output, date, 'night', True) < 1:
        return False
    # 3/29 Night
    date = 29
    if manager_count(output, date, 'night') < 1:
        return False

    ### Shift Limit
    id = 144
    date = 10
    request_shift = 5
    if check_shift_limit(output, date, id, request_shift) == False:
        print("Shift Limit Failed")
        print("Return ...")
        return False

    id = 98
    date = 17
    request_shift = 6
    if check_shift_limit(output, date, id, request_shift) == False:
        print("Shift Limit Failed")
        print("Return ...")
        return False

    id = 70
    date = 27
    request_shift = 13
    if check_shift_limit(output, date, id, request_shift) == False:
        print("Shift Limit Failed")
        print("Return ...")
        return False

    # print("Check Shift Limit Success...")

    ### Leave Limit
    id = 19
    date = [1,2,3]
    if check_leave_limit(output, date, id) == False:
        print("Leave Limit Failed")
        print("Return ...")
        return False

    id = 231
    date = [14]
    if check_leave_limit(output, date, id) == False:
        print("Leave Limit Failed")
        print("Return ...")
        return False

    id = 90
    date = [20]
    if check_leave_limit(output, date, id) == False:
        print("Leave Limit Failed")
        print("Return ...")
        return False

    id = 118
    date = [15]
    if check_leave_limit(output, date, id) == False:
        print("Leave Limit Failed")
        print("Return ...")
        return False

    id = 12
    date = [3]
    if check_leave_limit(output, date, id) == False:
        print("Leave Limit Failed")
        print("Return ...")
        return False

    id = 98
    date = [19,20]
    if check_leave_limit(output, date, id) == False:
        print("Leave Limit Failed")
        print("Return ...")
        return False

    id = 23
    date = [31]
    if check_leave_limit(output, date, id) == False:
        print("Leave Limit Failed")
        print("Return ...")
        return False

    print("    ==========================    \n    ========  己霸婚  ========\n    ==========================")
    return True

if __name__ == '__main__':
    check_feasibility(output)

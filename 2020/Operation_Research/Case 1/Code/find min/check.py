def check_legal_leaves(output, days):
    for emp in output:
        leave = 0
        for d in range(1, days + 1):
            if output[emp][d] == 0:
                leave += 1
        if leave != 8:
            print(f"FAIL ID = {emp}, leave days = {leave}")
            return False

    return True

def check_consecutive_workdays(output, days):
    for emp in output:
        conse = 0
        for d in range(1, days + 1):
            if output[emp][d] != 0:
                conse += 1
            else:
                conse = 0

            if conse > 7:
                print(f"FAIL ID = {emp}, conse days = {conse}, from 3/{d - conse} to 3/{d}")
                return False
    return True

def check_night_shift(output, days):
    for emp in output:
        for d in range(1, days + 1 - 7):
            night = 0
            for delta in range(6):
                if output[emp][d + delta] in [11,12,13]:
                    night += 1

            if night > 1:
                print(f"more than 1 night shift in consecutive 7 days! ID: {emp}, from 3/{d} to 3/{d + delta}, w/ {night} night shifts")
                return False

    return True

def check_afternoon_shift(output, days):
    for emp in output:
        for d in range(1, days + 1 - 7):
            afternoon = 0
            for delta in range(6):
                if output[emp][d + delta] in [7,8,9,10]:
                    afternoon += 1

            if afternoon > 2:
                print(f"more than 2 afternoon shifts in consecutive 7 days! ID: {emp}, from 3/{d} to 3/{d + delta}, w/ {afternoon} afternoon shifts")
                return False

    return True

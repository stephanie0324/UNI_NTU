from parameters import shift_table, csr

### 確認這個 Shift 裡面有沒有包含到那個時段
def shift_period_pair(shift, period):
    for i in shift_table[shift]:
        if i == period:
            return True
    return False

### 確認這些時段有沒有滿足 CSR Ratio
def senior_ratio(output, date, period, seniority):

    for p in period:
        total = 0
        senior = 0
        for person in output:
            sft = output[person][date] # get shift
            # if date == 25:
            #     print(sft, end = ' ')
            if shift_period_pair(sft, p) == True:
                total += 1

                if csr[person]['exp'] >= seniority:
                    senior += 1
    if total != 0:
        return senior / total
    else:
        return 0

### 找某日期某時段的 Assistant Manager/Manager 人數
def manager_count(output, date, shift_cat, no_assistant_manager = False):
    count = 0

    morning = [1,2,3,4,5,6]
    afternoon = [7,8,9,10]
    night = [11,12,13]

    for person in output:
        sft = output[person][date]
        # Morning
        if shift_cat == 'morning':
            for i in morning:
                if sft == i:
                    if csr[person]['pos'] == 'AM' or csr[person]['pos'] == 'MANA': # is manager or assistant manager
                        if no_assistant_manager == False or csr[person]['pos'] == 'MANA': # no_assistant_manager
                            count += 1
        # afternoon
        elif shift_cat == 'afternoon':
            for i in afternoon:
                if sft == i:
                    if csr[person]['pos'] == 'AM' or csr[person]['pos'] == 'MANA': # is manager or assistant manager
                        if no_assistant_manager == False or csr[person]['pos'] == 'MANA': # no_assistant_manager
                            count += 1
        # night
        elif shift_cat == 'night':
                for i in night:
                    if sft == i:
                        if csr[person]['pos'] == 'AM' or csr[person]['pos'] == 'MANA': # is manager or assistant manager
                            if no_assistant_manager == False or csr[person]['pos'] == 'MANA': # no_assistant_manager
                                count += 1

    return count

### Check Shift Limit
def check_shift_limit(output, date, id, request_shift):
    if output[id][date] != request_shift:
        print("ID: %d, 3/%d request for shift %d but get shift %d." % (id, date, request_shift, output[id][date]))
        return False
    return True

### Check Leave Limit
def check_leave_limit(output, date, id):
    ret = True
    for d in date:
        if output[id][d] != 0:
            print("ID: %d, 3/%d request for LEAVE but get shift %d." % (id, d, output[id][date]))
            ret = False
            
    return ret

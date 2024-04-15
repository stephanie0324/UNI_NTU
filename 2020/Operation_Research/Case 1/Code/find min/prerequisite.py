def pre_output(days):
    """
        table: { id: [shifts], ...,  }, -1
    """
    table = {}
    id = [12, 19, 20, 23, 30, 36, 37, 40, 45, 49, 69, 70, 72, 73, 74, 75, 84,
          90, 98, 118, 120, 121, 122, 129, 132, 136, 144, 158, 170, 171, 172,
          186, 190, 203, 208, 213, 231, 239, 241, 249 ]

    for emp in id:
        table[emp] = []
        for day in range(days + 1):
            # Leave Limit
            if emp == 12 and day == 3:            # 3/3
                table[emp].append(0)
            elif emp == 19 and day in [1, 2, 3]:  # 3/1 ~ 3/3
                table[emp].append(0)
            elif emp == 23 and day == 31:         # 3/31
                table[emp].append(0)
            elif emp == 90 and day == 20:         # 3/20
                table[emp].append(0)
            elif emp == 98 and day in [19, 20]:   # 3/19 ~ 3/20
                table[emp].append(0)
            elif emp == 118 and day == 15:        # 3/15
                table[emp].append(0)
            elif emp == 231 and day == 14:        # 3/14
                table[emp].append(0)
            # Shift Limit
            elif emp == 144 and day == 10:         # 3/10
                table[emp].append(5)
            elif emp == 98 and day == 17:         # 3/17
                table[emp].append(6)
            elif emp == 70 and day == 27:         # 3/27
                table[emp].append(13)
            else:
                table[emp].append(-1)

    return table

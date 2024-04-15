
param N; #Number of days in Month
param D{t in 1..24, j in 1..N};
param R{i in 0..13, j in 1..N};

var C {s in 35..45};
var B {s in 35..45};
var A {s in 35..45};
var x{i in 0..13, j in 1..N};
var y{t in 1..24, j in 1..N};
var w{t in 1..24, j in 1..N};
minimize lack: sum{t in 1..24, j in 1..N} w[t, j];
subject to offDays: sum{j in 1..N} x[0,j] = 8 * C;
subject to request {i in 0..13, j in 1..N}: x[i, j] >= R[i, j];
subject to afternoonShift:  sum{i in 7..10,j in 1..N} x[i, j] <= A;
subject to nightShift : sum{i in 11..13,j in 1..N} x[i, j] <= B;
subject to sevenDays {j in 1..N-6}: sum{k in j..j+6} x[0, k] >= C;
subject to dailyCSR {j in 1..N}: sum{i in 0..13} x[i, j]  = C;
subject to shift_1 {t in 1..5, j in 1..N}: (sum{i in 1..5} x[i, j]) + (sum{i in 7..12} x[i, j]) = y[t, j];
subject to shift_6 {j in 1..N}: (sum{i in 1..5} x[i, j]) + (sum{i in 7..10} x[i, j]) + x[12, j] = y[6, j];
subject to shift_7 {j in 1..N}: (sum{i in 2..5} x[i, j]) + (sum{i in 8..10} x[i, j])= y[7, j];
subject to shift_8 {j in 1..N}: (sum{i in 3..4} x[i, j]) + (sum{i in 9..11} x[i, j]) + x[13, j] = y[8, j];
subject to shift_9 {j in 1..N}: (sum{i in 10..13} x[i, j]) + x[1, j] + x[4, j] + x[7, j] = y[9, j];
subject to shift_10 {j in 1..N}: (sum{i in 1..2} x[i, j]) + (sum{i in 6..8} x[i, j]) + (sum{i in 11..13} x[i, j]) = y[10, j];
subject to shift_11 {j in 1..N}: (sum{i in 1..3} x[i, j]) + (sum{i in 6..9} x[i, j]) + (sum{i in 11..13} x[i, j]) = y[11, j];
subject to shift_12 {t in 12..15, j in 1..N}: (sum{i in 1..4} x[i, j]) + (sum{i in 6..13} x[i, j]) = y[t, j];
subject to shift_16 {j in 1..N}: (sum{i in 1..4} x[i, j]) + (sum{i in 6..10} x[i, j]) + x[12, j] = y[16, j];
subject to shift_17 {j in 1..N}: (sum{i in 1..4} x[i, j]) + (sum{i in 6..10} x[i, j]) = y[17, j];
subject to shift_18 {j in 1..N}: (sum{i in 7..11} x[i, j]) + x[13, j] = y[18, j];
subject to shift_19 {j in 1..N}: (sum{i in 7..13} x[i, j]) = y[19, j];
subject to shift_20 {t in 20..24, j in 1..N}: (sum{i in 11..13} x[i, j]) = y[t, j];
subject to lack_nonneg{t in 1..24, j in 1..N}: w[t, j] >= 0;
subject to lack_calculation{t in 1..24, j in 1..N}: w[t, j] >= D[t, j] - y[t, j];
subject to nonneg_1{i in 0..13, j in 1..N}: x[i, j] >= 0;
subject to nonneg_2{t in 1..24, j in 1..N}: y[t, j] >= 0;
subject to constraint_2: B = 4.43*C;
subject to constraint_3: A = B*2;
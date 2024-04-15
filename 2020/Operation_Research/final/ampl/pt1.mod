param M; #Number of Factory
param N; #Number of District
param C; #Transport Cost per mask per m
param D{i in 1..M, j in 1..N}; #Distance between Factory i and District j
param PA{j in 1..N}; #Adult Population in District j
param PY{j in 1..N}; #Children Population in District j
param A{i in 1..M}; #0 if cannot produce children mask, 1 if can
param S{i in 1..M}; #Production capacity in Factory i
param K; #factory maximum production

var XA{i in 1..M, j in 1..N}; #Number of Adult Mask produced by Factory i for District j
var XY{i in 1..M, j in 1..N}; #Number of Children Mask produced by Factory i for District j


minimize cost: sum{i in 1..M, j in 1..N} (XA[i, j] + XY[i, j]) * D[i, j] * C;

subject to factoryLimit {i in 1..M}: sum{j in 1..N} (XA[i, j] + XY[i, j]) = S[i]*100000;
subject to districtAdultRequirement {j in 1..N}: sum{i in 1..M} XA[i, j] <= PA[j];
subject to districtChildrenRequirement {j in 1..N}: sum{i in 1..M} XY[i, j] <= PY[j];
subject to factoryChildrenProductionCapability {i in 1..M}: sum{j in 1..N} XY[i, j] <= K * A[i];
subject to nonneg_1{i in 1..M, j in 1..N}: XA[i, j] >= 0;
subject to nonneg_2{i in 1..M, j in 1..N}: XY[i, j] >= 0;
subject to coverage_of_adult {j in 1..N}:        sum{i in 1..M} XA[i, j] / PA[j] >= 1/7;
subject to coverage_of_children {j in 1..N}:     sum{i in 1..M} XY[i, j] / PY[j] >= 1/7;

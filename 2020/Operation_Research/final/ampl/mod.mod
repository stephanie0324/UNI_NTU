## parameters ##
param M;                                                                        # Number of Factory
param N;                                                                        # Number of District
param C;                                                                        # Transport Cost per mask per m
param K;                                                                        # factory maximum production
param D{i in 1..M, j in 1..N};                                                  # Distance between Factory i and District j
param PA{j in 1..N};                                                            # Adult Population in District j
param PY{j in 1..N};                                                            # Children Population in District j
param PA_NORM{j in 1..N};                                                       # Adult Population in District j
param PY_NORM{j in 1..N};                                                       # Children Population in District j
param S{i in 1..M};                                                             # Production capacity in Factory i
param A{i in 1..M};                                                             # 0 if cannot produce children mask, 1 if can
param d{j in 1..N};                                                             # density in District j

## variables ##
var XA{i in 1..M, j in 1..N};                                                   # Number of Adult Mask produced by Factory i for District j
var XY{i in 1..M, j in 1..N};                                                   # Number of Children Mask produced by Factory i for District j
var rA;                                                         		# coverage of adult
var rY;                                                         		# coverage of children
var U{j in 1..N};                                                               # utility function
var cost;

var AdultMask{j in 1..N};                                                       # record all the adult masks supplied to town j
var ChildMask{j in 1..N};                                                       # record all the child masks supplied to town j

## objective functions ##
minimize total_cost: cost;

## constraints ##
subject to factoryLimit {i in 1..M}:                                            sum{j in 1..N} (XA[i, j] + XY[i, j] / 2) = S[i];
subject to districtAdultRequirement {j in 1..N}:                                sum{i in 1..M} XA[i, j] <= PA[j];
subject to districtChildrenRequirement {j in 1..N}:                             sum{i in 1..M} XY[i, j] <= PY[j];
subject to factoryChildrenProductionCapability {i in 1..M}:                     sum{j in 1..N} XY[i, j] <= 2*S[i] * A[i];
subject to nonneg_1 {i in 1..M, j in 1..N}:                                     XA[i, j] >= 0;
subject to nonneg_2 {i in 1..M, j in 1..N}:                                     XY[i, j] >= 0;
subject to coverage_of_adult {j in 1..N}:                                       rA[j] = sum{i in 1..M} XA[i, j] / (PA[j] + PY[j]);
subject to coverage_of_children {j in 1..N}:                                    rY[j] = sum{i in 1..M} XY[i, j] / (PY[j] + PA[j]);

# subject to utility_function{j in 1..N}:                                         U[j] = (rA[j] + rY[j] + d[j] + 0.0001) ** (1/3);
# subject to utility_function{j in 1..N}:                                         U[j] = (rA[j] + rY[j] + 0.001) ** (1/2) * d[j];
# subject to utility_function{j in 1..N}:                                         U[j] = ((PA_NORM[j] + PY_NORM[j]) * (rA[j] * rY[j]) * d[j] + 0.0000000000001) ** (1/4);
# subject to utility_function{j in 1..N}:                                         U[j] = ((rA[j] + 0.00001) ** (1/3) + (rY[j] + 0.00001) ** (1/3)) * (d[j] ** (1/3)) + (1/3) * (rY[j] + 0.00001) ** (1/3) * (rA[j] + 0.00001) ** (1/3) * (d[j] + 0.00001) ** (1/3);
subject to utility_function{j in 1..N}:                                         U[j] = ((PA_NORM[j] + PY_NORM[j]) * (rA[j] + rY[j]) * d[j] + 0.00000001) ** (1/3);

subject to adult_town_quant{j in 1..N}:                                         AdultMask[j] = sum{i in 1..M} XA[i, j];
subject to child_town_quant{j in 1..N}:                                         ChildMask[j] = sum{i in 1..M} XY[i, j];

subject to cost_of_maskXdistance:                                               sum{i in 1..M, j in 1..N} (XA[i, j] + XY[i, j]) * D[i, j] * C = cost;

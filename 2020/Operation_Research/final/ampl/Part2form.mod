## parameters ##
param M;                                                                        # Number of Factory
param N;                                                                        # Number of District
param C;                                                                        # Transport Cost per mask per m
param K;                                                                        # factory maximum production
param D{j in 1..M, i in 1..N};                                                  # Distance between Factory i and District j
param PA{j in 1..M};                                                            # Adult Population in District j
param PY{j in 1..M};                                                            # Children Population in District j
param S{i in 1..N};                                                             # Production capacity in Factory i
param A{i in 1..N};                                                             # 0 if cannot produce children mask, 1 if can
param d{j in 1..M};                                                             # density in District j
## variables ##
var XA{j in 1..M, i in 1..N};                                                   # Number of Adult Mask produced by Factory i for District j
var XY{j in 1..M, i in 1..N};                                                   # Number of Children Mask produced by Factory i for District j
var rA{j in 1..M};                                                              # coverage of adult
var rY{j in 1..M};                                                              # coverage of children
var U{j in 1..M};                                                               # utility function
## objective functions ##
maximize utility: sum{j in 1..M} U[j];
## constraints ##
subject to factoryLimit {i in 1..N}:                                            sum{j in 1..M} (XA[j, i] + XY[j, i] / 2) = S[i];
subject to districtAdultRequirement {j in 1..M}:                                sum{i in 1..M} XA[j, i] <= PA[j];
subject to districtChildrenRequirement {j in 1..N}:                             sum{i in 1..N} XY[j, i] <= PY[j];
subject to factoryChildrenProductionCapability {i in 1..N}:                     sum{j in 1..M} XY[j, i] <= 2*S[i] * A[i];
subject to nonneg_1 {j in 1..M, i in 1..N}:                                     XA[j, i] >= 0;
subject to nonneg_2 {j in 1..M, i in 1..N}:                                     XY[j, i] >= 0;
subject to coverage_of_adult {j in 1..M}:                                       rA[j] = sum{i in 1..N} XA[j, i] / PA[j];
subject to coverage_of_children {j in 1..M}:                                    rY[j] = sum{i in 1..N} XY[j, i] / PY[j];
# subject to utility_function{j in 1..M}:                                         U[j] = (rA[j] * rY[j] * d[j]) ** (1/3);
subject to utility_function{j in 1..M}:                                         U[j] = (rA[j] * rY[j] * d[j]);
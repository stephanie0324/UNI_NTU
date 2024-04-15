# Operation-Research-2020
## Week 1 (3/5)
    1. Case 1
    沒有使用任何演算法或是數學方法來做最佳化的排程
## Week 2 (3/12) - Linear Programming
    1. The Graphical Approach
    2. Three Types of Linear Program     
## Week 3 (3/19) - The simplex method
    1. The standard form
        * non-negative right hand side
        * non-negative variables
        * equality constraints (using slack var. to fill in the gaps)
    2. Basic solutions
        * bfs - basic feasible soultion 
        * adjacent bfs
    3. The simplex method
    4. The tableau represntation
        * maximization - negative numbers
        * minimization - positive numbers
    5. Unbounded LPs
    6.Infeasible LPs
## Week 4 (3/26) - Application of linear programming
    1. Material Blending
    2. Linearizing maximum/ minimum function
         * linearizing constraints
    3. AMPL
        * cd '' ;
        * model ;
        * data ;
        * solve ;

## Week 5 (4/9) - Linear Program Duality
     1. Primal-dual pairs
        * original -> primal , new -> dual
        * find upper bound
           < primal max => dual min >
                a. primal objectives  vs dual RHS
                    positive -> " >= " 
                    negatuve -> " <= "
                    free     -> " == "
                b. primal RHS => dual objectives
                    >= -> " <=0 "
                    <= -> " >=0 "
                    == -> free variable
            < primal min => dual max>
                all reverse
        * original -> primal , new -> dual
        * find upper bound
| obj.fun. | max | min | obj.fun. |
|---------:|----:|----:|---------:|
| constraints | <= | >=0 | variables |
|             | >= | <=0 |           |
|             | == | free |          |
| variables   | >=0 | >= | constraints |
|             | <=0 | <= |             |
|             | free | == |            |

     2. Duality theorems
     3. Shadow prices
     4. Case 2

## Week 6 (4/16) - Linear Relaxation
        1. Linear relaxation - resulting Lp after removing all the integer constraints.
            * solving IP(integer program)
                    > for minimization it provides lower bound
                    > for maximization it provides upper bound
        2. Branch and bound
        3. Ip formulation
## Week 7 (4/23) - Application of Integer Programming
        1. Facilities location problems 
            * maximum covering problem 
            * fixed charge location problem
        2. Machine scheduling problems
            * minimizing total tardiness(延遲) on a single machine
            * minimizing makespan on parrallel machines
        3. Vehicle routing problems
        
## Week 8 (4/30) - Non-Linear Programming
        1. Introduction
            * convex analytics
            * extreme points & optimal solutions
            * solving single variate NLP
        2. The EOQ model

## Week 9 (5/7) - Non-Linear Programming : Theory
        1. Multi-variateconvex analysis
            * gradient and hessian
            * positive-semi-definite
        2. Solving constrained NLP
            * Relaxation with rewards
            * Lagrangian relaxation
            * Lagrangian duality
        3. Application
            * multi-product EOQ problem
         
## Week 10 (5/14) - Multi-variate NLP : Alogorithms
    1. Overview
    2. Gradient descent
    3. Newton's method
       
## Week 11 (5/21) - Dynamic Programming
    1. Deterministic dynamic programming
    2. Stochastic dynammic programming

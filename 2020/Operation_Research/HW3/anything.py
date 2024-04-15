
#(1-2*a)**2+3*(1-5*a)**2-(1-2*a)*(1-5*a)-(1-2*a)-2*(1-5*a)

import numpy as np
from scipy.optimize import minimize

a =0
def objective(a):
    return (1-2*a)**2+3*(1-5*a)**2+(1-2*a)*(1-5*a)-(1-2*a)-2*(1-5*a)

sol = minimize(objective , a )

print(sol)

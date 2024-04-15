## Case 3 - Formulate a Integer Linear Program

### Decision Variables
* For each shift, for each day, we want to determine **how many CSRs** should be assigned to **that shift** on **that day**

### Objectives 
* **minimize the total lack** amount across all periods in the coming month

### Constraints
* Proxy of legal day off:  
  in total there should be **320 CSRs** asigned to **shift 0** in this month
* Proxy for shift requests:  
  at least **n CSRs** assigns to **shift k** corresponding to the request
* Proxy for leave requests:  
  at least **n CSRs** assigns to **shift 0** corresponding to the request
* Proxy for senior and manager limit:  
  ignore
* Proxy for night shift:  
  there can be at most **177 CSRs** assigned to **night shifts** in this month
* Proxy for afternoon shift:  
  there can be at most **354 CSRs** assigned to **afternoon shifts** in this month
* Proxy for days off after consecutive seven workdays:  
  there should be **at least 40 CSRs** assigned to **shift 0** for **every seven consecutive days**
  
### Tasks
1. Formulate the mathematical Integer Linear Program
2. AMPL or Gurobi for the LP
3. Summarize the result


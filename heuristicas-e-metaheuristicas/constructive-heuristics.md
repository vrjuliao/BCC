# Constructive Heuristics
Cormen et al., "Introduction to Algorithms", 2009: Chap 15 (15.1, 15.2, 15.3),
16 (16.1, 16.2) and 35 (35.1, 35.2, 35.3)\
Arts and Lenstra J. K.,"Local Search in Combinatorial Optimization", 
John Wiley and Suns, 1997: Chapter 8 ( 8.1 e 8.2)

Vinícius Julião Ramos - 2018054630

## 15 - Dynamic Programming (Cormen)
As well as Divide-and-conquer, Dynamic programming solves problems by combining
solutions of subproblems.
This approach consists of solving a problem just once, storing important values
for the case where the same operation would be requested.
But, as this operations was already computed before, dynamic programming 
algorithms just need to request the stored data, instead of calculating it 
again.
To develop a dynamic programming algorithm we need separate in four steps:
1. Characterize the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution, typically in a bottom-up fashion.
4. Construct an optimal solution from computed information.

### 15.1 - Rod cutting
This problem consists of, given a rod of length $n$ inches and a table of 
prices $p_i$ for $i=1,\ 2,\ 3,\ ...,\ n$ determine the maximum revenue price
$r_n$ obtainable by cutting up the road and selling the pieces.
An away to solve this problem is through recursive calls, where to calculate 
$r_n$ we need to calculate all combinations of possible rod lengths.
But when we don't choose use extra memory space, the cost is exponential, since
the $r_1$ calculus will be invoked $n$ times, $r_2$ invoked $n-1$ times, $r_3$ invoked $n-2$ ...
Then we will get an factorial cost.

Dynamic programming makes a **trade-off** between time and memory.
When the $i$-th revenue cost is calculated, the algorithms saves this value in
a array, so if $i+1$-th requests $r_i$, for getting the best combination 
between rod pieces, $r_i$ don't need to be recalculated since it was saved
previously.
Without this auxiliar memory, to get $r_{i+1}$ we need to calculate $r_i$ again,
even if this one was computed before.
So, dynamic programming depends on an auxiliar memory to save earlier-computed
data, and this memory can be full by two ways (**top-down** or **bottom-up**).

**Top-down**\
It consists in a approach so closed to the exponential-time algorithm, but the 
firsts line code of the function to compute `revenue_price(i)` check a global
array `r[i]` if the value of this revenue price is already saved.
Then we have:
```python
# auxiliar memory
r = [-1 for _ in range(n)]

# p = price table
# n = maximum size of the steel rod
def memorized_cut_rod(p, n):
  # if this value was computer before, then it shouldn't to be computed again
  if r[n] >= 0 return r[n]

  if n == 0:
    q = 0
  else:
    q = -1
    for i in range(n):
      q = max(q, p[i]+memorize_cut_rod(p, n))

  # Once this value is calculated, we save to prevent recalculation
  r[n] = q
  return q 
```

**Bottom-up**\
Using the **Top-down** approach, `r[i]` is calculated while this value is 
requested by the program.
In other words, the algorithm calculates `r[i]` if this one was not calculated 
before, so we can think in a recursion tree where the first value saved in 
`r[i]` is $i=1$ when the programs starts from `r[n]` and starts the recursion
until get the value for `r[1]`.
With the **Bottom-up** version, we consider that the smaller $i$-th values (for 
$i<n$) was calculated, thus it is not necessary navigates in such recursion,
just consulting the array instead.
Consequently we have:
```python
# auxiliar memory
r = [-1 for _ in range(n)]
r[0] = 0

# p = price table
# n = maximum size of the steel rod
def bottom_up_cut_rod(p, n):
  for i in range(n):
    q = -1
    for j in range(i):
      q = max(q, p[i]+r[i-j))

    # save the best value for r[i]
    r[i] = q

  return r[n]
```

In short, the to calcule `revenue_price(i)` we need to calculate every 
combination of revenue prices for indexes lower than $i$.
But with dynamic programming, this calculus is considered as subproblems, and
as this subproblem is solved (and saved) once, it should not be done again.

### 15.2 - Matrix-chain multiplication
Now, this problems want to solve a chain of matrixes multiplied each other.
So, given a sequence of matrixes $A_1,\ A_2,\ ..., A_n$, we want to get the 
product of this chain.
Since multiplication between matrixes is an associative operation, we don't
care with the order of multiplications.
Using a naïve way, considering that the matrices are compatible, we can yield
the product for a multiplication chain in $O(n^3)$, but it is possible to 
reduce the scalar cost of this multiplications by defining the operations
sequence.

**Example**\
Suppose three matrices $B_{10\times 100},\ C_{100\times 5}$ and
$D_{5\times 50}$.
If we execute a multiplication chain as $((B\times C)\times D)$ we compute 
$10\times 100\times 5 = 5000$ (at first multiplication) plus
$10\times 5 \times 50 = 2500$, totalizing 7500 multiplication operations.
But, if we decide to use this sequence of parenthesis> $(B\times(C\times D))$
we need $100\times 5\times 50 = 25,000$ operations, firstly, addded at
$10\times 100\times 50=50,000$ to yield the same result.
Thus, we can observe that it is possible to reduce the scalar cost of the
multiplications giving the best choice of parenthesis places.

So, we can define our problem as: given a chain of matrices to be multiplied,
return a fully parenthesized product of these matrices that minimizes the 
number of scalar multiplications.
It's important to say that for analyzing each parenthesis permutation, the 
cost is $\Omega(2^n)$.
To do solve that, using dynamic programming we shall divide our approach in 4
steps:
1. Characterize the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution.
4. Construct an optimal solution from computed information.

**A recursive solution**\
Firstly let us define an auxiliar memory to save the costs of each 
multiplication.
Let `m[i][j]` be a matrix to save the minimum number of scalar multiplications
of the matrix-chain: $A_i\times A_{i+1} \times ... \times A_j$.
For that, we shall consider that we are separating (inserting a parenthesis) at
the $k$ position, then two new matrices are produced: $A_{i...k}$ and
$A_{k+1...j}$.
This notation means $A_{i...j}$ a matrix obtained by the multiplication chain 
from $i$-th until $j$-th matrix.
So, as `m[i][j]` stores the minimum cost of the chain between $i...j$, when 
we split this chain at $k$ (such that $i\leq k <j$) the cost of `m[i][j]` is
given by the sum `m[i][k]` plus `m[k+1][j]` added to the cost of
$A_{i...k} \times A_{k+1...j}$.

Finally, `m[][]` helps us to get the best costs of each split without to 
recalculate it.
This data store is calculated by:
$$
m[i,\ j] = 
\begin{cases}
0 & \text{if } i=j,\\
\substack{\large{min}\\i\leq k<j}\normalsize\{m[i,\ k] + m[k+1,\ j]+ p_{i-1}
p_kp_j \}& \text{if } i<j.

\end{cases}
$$

**Computing the optimal costs**\
Our input is an array $p$ where the $A_i$ matrix dimensions are $p_{i-1}$ and 
$p_i$ elements.
Using a bottom-up approach to solve this problem, we can grant that the smaller
problems are being solved before to solve the bigger problems.
We start by calculating chains within two matrices, we know that a chain 
having just one element has cost equals to $0$.
After, we should to calculate chains with three elements, but a chain with 
three elements has an optimal chain with 2 matrices multiplied with a third 
matrix.
So, this optimal "2-chain" has its cost already calculated by the previous
iteration.
Consequently, we will calculates a chains iteratively, growing the size of this chains, and selecting the best parenthesis option according to smaller
chains.
Then, we have the following algorithm:
```python

#p => an array, p0 and p1 indicates that matrix A1 has dimensions (p0 x p1)
def matrix_chain_order(p):
  n = len(p)-1
  m = [list([0 for _ in range(n)]) for _ in range(n)]
  s = [list([0 for _ in range(n)]) for _ in range(n)]

  for l in range(2, n): # l => chain length
    for i in range(n-l+1):
      j = i+l-1
      m[i, j] = float("inf")
      for k in range(i, j):
        q = m[i][k] + m[k+1][j] + (p[i]*p[k]*p[j+1])
        if(q < m[i][j]):
          m[i][j] = q
          s[i][j] = k

  return m, s
```

**Constructing an optimal solution**\
Observe that our algorithm returns a matrix $s$, that compute the split index 
for each tuple $i,j$.
So, since we are interested in the complete expression, we can print this 
recursively by:
```python
# s[i, j] => returns the split index for the chain that starts with i
# and ends at j.
def print_optimal_parens(s, i, j):
  if i==j:
    print("A"+i)
  else
    print("(")
    print_optimal_parens(s, i, s[i][j])
    print_optimal_parens(s, s[i][j]+1, j)
    print(")")
```

### 15.3 - Elements of dynamic programming
A good question about dynamic programming is about when this approach applies.
To answer this question, we going to examine two key characteristics of **DP**
solutions for optimization problems: **optimal substructure** and 
**overlapping subproblems**.

#### **Optimal substructure**
For optimization problems, Dynamic Programming might be applied in problems 
which to solve an instance sizing $n$, it is necessary to solve the
sub-instances with $n-1$ elements.
When these subproblems are solved, we are solving an optimization problem for
a smaller instance, then we have an **optimal substructure**.
Once taking the optimal substructures, we can solve the whole problem.
There is a common pattern in optimal substructure problems, where it's possible
observe:

1. Choices with the combination of best sub-results should be made.
These choices leaves new subproblems to solve.
2. Getting the best choice of sub-results, you ensure that the parent problem
is being solved.
3. Choices allow decide which is the besto combination of sub-results.
4. Using the best coices along of the algorithm running, it ensures such 
combination is the correct result.
In other words, these choices select the optimal substructures.

To get the running time of a dynamic programming problem, we can illustrate
the algorithm with a directed graph.
The subproblems are nodes (the initial problem also is a subproblem from 
itself), and the edges indicate which subproblems an another subproblem must
consider to choose for producing the optimal substructure.
Observe that for a $n$-sizing **rod cutting**, we have $n-1$ subproblems to 
analyse before choose the best.
It means that we have an $O(n^2)$ running-time cost.
But in a $n$-sizing of **matriz chain multiplication**, we have $\Theta(n^2)$
subproblems, such that each node has $n$ edges (or $n$ subproblems to
consider).
Resulting in an $O(n^3)$ running-time cost.

#### **Overlapping subproblems**
Another scenario where dynamic programming might be used is when an algorithm
calls, recursively, the computation of the same subproblem more than once.
It spends an unnecessary execution time that could be avoided using space 
(memory), because if we saves the subproblem result at first time when this
one is solved, we don't need to solve it again since it is required.
We might check the memory instead.
This structure of recomputing the same subproblems is called 
**overlapping subproblems**.

----

## 16 - Greedy Algorithms (Cormen)
Contrary to dynamic programing, a greedy algorithm starts choosing the best
result at the moment, without check all combinations of choices.
This approach consider locally the best solution, differently dynamic 
programming needs a global checking of the best solution.
Greedy algorithms not always yield the optimal result, but for many problems
this kind of algorithms do.

### 16.1 An activity-selection problem
We can define this problem as an scheduling of competing activities that 
require exclusive use of a common resource, with a goal of selecting a 
maximum-size set of mutually compatible activities.
The **input** of this problem is an array $A$ with $n$ activities where each 
one is a tuple $a_i$ where $i\in [1,n]$.
Each $a_i$ contains two elements $s_i$ (start time) and $f_i$ (finish time) of 
the required time allocation to the resource.
It's important to say that the $A$ elements is increasingly sorted by the finish
time.
An expected **output** is a set $R$ with the maximum quantity of compatible 
activities.
First, we shall use dynamic programming to solve that, and we will observe that 
the best choices of subproblems are always the same choice that the greedy 
choice is capable to do.

#### **The optimal substructure of the activity-selection problem**
It's possible state that there is an optimal result $S$ which contains the 
maximum number of compatible activities $a_i$.
So, since we have an interval $S_{ij}$ that starts at time $i$ and finishes at 
time $j$, we shall find compatible activities within $S_{ij}$.
Supposing that $a_k$ is an activity of $S_{ij}$, an we choose $a_k$ as an 
element in the solution set $R_{ij}$, then we can get all other elements of
$R_{ij}$ through $R_{ik}\ \cup\ R_{kj}\ \cup\ \{a_k\}$.\
In short, considering $c[i,j]$ as our auxiliar memory of the dynamic 
programming algorithm, such that this memory is our storing $R_{ij}$, our 
recursive expression is:
$$
c[i,j] = 
\begin{cases}
  0 & \text{if } S_{ij} = \empty,\\

  {{\large\max} \atop a_k \in S_{ij}} \ \{c[i,k]+c[k,j]+1\} & \text{if }
  S_{ij} \neq \empty.\\
\end{cases}
$$

#### **Making the greedy choice**
Even though the dynamic programming algorithm choses the corrects activities and yield 
the correct answer $R$, checking globally the chooses might not be the fastest option.
Since we have the activities sorted by the finish time $f_i$, and using the difference
between the start time $s_i$, it's possible get activities smaller activities that
finish earlier.
Then, we could infer we are interested in earliest finishing activities that are 
compatible with each other.
In short, the last phrase defines our greedy choice, and since we have the $A$ array 
sorted by the finish time, we can check it linearly.

> The first element of $A$ always is in a maximum-size subset of mutually compatible
activities.

#### **A recursive greedy algorithm**
With the last statement, we can extract a recursive algorithm checking the "sufixes" of
$A$ which the first element is compatible with the last activity extracted from this 
one.
Then, we shall consider four arguments for our algorithm:
- $S$: We divided $A$ in two arrays, where $S$ represents the start time.
- $F$: On $A$ division, $F$ represents the finish time.
- $k$: The index of the last added element in the result.
- $n$: Size of $A$.

So, since the first element of $A$ is part of a solution of this problem, our initial
call is `recursive_activity_selector(S, F, 0, n)`.

```python 
def recursive_activity_selector(S, F, k, n):
  m = k+1
  while m <= n and S[m] < F[k]:
    m += 1

  if m <= n:
    new_activity = tuple(S[m], F[m])
    return [new_activity].join( recursive_activity_selector(S, F, m, n) )
```

#### **A iterative greedy algorithm**
Observing the greedy algorithm we can divide our iteration in two steps:
1. Get the first activity $a_j$ from $A$ that is compatible with the last added activity
in result array $R$, while $j < n$.
2. Add $a_j$ in result array and repeat the step.

```python
# the array $A is divided in $S (start) and $F (finish)
def greedy_activity_selector(S, F, n):
  last_added_element = (S[0], F[0])
  R = [last_added_element]
  j = 1
  for m in range(2, n):
    if S[m] >= F[j]:
      last_added_element = (S[m], F[m])
      R.append(last_added_element)
      j = m
  return R
```

Both in the iterative version or in recursive version, the time-complexity is 
$\Theta(n)$, but we should consider $A$ is sorted by the finish time.
When $A$ is unsorted, then our greedy algorithm must sort this one and it requires a 
time-complexity of $O(n\log_2n)$ plus $\Theta(n)$ from our array sweeping that checks
which element is added in $R$.
In short, we have $\Theta(n)$ when $A$ is sorted and $O(n\log_2n)$ in otherwise.

### 16.2 Elements of the greedy strategy
A greedy algorithm tries obtain an optimal solution by making a sequence of choices.
The best choices is made by the moment, instead of considering all possibilities.
It doesn't produce the correct answer for all problems, but as we saw in 
activity-selection problem, for some problems it does.
Then, now we will discuss about some general properties of greedy methods.
Generally, we follow three steps to design a greedy algorithm:
1. Cast the optimization problem as one in which we make a choice and are left with one 
subproblem to solve.
2. Prove that there is always an optimal solution that can be obtained by greedy 
choices.
3. Demonstrate an optimal substructure and show that it's possible get valid 
substructures by the greedy choices.

#### **Greedy-choice property**
We can define that as: the global choice made by considering the local values, without
checking subproblems results.
So, we don't need to revisit the subproblems solved before, since we just need to 
analyse if the following "sub-results" are pieces of the whole result.

#### **Optimal substructure**
A problem exhibits optimal substructure if an optimal solution to the problem contains 
within it optimal solutions to smaller problems.
As we have seen on activity-selector algorithm, our problem was reduced to determine the
first compatible element on an array $S_k$ where $a_k$ is the last added element in the
result array.
Then, out initial problem is determine the first element of the $A$ array, and $S_k$ is
a "sufix" of $A$ where we need to do the same checking than $A$.

#### **Greedy versus dynamic programming**
- 0-1 knapsack problem:\
  A thief robbing a store finds $n$ items.
  The ith item is worth $i$ dollars and weighs $w_i$ pounds, where $i$-th and $w_i$ are
  integers.
  The thief wants to take as valuable a load as possible, but he can carry at most $W$
  pounds in his knapsack, for some integer $W$.
  Which items should he take?


- Fractional knapsack problem:\
  The setup is the same, but the thief can take fractions of items, rather than having
  o make a binary (0-1) choice for each item.

In these two problems, the **Fractional knapsack problem** can be solved by the greedy 
strategy, but the same strategy cannot solve the **0-1** problem.
In this case, dynamic programming solves both problems.


## 35 - Approximation Algorithms (Cormen)
### 35.1 - The vertex-cover problem (Cormen)
### 35.2 - The traveling-salesman problem (Cormen)
### 35.3 - The set-covering problem (Cormen)
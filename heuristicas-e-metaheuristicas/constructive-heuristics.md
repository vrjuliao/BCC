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
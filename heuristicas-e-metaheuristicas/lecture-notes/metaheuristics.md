# Metaheuristics
El. Talbi, Metaheuristics: From Design to Implementation, 2009: Capítulos 2 e
3 (3.1 a 3.6)\
A history of metaheuristics

Vinícius Julião Ramos - 2018054630

## From Design to Implementation

### 2 Single-Solution Based Metaheuristics

S-metaheuristics  (single-solution based metaheuristics)
show the efficiency of a the solutions based on walks in tackling various
optimization problems in different domains.

#### 2.1 COMMON CONCEPTS FOR SINGLE-SOLUTION BASED METAHEURISTICS
S-metaheuristics iteratively apply the generation and replacement procedures
from the current single solution.
Given an solution $s$, a S-metaheuristics put that solution in a set of
solutions $C$ and verify which of these is the best.

**2.1.1 Neighborhood**\
- Neighborhood. A neighborhood function $N$ is a mapping $N : S \rightarrow$
$2^S$ that assigns to each solution $s$ of $S$ a set of solutions
$N(s)\subset S$.

**2.1.2 Very Large Neighborhoods**\
Most of the metaheuristics use small neighborhoods that is, in general,
a polynomial function of the input instance size.
The neighborhood is exponential if its size grows exponentially with the size
of the problem.
Then, the complexity of the search will be much higher.

**2.1.2.1 Heuristic Search in Large Neighborhoods**: This approach consists in
searching heuristically very large neighborhoods.
A partial set of the large neighborhood is generated.
Hence, finding the best neighbor is not guaranteed.

**2.1.2.2 Exact Search in Large Neighborhoods**: This approach consists in
searching exactly very large neighborhoods. The main goal is to find an
improving neighbor.
They are based on efficient procedures that search specific large (even
exponential) neighborhoods in a polynomial time.

**2.1.2.3 Polynomial-Specific Neighborhoods**: his strategy consists in
transforming the input instance into a specific instance that can be solved in
a polynomial manner.


**2.1.3 Initial Solution**:\
Two main strategies are used to generate the initial solution: a random and a
greedy approach.

**2.1.4 Incremental Evaluation of the Neighborhood**\
Often, the evaluation of the objective function is the most expensive part of 
a local search algorithm and more generally for any metaheuristic.
This is an important issue in terms of efficiency and must
be taken into account in the design of an S-metaheuristic.
A more efficient way to evaluate the set of candidates is the evaluation
$\Delta(s, m)$ of the objective function when it is possible to compute, where
$s$ is the current solution and $m$ is the applied move.

#### 2.2 FITNESS LANDSCAPE ANALYSIS
The main point of interest in the domain of optimization must not be the 
design of the best algorithm for all optimization problems but the search for
the most adapted algorithm to a given class of problems and/or instances.
The analysis of landscapes of optimization problems is an important aspect in
designing a metaheuristic.

**2.2.1 Distances in the Search Space**:\
Let $d(s i , s j )$ be the distance between solutions $s_i$ and $s_j$ in the
search space.
It is defined as the length of the shortest path in the graph G; that is, the 
minimum number of application of the move operator to obtain the solution $s_j$ from the solution $s_i$.

**2.2.2 Landscape Properties**:
- Global indicators: Global approaches provide information about the structure
  of the entire landscape.
- Local indicators: The local approach consists in characterizing a local view
  of the landscape as explored by a metaheuristic.

**2.2.2.1 Distribution Measures**: The objective of the distribution measures 
is the distribution analysis of the local optimal solutions in the landscape
projected both in the search space $G$ and in the objective space $f$.

**2.2.2.2 Correlation Measures**: The objective of correlation measures is to
estimate the ruggedness of the landscape along with the correlation between the
quality of solutions and their distance to a global optimal solution.

**2.2.3 Breaking Plateaus in a Flat Landscape**:\
One such strategy consists in changing the objective function. The objectiv
function is generally defined rather straightforward in problem solving: it is
simply the value of the utility function to optimize.
For some problems, embedding more information in the objective function leads
to a significant improvement in the quality of the solutions that are reached.

#### 2.3 LOCAL SEARCH
Local search is likely the oldest and simplest metaheuristic method. 
It starts at a given initial solution. At each iteration, the heuristic
replaces the current solution by a neighbor that improves the objective
function.

**2.3.1 Selection of the Neighbor**\
Strategies to choose a next neighbor:
- Best improvement (steepest descent): In this strategy, the best neighbor
  (i.e., neighbor that improves the most the cost function) is selected.
- First improvement: This strategy consists in choosing the first improving
  neighbor that is better than the current solution.
- Random selection: In this strategy, a random selection is applied to those
  neighbors improving the current solution

**2.3.2 Escaping from Local Optima**\
One of the main disadvantages of local search is that it converges toward
local optima.
Local search works well if there are not too many local optima in the search
space or the quality of the different local optima is more or less similar.
Many alternatives algorithms have been proposed to avoid becoming stuck at
local optima.
Four different families of approaches can be used to avoid it:
- Iterating from different initial solutions: This strategy is applied in 
  multi-start local search, iterated local search, GRASP, and so forth.
- Accepting nonimproving neighbors: These approaches enable moves that
  degrade the current solution.
- Changing the neighborhood: This class of approaches consists in changing the
  neighborhood structure during the search.
- Changing the objective function or the input data of the problem: In this
  class, the problem is transformed by perturbing the input data of the
  problem, the objective function or the constraints, in the hope to solve
  more efficiently the original problem.

### 2.4 SIMULATED ANNEALING
SA had a major impact on the field of heuristic search for its simplicity and
efficiency in solving combinatorial optimization problems.
Then, it has been extended to deal with continuous optimization problems.

#### 2.5 TABU SEARCH

The use of memory, which stores information related to the search process,
represents the particular feature of tabu search.
TS behaves like a steepest LS algorithm, but it accepts nonimproving solutions
to escape from local optima when all neighbors are nonimproving solutions.
Usually, the whole neighborhood is explored in a deterministic manner, whereas
in SA a random neighbor is selected.
As in local search, when a better neighbor is found, it replaces
the current solution. When a local optima is reached, the search carries on by 
selecting a candidate worse than the current solution.
The best solution in the neighborhood is selected as the new current solution 
even if it is not improving the current solution.

In addition to the common design issues for S-metaheuristics such as the
definition of the neighborhood and the generation of the initial solution, the
main design issues that are specific to a simple TS are:
- Tabu list: The goal of using the short-term memory is to prevent the search
  from revisiting previously visited solutions.
- Aspiration criterion: A commonly used aspiration criteria consists in
  selecting a tabu move if it generates a solution that is better than the
  best found solution.

#### 2.6 ITERATED LOCAL SEARCH
The quality of the local optima obtained by a local search method depends on
the initial solution.
As we can generate local optima with high variability, iterated local search
may be used to improve the quality of successive local optima.

#### 2.7 VARIABLE NEIGHBORHOOD SEARCH
The basic idea of VNS is to successively explore a set of predefined
neighborhoods to provide a better solution. It explores either at
random or systematically a set of neighborhoods to get different local optima
and to escape from local optima. 
VNS exploits the fact that using various neighborhoods in local
search may generate different local optima and that the global optima is a
local  optima for a given neighborhood.

#### 2.8 GUIDED LOCAL SEARCH
Its adaptation to continuous optimization problems is straightforward given
that GLS sits on top of a local search algorithm.
The features of the obtained local optima are used to transform the objective
function.

### 3 Population-Based Metaheuristics

#### 3.2 EVOLUTIONARY ALGORITHMS
EAs are based on the notion of competition. They represent a class of
iterative optimization algorithms that simulate the evolution of species
They are based on the evolution of a population of individuals.
Initially, this population is usually generated randomly.
Every individual in the population is the encoded version of a tentative
solution.
An objective function associates a fitness value with every individual
indicating its suitability to the problem.
At each step, individuals are selected to form the parents, following the
selection paradigm in which individuals with better fitness are selected with
a higher probability.
Then, selected individuals are reproduced using variation operators to
generate new offsprings.
Finally, a replacement scheme is applied to determine which individuals of
the population will survive from the offsprings and the parents.
This iteration represents a generation.

**3.2.1 Genetic Algorithms**:\
raditionally, GAs are associated with the
use of a binary representation but nowadays one can find GAs that use other
types of representations.
A GA usually applies a crossover operator to two solutions that plays a major
role, plus a mutation operator that randomly modifies the individual contents
to promote diversity.

**3.2.2 Evolution Strategies**:\
ESs are mostly applied to continuous optimization where representations are
based on real-valued vectors.
Crossover is rarely used.
In an ES, there is a distinction between the population of parents of size
$\mu$ and the population of the offsprings of size $\lambda \geq \mu$.
An individual is composed of the float decision variables plus some other
parameters guiding the search.
Thus, an ES facilitates a kind of self-adaptation by evolving the solution as
well as the strategy parameters.

**3.2.3 Evolutionary Programming**:\
Evolutionary programming emphasizes on mutation and does not use recombination.
Traditional EPs have been developed to evolve finite state machines to solve
time series prediction problems and more generally to evolve learning machines.
They use normally distributed mutations and self-adaptation principle of the
parameters as in ESs.

#### 3.5 SCATTER SEARCH
SS is a deterministic strategy that has been applied successfully to some
combinatorial and continuous optimization problems.
SS is a evolutionary and population metaheuristic that recombines solutions
selected from a reference set to build others.
The method starts by generating an initial population Pop satisfying the
criteria of diversity and quality.
The reference set (RefSet) of moderate size 13 is then constructed by
selecting good representative solutions from the population.
The selected solutions are combined to provide starting solutions to an
improvement procedure based on a S-metaheuristic.
According to the result of such procedure, the reference set and even the
population of solutions are updated to incorporate both high-quality and
diversified solutions.
The process is iterated until a stopping criterion is satisfied.

#### 3.6 SWARM INTELLIGENCE
Swarm intelligence originated from the social behavior of those species that
compete for foods.
The main characteristics of swarm-intelligence-based algorithms are particles
are simple and nonsophisticated agents, they cooperate by an indirect
communication medium, and do movements in the decision space

**3.6.1 Ant Colony Optimization Algorithms**:\
ACO algorithms mimic the principle that using very simple communication
mechanism, an ant colony is able to find the shortest path between two points.


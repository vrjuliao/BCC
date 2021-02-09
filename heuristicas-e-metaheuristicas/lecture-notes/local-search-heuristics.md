# Local Search Heuristics

E. Talbi, "Metaheuristics: From Design to Implementation", Chapter 1\
Aarts e Lenstra, "Local Search in Combinatorial Optimization", 1997: Chapter
8.3

Vinícius Julião Ramos - 2018054630


## Metaheuristics: From Design to Implementation

The word heuristic has its origin in the old Greek word heuriskein, which means
the art of discovering new strategies (rules) to solve problems. The suffix meta, also
a Greek word, means “upper level methodology.”

### 1.1 Optimization models
Decision making consists in the following steps:
- Formulate the problem: In this first step, a decision problem is identified.
- Model the problem: In this important step, an abstract mathematical model
is built for the problem.
- Optimize the problem: Once the problem is modeled, the solving procedure
generates a “good” solution for the problem.
- Implement a solution: The obtained solution is tested practically by the decision
maker and is implemented if it is “acceptable”.

#### **1.1.1 Classical optimization models**
Global optimum. A solution $s∗ \in S$ is a global optimum if it
has a better objective function than all solutions of the search space, that is,
$\forall s \in S, f (s∗ ) \leq f (s)$.
A commonly used model in mathematical programming is linear programming
(LP).

Nonlinear programming models (NLP) deal with mathematical programming
problems where the objective function and/or the constraints are nonlinear.
Nonlinear continuous models are, how-
ever, much more difficult to solve, even if there are many modeling possibilities that
may be used to linearize a model.
In an integer program optimization
model, the decision variables are discrete.
When the decision variables are both discrete and continuous, we are dealing
with mixed integer programming problems.
Notice that there are some easy problems, such as network flow problems, where
linear programming automatically generates integer values.
A more general class of integer programming problems is combinatorial optimization problems.
Another common approach to model decision and optimization problems is constraint programming, a 
programming paradigm that integrates richer modeling
tools than the linear expressions of MIP models.


#### **1.2.1 Optimization Under Uncertainty**
In many concrete optimization problems, the input data are subject to noise. There
are various sources of noise.

#### **1.2.2 Dynamic Optimization**
Dynamic Optimization problems represent an important challenge in many real-life
applications. The input elements of the problem change over time. In dynamic optimization problems, 
the objective function is deterministic at a given time but varies
over the time.

##### **1.2.3 Robust Optimization**
In many optimization problems, the decision variables or the environmental variables
are perturbed or subject to change after a final solution has been obtained and implemented for the 
problem. Hence, in solving the problem we have to take into account
that a solution should be acceptable with respect to slight changes of the decision
variable values. The term robust qualifies those solutions.

### 1.3 OPTIMIZATION METHODS
#### **1.3.1 Exact Methods**

In the class of exact methods one can find the following classical algorithms: dynamic
programming, branch and X family of algorithms (branch and bound, branch and
cut, branch and price) developed in the operations research community, constraint
programming, and A∗ family of search algorithms.

#### **1.3.2 Approximate Algorithms**
In the class of approximate methods, two subclasses of algorithms may be distinguished: approximation 
algorithms and heuristic algorithms. Unlike heuristics, which
usually find reasonably “good” solutions in a reasonable time, approximation algorithms provide 
provable solution quality and provable run-time bounds.

#### **1.3.3 Metaheuristics**

Unlike exact methods, metaheuristics allow to tackle large-size problem instances by
delivering satisfactory solutions in a reasonable time. There is no guarantee to find
global optimal solutions or even bounded solutions.
Many classification criteria may be used for metaheuristics:
- Nature inspired versus nonnature inspired: Many metaheuristics are inspired
by natural processes: evolutionary algorithms and artificial immune systems
from biology.
- Memory usage versus memoryless methods: Some metaheuristic algorithms
are memoryless; that is, no information extracted dynamically is used during
the search.
- Deterministic versus stochastic: A deterministic metaheuristic solves an
optimization problem by making deterministic decisions.
- Population-based search versus single-solution based search: Single-solution
based algorithms manipulate and transform
a single solution during the search while in population-based algorithms
a whole population of solutions is evolved.
- Iterative versus greedy: In iterative algorithms, we start with a complete
solution and transform it at each iteration using some
search operators. Greedy algorithms start from an empty solution, and at each
step a decision variable of the problem is assigned until a complete solution is
obtained

#### **1.3.5 When Using Metaheuristics?**
Even if a problem is NP-hard, small instances may be
solved by an exact approach. Moreover, the structure of the instances plays an
important role. Some medium- or even large-size instances with a specific structure
may be solved in optimality by exact algorithms. Finally, the required search time
to solve a given problem is an important issue in the selection of an optimization
algorithm.

Many combinatorial optimization problems belong to the NP-hard class of prob-
lems. This high-dimensional and complex optimization class of problems arises in
many areas of industrial concern.

Metaheuristics and IP/MIP problems: Despite the advances in reformulating IP
and MIP models, and the development of new efficient procedures such as cutting
planes and column generation, IP and MIP problems remain difficult to solve for
moderate and large instances in a reasonable time.

Metaheuristics and CP: As for MIP models, constraint programming techniques
enable to solve small instances of CP models in an optimal manner within a reasonable
period of time.

For nonlinear continuous (NLP) optimization, metaheuristics should be applied, if
derivative-based methods, for example quasi-Newton method or conjugate gradient,
fail due to a rugged search landscape

### 1.4 MAIN COMMON CONCEPTS FOR METAHEURISTICS

**1.4.1.1 Linear Representations Linear** representations may be viewed as
strings of symbols of a given alphabet.

**1.4.1.2 Nonlinear Representations Nonlinear** encodings are in general more
complex structures. They are mostly based on graph structures. Among the traditional
nonlinear representations, trees are the most used.

**1.4.1.3 Representation-Solution Mapping** The representation-solution
mapping function transforms the encoding to a problem solution.
The mapping between the solution space and the encoding space
involves three possibilities.

**1.4.1.4 Direct Versus Indirect Encodings** When using an indirect
representation, the encoding is not a complete solution for the problem. A decoder is required
to express the solution given by the encoding. According to the information that is
present in the indirect encoding, the decoder has more or less work to be able to derive
a complete solution.

#### **1.4.2 Objective Function**

**1.4.2.1 Self-Sufficient Objective Functions**: For some optimization 
problems, the definition of the objective function is straightforward.

**1.4.2.2 Guiding Objective Functions**: For other problems, the definition of
the objective function is a difficult task and constitutes a crucial question. The objective
function has to be transformed for a better convergence of the metaheuristic. The new
objective function will guide the search in a more efficient manner.

**1.4.2.3 Representation Decoding**: The design questions related to the definition
of the representation and the objective function may be related. In some problems,
the representation is decoded to generate the best possible solution.

**1.4.2.4 Interactive Optimization** In interactive optimization, the user is 
involved online in the loop of a metaheuristic.

**1.4.2.5 Relative and Competitive Objective Functions**: In some problems,
it is impossible to have an objective function f that associates an absolute value
with all solutions.

**1.4.2.6 Meta-Modeling**: It is well known that most of the time, in
metaheuristics, the time-intensive part is the evaluation of the objective function. In many
optimization problems, the objective function is quite costly to compute. The 
alternative to reduce this complexity is to approximate the objective function and
then replace the original objective function by its approximation function.

### 1.5 CONSTRAINT HANDLING
Dealing with constraints in optimization problems is another important topic for the
efficient design of metaheuristics. Indeed, many continuous and discrete optimization
problems are constrained, and it is not trivial to deal with those constraints.

#### **1.5.1 Reject Strategies**
Reject strategies represent a simple approach, where only feasible solutions are kept
during the search and then infeasible solutions are automatically discarded.

#### **1.5.2 Penalizing Strategies**
In penalizing strategies, infeasible solutions are considered during the search process.
The unconstrained objective function is extended by a penalty function that will
penalize infeasible solutions. This is the most popular approach.

#### **1.5.3 Repairing Strategies**
Repairing strategies consist in heuristic algorithms transforming an infeasible
solution into a feasible one. A repairing procedure is applied to infeasible solutions to
generate feasible ones. For instance, those strategies are applied in the case where
the search operators used by the optimization algorithms may generate infeasible
solutions.

#### **1.5.5 Preserving Strategies**
In preserving strategies for constraint handling, a specific representation and operators
will ensure the generation of feasible solutions. They incorporate problem-specific
knowledge into the representation and search operators to generate only feasible
solutions and then preserve the feasibility of solutions.

### 1.6 PARAMETER TUNING
Parameter tuning may allow a
larger flexibility and robustness, but requires a careful initialization. Those parameters
may have a great influence on the efficiency and effectiveness of the search.

#### **1.6.1 Off-Line Parameter Initialization**
As previously mentioned, metaheuristics have a major drawback; they need some
parameter tuning that is not easy to perform in a thorough manner. Those 
parameters are not only numerical values but may also involve the use of search
components.

#### **1.6.2 Online Parameter Initialization**
The drawback of the off-line approaches is their high computational cost, particularly
if this approach is used for each input instance of the problem. Indeed, the optimal
values of the parameters depend on the problem at hand and even on the various
instances to solve. Then, to improve the effectiveness and the robustness of off-line
approaches, they must be applied to any instance (or class of instances) of a given
problem.

### 1.7 PERFORMANCE ANALYSIS OF METAHEURISTICS
- Experimental design: In the first step, the goals of the experiments, the selected
instances, and factors have to be defined.
- Measurement: In the second step, the measures to compute are selected. 
- Reporting: Finally, the results are presented in a comprehensive way, and an
analysis is carried out following the defined goals.

#### **1.7.1 Experimental Design**
In the computational experiment of a metaheuristic, the goals must be clearly defined.
All the experiments, reported measures, and statistical analysis will depend on the
purpose of designing the metaheuristic. Indeed, a contribution may be obtained for
different criteria such as search time, quality of solutions, robustness in terms of the
instances, solving large-scale problems, parallel scalability in terms of the number of
processors, easiness of implementation, easiness to combine with other algorithms,
flexibility to solve other problems or optimization models, innovation using new
nature-inspired paradigms, automatic tuning of parameters, providing a tight
approximation to the problem, and so on.

#### **1.7.2 Measurement**
**1.7.2.1 Quality of Solutions**: Performance indicators for defining the quality
of solutions in terms of precision are generally based on measuring the distance or the
percent deviation of the obtained solution to one of the solutions.

**1.7.2.2 Computational Effort**: The efficiency of a metaheuristic may be
demonstrated using a theoretical analysis or an empirical one. In theoretical analysis,
the worst-case complexity of the algorithm is generally computed.

**1.7.2.3 Robustness**: In general, robustness is
insensitivity against small deviations in the input instances or the parameters of
the metaheuristic. The lower the variability of the obtained solutions the better the
robustness

**1.7.2.4 Statistical Analysis** Once the experimental results are obtained for
different indicators, methods from statistical analysis47 can be used to conduct the
performance assessment of the designed metaheuristics.


#### **1.7.3 Reporting**
The interpretation of the results must be explicit and driven using the defined goals
and considered performance measures. In general, it is not sufficient to present the
large amount of data results using tables. Some visualization tools to analyze the data
are welcome to complement the numerical results 
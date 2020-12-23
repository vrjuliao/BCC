# Complexity Theory
Cormen et al., "Introduction to Algorithms", 2009: Chapters 1, 2, 3 e 34 (34.1 e 34.2)

Vinicius Julião Ramos - 2018054630

## 1 - The Role of Algorithms in Computing

### 1.1 Algorithms
Informally, an algorithm is any well-defined procedure that has an **input**
(could be empty, unique or a set of elements) and using this input, produces
an **output**.
So, algorithm is a sequence of steps, that use the input to produce some output.

Given some problem specification, an algorithm can be described by a
computational procedure for achieving the expected result.
The **input** is called an **instance** of the problem.

An algorithm is said to be **correct** if, for every **instance**, it produces
the correct **output**.
An incorrect algorithm is when an algorithm don't produce the correct
**output** for all **instances**, but incorrect algorithms cam be useful when
we control the error rate.

**Data Structures** \
It is a way to store an organize data in order to facilitate access and
modifications.
Each data structure has a scenario to be applied, so it is important to know
the strengths and limitations of each used data structure.

**Hard problems**\
Hard problems are measured by time efficiency.
In other words: how many time is spent to solve the problem, but this is not
a clock time.
Here, the smallest unity of time is the time spent to compute the fastest
computational operation.

There are classes of problems that nobody has proven if an efficient
algorithm exists or not.
Further more, the NP-Complete class have the property where if one
NP-Complete problem has an efficient algorithm, then the whole NP-Complete
class has an efficient algorithm.
But nowadays, NP-complete is a class with hard problems.

**Parallelism**\
Currently, processors have more than one core.
This means that a current processor is a set of processors (cores), and we can
paralelize the execution of a program.
Or else, multiple programs can be executed at the same time using a multi-core
processor.
With this new technology, we can develop parallel algorithms to perform and
improve the execution, in other words, just one algorithm can solve two problems
at the same time.

### 1.2 Algorithm as a technology
In a imaginary world, we can think in computers infinitely fast with an infinite
memory where any algorithm can execute.
But in the real world, we have a bounded memory computers with fast processors
(even though it is not infinitely fast).
Thus, to create an efficient algorithm, we need to consider the execution time
with de memory usage before to design an algorithm.

**Efficiency**\
There are so many ways to solve the same problem.
These ways have different timing execution costs that make one solution better
than other (or more efficient).
For instance, using the sorting problem for $n$ elements, there is algorithms
that sort these elements with an time order of $n^2$, but others solutions
can sort the $n$ elements with $n \log_2{n}$ operations.

**Algorithms and other technologies**\
As well as hardware, softwares can implement new technologies.
This technologies not implies just as a new user interface or a new utility,
but if a software uses an algorithm with an cost of $n^2$ and a new solution
for the same problem was developed executing in a time of $n \log_2n$, then
the software will receive a new technology.
Thus, we can consider algorithms as technologies.

## 2 - Getting Started
This chapter introduces sorting algorithms for explaining and analyze the role
of each sorting approach.
The execution time is also analyze for these approaches and using *pseudocodes*
it shall show how to confirm the correctness for algorithms.
Lastly, the divide-and-conquer approach is introduced to show the merge sort
algorithm.

### 2.1 - Insertion Sort
**Input**: A sequence of $n$ numbers $\{a_1, a_2, ..., a_n\}$\
**Output**: A permutation (reordering) of the **Input** sequence
$\{a'_1, a'_2, ..., a'_n\}$ where $a'_1 \leq a'_2 \leq ... \leq a'_n$.

**Insertion sort** is an efficient algorithm for small sequences of numbers.
This solution can be simulated by a set of cards in a hand: If the player wants
to sort the cards, (s)he select one-by-one and switch the card place.
The cards set is separated in two groups: **left** and **right**.
**Left** is the sorted group and **right** has the card that shall be inserted
in **left** one.
After that, the **left** has 2 cards and **right** has one less card.
Then, one more card from **right** shall be removed and inserted in the correct
position in **left**.
That process is repeated until right group to be empty.

**Loop invariants and the correctness of insertion sort**\
It is used to show the correctness of this sorting solution.
Three things must be presented:
1. Initialization: The **left** group starts with the most left card on the hand.
then, with 1 card, the left group is always sorted.
2. Maintenance: For each insertion in **left** the group must keep sorted, then
it the algorithm will check the correct position where the card will be
inserted.
3. Termination: The result should grant that the array of elements is sorted.
The goal of this algorithm is clear **right** and put all elements in **left**,
but with the second step (**Maintenance**) we know that **left** is always
sorted.
Finally, when **right** is clear it means that **left** contains every element
of **right**, then if the algorithm return **left** at the final, we can
confirm the result is correct.

**Pseudocode conventions**
- Indentation indicates block structures.
- Loops are represented by **for**, **while** and **repeat-unil** key words.
These structures contains implicitly an **if** condition.
The **if-else** statements have the same interpretation of C/C++.
- The "//" symbol indicates a comment.
- A multiple assignment like `i = j = 1` should be interpreted as `i` and `j`
is receiving `1` value.
- Global variables have explicit declaration. Then, intern variables don't carry
about initialization.
- Elements in arrays (or in some data structures that can be accessed by a key)
is accessed by the variable name of this array followed by the index/key
inside square brackets.
- The keyword **error** indicates that some condition or procedure was not
satisfied, so the algorithm execution will be stopped.

### 2.2 - Analyzing algorithms

There are so many concerns to consider in a computer like memory, bandwidth,
or hardware for instance.
But in general, we are worrying with the time execution of an algorithm to
compare two (or more) different ones for a single solution.
The time analysis consider a theoretical computer, with one processor where
commands are executed one after another.
This model of computer is compatible with existing computer, so the available
instructions are the same instructions that can be executed in a current
processor.
Once the main worry is time execution, the memory hierarchy is not a problem,
because this approach just consider the existence of a memory.

**Analyzing insertion sort**\
Execution time is expressed by a function given according to the size of the
**Input**.
That means the time spent to sort an array of elements using **Insertion sort**
depends on the quantity of elements in this array.
So, the time analysis will produce a function $f(n)$ where $n$ is the size of
the array.
Further more, when we are analyzing another algorithm, $f$ can be produced
considering other factors; for instance, in a graph we can analyze the
execution time complexity using the quantity of edges ($e$) and vertexes ($v$).
Then this graph algorithm can have a time execution expressed by $f(e,v)$.

Some pieces of code, demands a constant time of execution.
This pieces are a sequence of instructions that requires a theoretical time
execution equals to 1.
Because of that, for pieces of code with a constant execution time, we are
commonly no worried about this constant is big or small.
So, we can say that code requires a 1 of time execution (even if the constant
is so big).
Looking for the **Insertion sort** algorithm it has a sequence a constant time
execution code inside two **for** loops.
The most inter loop compare elements for **right** against **left**, then one
by one, **right** elements are compared with all of **left** elements.
Since **left** is increased on the hand of the most external loop executes,
the constant time code run once at the first loop, twice at the second loop,
three times at the third loop until $n$.

With this behavior, the constant time code run $1+2+3+...+n$ times.
In other words, $f(n) = \sum_{i=1}^ni = \frac{n^2+n}{2}$.
It means we have a behavior where the time execution of **Insertion sort** grows
like a square function.
Finally, we can summarize that how much elements the array have, the time spent
to sort this elements is equals to a square quantity of constant instructions.
Lastly, our analysis considers just the case where the loop always occurs, but
the most external loop of our **Insertion sort** algorithm never execute when
the array is already sorted.
Because of that we need to make a more concise approach, considering other
permutation cases.
We can do that using the worst-better-and-medium cases analysis.

**Worst-case and average-case analysis**\
Worst-case occurs when the **input** requires the maximum of the time execution
for resulting the correct **output**.
In **Insertion sort** the worst case is given by an inverse sorted array, since
this organization of elements get the maximum of comparisons and elements
switching to yield the correct sort ordering.
The worst case of some algorithm give us an upper bound of the execution time;
that means none **input** can spent more time than the worst case (although it
is possible to get a time execution equals to the worst case).

For some algorithms, the worst case almost never occurs because the specificity
required for the **input**.
In the **Insertion sort**, for a **Input** with $n$ elements, the slowest
situation happens only for 1 between $n!$ permutations of elements.
Thus, the worst case has a low probability and in this case a better analysis
is given by the *average-case*.
Despite the worst case, commonly, being slowly than average-case, the most of
algorithms have average-cases close to worst.
Lastly, with the **Insertion sort**, the average-case also has a quadratic
time complexity.

**Order of growth**\
Time complexity (or memory complexity) is a function $f(n)$ where $n$ is the
size of **input**.
The $f$ is the theoretical quantity of time (or memory) spent to solve the
problem with that input.
But in general an algorithm analysis is interested in the **order of growth**
of this algorithms.
This means a function behavior of $f$, for instance, quadratic in our example of
**Insertion sort**, since $f(n)=\frac{n^2+n}{2}$.
Thus, our **order of growth** summarize $f$ in the most growing parcel of that
function, $n^2$.
So, the time spent to sort $n$ element using **Insertion sort** can grow
quadratically according to the size of the array.

### 2.3 - Designing algorithms
**Insertion sort** is an approach of **incremental** algorithm, to solve the
sort problem, but there are others approaches that allow us to sort an array of
elements.
Here we discuss about **divide-and-conquer** algorithms, in which we can
prevent some instructions to be executed by separating the elements.

#### **2.3.1 - The divide-and-conquer approach**
This approach is (in many cases) recursive, and consists in divide a big input
in small pieces (or groups) and solve this groups dividing it in smaller
sub-groups.
The smaller sub-groups are a set of elements with common characteristics where
the algorithm can solve it easier than the whole group.
In short **divide-and-conquer** has three main steps:
1. **Divide** the problem in small instances (subproblems).
2. **Conquer** this subproblems by dividing them recursively.
3. **Combine** the subproblmes solutions and yield the solutions of the big
problem.

The **merge sort** algorithm uses this approach by:
1. **Dividing** (recursively) instance of $n$ elements into two problem with
$\frac{n}{2}$ elements.
2. **Conquering** with the recursion of merge sort.
3. **Combining** two sub-arrays in a big array sorted.

**Merge sort** is a "bottoms-out" recursion, since the divide occurs until the
subgroup has 1 element - it guarantees that the subgroup is always sorted.
Then, suppose that **merge sort** algorithm divide the instance $A$ into $B$
and $C$: Whether $B$ has just 1 element, $B$ is already sorted, now the
algorithms need to solve the $C$ group.
Note that if $C$ also has just 1 element, $C$ is sorted.
Lastly, after to solve $merge(C)$, the groups $A$ will be overwritten with
$B$ and $C$ elements.
That overwriting considers the correct sequence, thus the only element inside $B$
will be copied to $A$ for the correct position among elements of $C$.

This last step (overwritten) occurs whenever these two divided groups are
sorted.
The name **merge sort** is given because as these two subgroups are sorted, it
is easy to create a parent group from these ones.

#### **2.3.2 - Analyzing divide-and-conquer algorithms**
Algorithms that have recursive call to itself can be time-analyzed using
**recurrence equation**.
This equation is given in parts, where each part is an decision case inside
the algorithm.
For instance, for an mock array $A$ which is divided in two other arrays $B$
and $C$:

$$T(n) = 
\begin{cases}
  \Theta(1)       & ,\ n=1\\
  T(n-1) + T(1) & ,\ n \text{ is odd}\\
  2T(n/2)       & ,\ n \text{ is even}
\end{cases}
$$

Look that every when the size of subgroup is even, the cost of calculating the
result is equals twice executions for $\frac{n}{2}$.
When the subgroup has an odd quantity of element, then the cost is equals to
$n-1$ plus the cost of the execution for single one element.
It implies in a multiple recursion calls until every divided group having 1
element and finally return a constant cost.
Then, we can suppose that this algorithm wants to divide the problem in
subproblems with an even quantity of elements.
Thus the conditions (that make the recursive calls) decide the execution cost
of that algorithm.

**Analysis of merge sort**\
With the tree main stages of **merge sort** (Divide, Conquer and Combine) we can
analyse separately each task.
**Divide** executes with only one operation: separate two different indexes gap
between the bigger array; so we have a cost equals to a constant $c$.
**Conquer** must call the recursive function for the two pieces of the splitted
array, as the array (generally) is divided in two equal parts, then the cost is
$2 \times T(\frac{n}{2})$.
**Combine** generates a big array from two other smaller arrays (with
$\frac{n}{2}$ each), therefore this cost is equals to $n$.
Lastly, when $n=1$, there is a constant cost just returning the array with
this element.
In short, the recurrence equation is given by:
$$
T(n) = 
\begin{cases}
  \Theta(1)                   &,\ n \leq 1\\
  T(n/2)+\Theta(n)+\Theta(1)  &,\text{ otherwise}
\end{cases}
$$

Using the master theorem we can prove the cost of **merge sort** is
$$f(n) = \Theta(n \times\log_2 n)$$

## 3 - Growth of Functions
In the [chapter 2](#2---getting-started)
we defined the exact complexity of **Insertion Sort**, but in
general we are interested in the behavior of the complexity function.
In other words, we've observed the **Insertion sort** behavior is quadratic,
because its $f(n) = \frac{n^2+n}{2}$ and the most expressive parcel of this
function is $c_1 \times n^2$ whose $c_1 = \frac{1}{2}$.
Using growth functions we are not concerned with this constants, like $c_1$,
since the **Input** is very large this constants will not be an expressive
weight on the time spent to solve that problem.
So, for that case our **Growth function** is $g(n) = n^2$ and this function is
the asymptotic function of $f(n)$.

### 3.1 - Asymptotic notation
This notation is used to define the asymptotic running time of an algorithm.
In general, a asymptotic function summarize the function behavior when the 
input is infinitive.

**Asymptotic notation, functions, and running times**\
Asymptotic notations frequently denotes the behavior of functions not mattering
the input of the problem.
As we saw in **Insertion Sort**, in the worst-case we have a quadratic
function, but this occurs just with a specific input organization.
In other cases, the cost is not a quadratic function, then there is a notation
to express another input cases.

**$\Theta$-notation**\
For a given function $g(n)$, we denote by $\Theta(g(n))$ the set of functions:
$$
\Theta(g(n)) = \{f(n):\text{ there exist positive constants }c_1, c_2
\text{ and } n_0 \text{ such that } \atop0 \leq c_1g(n) \leq f(n) \leq c_2g(n)
\text{, for all } n \geq n_0\}
$$
We can interpret that saying for some $n$,  $c_1\times g(n)$ is always lesser
than $f(n)$.
In addition, with this same $n$ value, $c_2 \times g(n)$ is always greater than
$f(n)$.
Thus $g(n)$ can represent a lower and a upper bound for $f(n)$ when this bound is multiplied by a constant, so $f$ belongs to $\Theta(g(n))$ or
$f(n) = \Theta(g(n))$.

**$O$-notation**\
With $\Theta$-notation we are mattering with the upper and lower bounds given
by an single function $g(n)$, but with $O$-notation we are concerned just with
the upper bound.
Then, $O(g(n))$ is a a set of functions where:
$$
O(g(n)) = \{f(n):\text{ there exist positive constants }c \text{ and } n_0
\text{ such that } \atop0 \leq f(n) \leq c\times g(n)
\text{, for all } n \geq n_0\}
$$

Note that $f(n) = \Theta(g(n))$ implies $f(n) = O(g(n))$

**$\Omega$-notation**\
With $\Theta$-notation we are mattering with the upper and lower bounds given
by an single function $g(n)$, but with $\Omega$-notation we are concerned just
with the lower bound.
Then, $\Omega(g(n))$ is a a set of functions where:
$$
\Omega(g(n)) = \{f(n):\text{ there exist positive constants }c \text{ and } n_0
\text{ such that } \atop0 \leq c\times g(n) \leq f(n)
\text{, for all } n \geq n_0\}
$$

Note that $f(n) = \Theta(g(n))$ implies $f(n) = O(g(n))$

#### **Theorem**
For any two functions $f(n)$ and $g(n)$, we have $f(n) = \Theta(g(n))$ if and
only if $f(n)=O(g(n))$ and $f(n) = \Omega(g(n))$.

**Asymptotic notation in equations and inequalities**\
When asymptotic notation is shown in formulas, we shall interpret that like
an anonymous function, where we just know about the possible functions set that
can be overwrite the asymptotic notation.
For instance $2n^2+3n+1 = 2n^2+\Theta(n)$ means that
$2n^2+3n+1 = 2n^2+f(n)$ where $f(n)$ is part of the set $\Theta(n)$.
In Chapter 2 we've used the recurrence function of **merge sort** as
$T(n) = 2T(\frac{n}{2}) + \Theta(n)$ to give more details about the recurrence
function.
This notation helps to understand behavior of the complexity function.

Using another example, $2n^2 + \Theta(n) = \Theta(n^2)$, the left equation 
shows more details from the function than the right.
Then, some different analysis can be extracted from a more detailed asymptotic
notation.
Further more, it still possible getting an asymptotic function from the left
equation, but as we've saide before, the asymptotic notation summarize the
function behavior by considering an infinitive input.

**$o$-nonation**\
Differently to $O$-notation, the *little-oh*, not want to denote a tight
asymptotic function.
Contrariwise, $o$-notation specifies the set of functions that are an above
asymptote but are not tight.
For example, $2n^2 \neq o(n^2)$ since $n^2$ is the tight asymptote for $2n^2$.

$$
o(g(n)) = \{f(n):\text{ for any positive constants }c > 0 \text{, there exists
a constant } n_0>0 \text{ such that } \atop0 \leq f(n) < c\times g(n)
\text{, for all } n \geq n_0\}
$$

Observe that
> for any constant $c>0$

$c\times n^2$ can not be an upper bound for $2\times n^2$, because $c \in (0, 2]$ not satisfies that condition.
But for the case where $2n = o(n^2)$ any value of $c>0$ make $c\times n^2$ an
grater limit of $2\times n$.

**$\omega$-nonation**\
Here occurs the same analogy between **$o$** and **$O$** notations, using the
lower bound instead.
For that case we have:
$$
\omega(g(n)) = \{f(n):\text{ for any positive constants }c > 0 \text{, there exists
a constant } n_0>0 \text{ such that } \atop0 \leq c\times g(n) < f(n)
\text{, for all } n \geq n_0\}
$$

With the same example of $o$-notation, $2n^2 \neq \omega(n^2)$.
It is explained with the range where $c \in [2, \infty)$; inside this interval
$c \times n^2$ is always greater than $2n^2$.
Although, $2n^2 = \omega(n)$, because every value of $c>0$ makes $c\times n$ being lesser than $ 2n^2$.

### 3.2 - Standard notations and common functions
This chapter explores mathematical relationships among asymptotic notation.

**Monotonicity**\
A function $f(n)$ is **monotonically increasing** if $m\leq n$ implies
$f(m) \leq f(n)$.
Similarly, $f(n)$ is **monotonically decreasing** when $m\leq n$ implies in
$f(m) \geq f(n)$.
$f(n)$ is **strictly increasing** whether $m < n$ implies $f(m) < f(n)$ and
**decreasing** if $m<n$ implies $f(m) > f(n)$.

## 34 - NP-Completeness

### 34.1 - Polynomial time
To study the NP-completeness we shall consider three things:
1. Although we feel that a problem that requires time $\Theta(n^{100})$
to be intractable, in general, practical problems requires very few time, for
consequence a low-degree polynomial.
2. Problems that can be solved by reasonable models of computing in polynomial
time, also can be transposed and solved using another reasonable models.
3. Since polynomials are closed under addition, multiplication and composition,
the class of polinomial-time solvable problems has nice closure properties.
For instance, if the output of a polynomial algorithm is fed into the input of
another polynomial problem, then this composition results a new polynomial 
problem.

**Abstract problems**\
Let us define, firstly, what exactly a problem is:
- **Abstract problem** is a binary relation between a set $I$ of **inputs**
with the set $S$ of **solutions**.
This relation don't need to be an injection, so one input can result in 
different solutions and vice-versa.
For instance, two different permutations of an array of elements have the same
solution for the sorting problem.
Another example is the shortest path in a graph, a graph can contains two 
different, but equally short, paths within itself for the same set of edges and
vertexes.
This kind of problems is more general than we need, so we shall pay attention
in **decision problems**, that are a more simple problems whose output always 
$\in \{yes,\ no\}$.
- **Decision problems** are a binary relation between some input and a 
solution, but differently from **abstract problems**, in this case our possible
solutions set is $\{yes,\ no\}$, or else $\{1,\ 0\}$.
Then, these problems wants to solve questions like "Is it possible to ... ?"
and answer either `"yes, it is possible"` or `"no, it is not possible"`.
- **Optimization problems** are problems where given some input, the solutions
must yield the solution with some "best result".
For instance, the Shortest Path problem is an optimization problem, because the
best solution consists of the shortest path in a graph.
Then, solutions for optimization problems must grant that there is not a 
better solution than this one.
In addition, we can say that if we can solve a **decision problem** in 
polynomial time, probably we shall solve another problem types also in 
polynomial time.

**Encodings**\
Current computers use binary notation to store commands and data.
To translate real-world problems to computer these computers must encode our
data and our commands in some binary expression.
For instance, ASCII code is an encoding of alphabetic characters.
So, a computer that solves abstract problems, actually encode this problems to
a language understandable for the computer.
After such translation, the abstract problem become a **concrete problem**.
**Concrete problems** are polynomial-tiem solvable when the time complexity
follows $O(T(n))$ with $T(n) = n^k$ where $k \in \N$ is a constant.
Lastly, we can formally define the **complexity class P** as the set of 
**concrete problems** that are polynomial-time solvable.
Remember that $n$ is the input size whose this input is the
**concrete elements**, in other words, the translated elements from real-world.

The polynomial behavior depends on the encoding, for example, suppose a 
problem that the input is an integer $u$ and its complexity is $\Theta(u)$.
If we consider that input size as 1 (because it is given just one integer), 
then our solution is not polynomial-time solvable, since the size of the input
is constant, and the problem can be hard to solve even if the size input not   
changing.
In other hand, if we have the another problem that receives an integer $v$ that
requires $\Theta(w^2)$ of complexity time, where $w$ is the bits of this
integer in binary base, then we have a polynomial solution.
It occurs because numbers can be translated with some encoding, and with this 
tool the solution becomes polynomial.

**Lemma 34.1**\
Let $Q$ be an abstract decision problem on an instance set $I$, and let $e_1$
and $e_2$ be polynomially related encodings on $I$.
Then, $e_1(Q) \in P$ if and only if $e_2(Q) \in P$.

**A formal-language framework**\
**L** is a language defined by an alphabet $\Sigma$ with finite symbols.
**L** is any combination of $\Sigma$ symbols.
Finally, the **P class** can be defined in two ways:
$$
P = \{L \subseteq \{0, 1\}^\ast \text{: there exists an algorithm } A
\text{ that decides } L \text{ in polynomial time} \}
$$
OR
$$
P = \{L:\ L\text{ is accepted by a polynomial-time algorithm} \}
$$

### 34.2 - Polynomial-time verification
Even if we don't know polynomial-time solutions for some problems, given an 
instance and a result, we can check if that result can answer the question,
proposed by the problem.
This checking is called as a certificate algorithm.
To illustrate, suppose that the polynomial-time algorithm of the sorting 
problem is unknown, but given two arrays $I$ as input and $R$ as result,
we can verify all elements $r \in R$ if $r_i \leq r_j$ with
$i < j \leq R.length$.
This checking executes in polynomial time and can say us if $R$ is sorted or 
not.

**The complexity class NP**\
The NP class contains the problems that can have their solutions checked by a
polynomial algorithm.
In other words, a polynomial-time certificate.
The main question about NP class is: "Is NP=P class?", so far there are 
problems in NP class which has no a polynomial-time solution.
Furthermore we can not say that this problems will not have a polynomial-time
solution in the future, thus we don't know if NP is equals, or not, to P-class.

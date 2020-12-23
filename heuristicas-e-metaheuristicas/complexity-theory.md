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
\Biggr\{{
    \normalsize\Theta(1) \quad\qquad\qquad,\ n = 1 \atop\Large {
    T(n-1) + T(1) \quad, \ n\ \text{is odd}\atop {
    2T(n/2) \qquad\quad, \ n\ \text{is even}
}}}
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
\Biggr\{{
    \Theta(1) \qquad\qquad\qquad,\ n \leq 1 \atop 
    T(n/2)+\Theta(n)+\Theta(1) ,\ \text{otherwise}}
$$

Using the master theorem we can prove the cost of **merge sort** is
$$f(n) = \Theta(n \times\log_2 n)$$
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
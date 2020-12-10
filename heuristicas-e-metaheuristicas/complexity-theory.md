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
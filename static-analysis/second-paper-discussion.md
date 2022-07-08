Vinicius Julião Ramos\
2018054630

# Second Paper Discussion
## Divergence Analysis


1. The problem that the paper discusses
   1. What is the specific problem that the paper solves?\
   The paper propose a static analysis that discover divergences in SIMD architectures, aka GPUS. Such static analysis make it possible to optimize GPU code.

   2. Why is this problem important\
   GPU has become very useful for many purposes like Games and Machine Learning. So, for that scenarios where the computation depends on a GPU it would be better to improve the register allocation in order to reduce the number of requests for those data placed in low hierarchy level.
   
   3. Who will benefit immediately from the solution of this problem.\
   The benefit is the improvement in the register allocation approach, where it was possible to notice that the code produced by this work is 26.21% faster than the code produced by the baseline compiler.
   
   4. What is the theory upon which the problem is defined?
   The theory behind the problem is related to divergence flow and register allocation. So, to improve the register allocation, it is necessary to identify the divergent points in the CFG.
   

2. The context of the paper

   1. What is the general context of the paper?\
   The general context is to use Divergence Analysis to improve register allocation for a GPU program.

   2. Since when is this context source of research?\
   If we consider graph theory, we can aim that this research context is researched since the graph theory raise up. But, considering the static analysis context, we can affirm that the context of the problem discussed in this paper was raised with the advance of the GPU based programs.

   3. Is there any book that provides an in-depth overview of this problem?\
   Yes, one of the authors of this paper (Fernando Pereira) has a online book that explains th Code Optimization Techniques for Graphics Processing Units.
   There is also a NVIDIA's book (gpu GEMs) that has a chapter dedicated to explain GPU optimizations.

   4. What can we find about this context in wikipedia?\
   It's not possible to find a specific page for "Divergence Analysis" in Wikipedia. However, the page about CUDA programming has a section that explores and explain GPU optimizations.
  
3. The Solution
   1. What is the key idea used to solve the problem?\
   Two different solutions were given in that paper. So, we have a naïve solution at first, that extracts the divergence propagation between the variables in the program.
   The second solution is a deeper one, that is capable to give more information about divergent variables, no only inform if a variable diverges or not.

   1. Why is this specific idea different from what had been done before?\
   Actually, this is the first paper about divergence analysis. So, the closest solution that was had before is the *vectorization analysis*. These approaches differs in the sense where *vectorization* can track affine relations between variables and identify variables which hold values that are consecutively spaced between successive threads. In the other hand, *divergence analysis* considers control flow dependency to determine the abstract state of a variable.

   1. Is there any algorithm involved in the solution?\
   Yes. The control flow graph of a program is traversed in order to assign the state of a variable given the current visited point. This assignment is made by the relations defined in section 3. 

   1. Is the solution exact, or does it approximate an optimal? In the latter case, what would be the price of finding the optimal?\
   No, the solution is not exact. The exact solution depends on run time information. The "divergent" state is a "might be" not a "must be". So, there are cases where we determine a "divergent" state for a variable that is not necessarily it.


4. The Organization of the Paper 

   1. How was the abstract organized?\
   The abstract is organized in the traditional "context - problem - solution - results" style.

   1. How was the introduction organized?\
   With six paragraphs, the introduction follows the "context - problem - solution" style. However it is done by showing related works that confirms the sense of each presented information. The first 2 paragraphs show the context, where introduces the focus of SIMD programs for GPUs. The three following paragraphs briefly argues the use of Divergence Analysis and why it is important. Also, in these three paragraphs it is shown the problems that can be solved by this approach. The rest of the section describe the solutions that the paper contains.


   1. What is discussed in each section of the paper?\
   1 Introduction - 2 Background - 3 Divergence Analysis - 4 Divergence Aware Register Spilling - 5 Experiments - 6 Conclusion

   1. What was left for the conclusion?\
   The authors conclude the paper by confirming the quality of that solution and present that despite the work have been implemented for a NVIDIA GPU, it can be extended to support further SIMD architectures and programming languages.
  
  
5. The Written Style

   1. Can you give a title to each paragraph in the introduction?\
   2) Use of GPUs for parallel computation. 2) The existent brands of GPUs and its naming. 3) What is data divergence. 4) Paper goal. 5) Where Divergence Analysis can be applied. 6) Benefits of Divergence Analysis. 7) Experiments environment. 8) Paper summary.

   4. Can you find examples of sentence topics to every paragraph in the introduction?\
   Yes, I can!\
   Increasing programmability and low hardware cost are boosting the use of graphical
processing units (GPU) as a tool to run general-purpose applications.\
    Such groups are called warps in NVIDIA’s jargon,
or wavefronts in AMD’s.\
    Data divergence occurs if the same variable name is mapped to different values in the
environments of distinct processing elements.\
    The main goal of this article is to provide compilers with techniques that help them
understand and improve divergent code.\
    The divergence analysis is important in different ways. First, it helps the compiler
to optimize the translation of SIMD languages to ordinary CPUs.\
    Third, the divergence analysis improves the static performance prediction techniques used in SIMD architectures.\
    We have compiled all 395 CUDA kernels taken from the Rodinia...\
    In that work, we mentioned our divergence-aware register spiller; however, in
this article, we explain it in much deeper detail, following a previous description...
   
   1. Can you give examples of techniques used to connect different paragraphs?\
   The second paragraph connects to the first by stating describing a feature of GPUs. So, the second paragraph begins a new subject, not connected with the second, neither the fourth. However, the fifth one connects to the fourth by explaining that the goal of the article is use the concepts explained in the previous paragraph.
   For the sixth paragraph, it starts by enumerating the second goal, since the first goal was introduced in the fifth paragraph.
   Lastly, the two last paragraphs are not connected.

   1. Can you find examples of declarative, illustrative and enumerative paragraphs?\
   The two first paragraphs are declarative, since it shows the capabilities of a GPU and the available models and brands in the market. These two ones, also can be considered illustrative, since they use GPU models and them features to exemplify the computational power.\
   The fifth and sixth paragraphs have a enumeration that outlines the goals of this paper.
  
1. The related works

   1. What is the purpose of the related works section in this paper?\
   There is no related works section.

   1. What are the earliest papers about this problem?\
   This is the first paper about "Divergence Analysis"

   1. What is the most seminal paper in this field of research?\
   It is this one.

   1. Which good conferences have recently published papers about similar problems?
   OOPSLA, PLDI and POPL.

2. Validation

   1. Which points do the authors try to prove with experiments?\
   The authors ran the most know benchmarks by comparing the solutions for register allocation given by a "Divergence Analysis" and the current compilers. Then the generated programs are compared and information as program speedup and size are drawn in tables and graphs.

   1. Are the experiments rigorous enough?\
   Yes, they are. The authors used the same a well known set of benchmarks fot SIMD programs. All the steps of that experiments are shown and this test is reproducible since the tool is publicly available.

   1. Which visual resources have the authors used to present data?\
   Bar and line graphics were used to compare the current solution and other ones. Also, a table containing these results was shown. In this table is possible to observe the speedup that the newer solution has performed. Each line of the table specifies the benchmark for a given input. There are two line graphics that shows the linear behavior of the current solution against the quadratic time cost of the last solution.

   1. Which statistical theory have the authors used in this paper?\
   Actually, the paper does not present a strong statistical theory. Despite it has used tables and graphs, there is no statistical information. But since we have the raw data, it is possible to calculate statistics.
  

3. Resources

   1. Do the authors use any particular type of notation?\
   Yes. The "toy" language used to exemplify the instructions of interest for that program is written in a particular notation. Also, there is a particular notation used to demonstrate how the state of a variable is propagate for another one.
   In summary, the Figure 5 is the best example of particular notation.

   1. Which examples have the authors used to present their ideas?\
   The authors give, in general, programs as examples. These programs are given in the control flow graph format. It is also given a dependency graphs as examples, like the Figure 14.
   Lastly, to exemplify a high polynomial level program, the Figure 15 shows a C-like program.

   1. Which visual resources have the authors used to explain their points?\
   Graph images, tables, pseudo codes and data graphics are used for that end.
   
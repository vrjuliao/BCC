Vinicius Julião Ramos
2018054630

# First Paper Discussion
## A Linear Time Algorithm  for Placing phi-Nodes


1. The problem that the paper discusses
   1. What is the specific problem that the paper solves?\
   This paper gives a linear time algorithm that is capable to find out iterate dominance frontier for any graph in linear time. Actually, the related work (Cytron) is capable to generate the IDF for a graph in linear time, but for latter graphs it is not possible.

   2. Why is this problem important\
   Considering that Cytron's algorithm was the key reference for solving IDF, in the field of static analysis, identify IDFs is important to compute the phi nodes for a program represented, for example, in a SSA form.

   3. Who will benefit immediately from the solution of this problem.\
   All those ones that needs a solution to solve the Iterated Dominance Frontier for a graph. In this case the sense of Static Analysis we are benefited with a linear algorithm that helps us to identify phi functions and its nodes.

   4. What is the theory upon which the problem is defined?
   Some theory aspects that grounds the paper are related to graph-theory like dominance, dominance frontier, iterated dominance frontier. Also, we have the Static Analysis basis as the SSA form.
  
2. The context of the paper

   1. What is the general context of the paper?\
   It is a Static Analysis paper that discuss about a solution the new state of the art for solving IDFs in a graph.

   2. Since when is this context source of research?\
   If we consider graph theory, we can aim that this research context is researched since the graph theory raise up. But, considering it as a static analysis based context, we can affirm that the context of the problem discussed in this paper was raised with the SSA or SEG representations.

   3. Is there any book that provides an in-depth overview of this problem?\
   Yes, some books like the Dragon's book have a section that discuss about SSA representations and in those sections, the problem of finding phi function and phi nodes are shown. But there is no a book only dedicated to discuss SSA forms with a linear time solution for phi functions.

   4. What can we find about this context in wikipedia?\
   It is possible to find ou a huge page in Wikipedia that discuss about phi nodes. Actually, this paper is in the bibliography of the wikipedia page. Phi nodes are explained and the reasons of IDF identification are presented.
  
3. The Solution
   1. What is the key idea used to solve the problem?\
   The author used an approach of checking the IDF recursively, but spending a linear time for each node. However, the solution also propose a new visiting order of the nodes, such that avoid duplicated computation. Once this duplicated computation is avoided, the quadratic cost does not occur.

   2. Why is this specific idea different from what had been done before?\
   The previous idea computes the IDF nodes for each node. So, in that sense it has a quadratic memory cost. If we consider each node IDF as a set, and considering that we have to make union operations using those sets, we will spent a quadratic computation time. This new approach introduces a new data structure that doesn't use this kind of memory, and with this new data structure, we can reach a linear memory and time complexity.

   3. Is there any algorithm involved in the solution?\
   The solution itself is an algorithm. But we can see a kind of graph traversing (not an in depth traversing) but the visiting order is a key aspect of this algorithm.

   4. Is the solution exact, or does it approximate an optimal? In the latter case, what would be the price of finding the optimal?\
   Yes, we have an exact solution.


4. The Organization of the Paper 

   1. How was the abstract organized?\
   The abstract is organized in the traditional "context - problem - solution - results" style. The two first sentences present the context. The next sentence presents the problem. The rest of the first paragraph introduces the solution, and lastly, the whole second paragraph introduces results.

   2. How was the introduction organized?\
   With six paragraphs, the introduction follows the "context - problem - solution" style. However it is done by showing related works that confirms the sense of each presented information. The first paragraph shows the context, but the following enumerations blends the problem with the context. The second paragraph presents the problem by introducing the last state of the art algorithm to solve phi-nodes placing. The next three paragraphs the solution is briefly explained and the paper body is shown. 


   3. What is discussed in each section of the paper?\
   1 Introduction - 2 Background and Notation - 3 DJ-Graphs and Their Properties - 4 Algorithm for Placing phi-Nodes - 5 Correctness and Complexity - 6 Implementation and Experimental Results - 7 Related Works - 8 Conclusion

   4. What was left for the conclusion?\
   The author concludes the paper by confirming the quality and the simplicity of the solution. The conclusion, also describes some advances and novelties, like the DJ-Graph, that this paper presented.
  
  
5. The Written Style

   1. Can you give a title to each paragraph in the introduction?\
   2) The existent intermediate representations of programs, including SSA and SEG. 2) Steps for a placing phi-nodes algorithm. 3) Why the last state of the art algorithm has a quadratic cost. 4) Use of a dominance graph to this new solution. 5) DJ-Graph: an extension for dominance graph. 6) How the solution was implemented and how it was stressed. 7) Paper structure.

   2. Can you find examples of sentence topics to every paragraph in the introduction?\
   Yes, I can!\
   In the first paragraph: "Static Single Assignment form, ..., and other related intermediate representations have been successfully used for efficient data flow analysis...".\
   The enumerated steps are proceeded by: "Given a flow-graph, the original algorithm for computing phi-nodes for ans SEG consists of the following steps:".\
   The next paragraph starts with: "The time complexity of the original algorithm depends on the size of the dominance frontier".\
   Fourth one: "One key feature of our linear time algorithm is to order the ones in the dominator tree in such way that...".\
   In the fifth paragraph, the word "DJ-Graph" is explained by: "The skeleton of the DJ-Graph is the dominator tree of its flowgraph".
   For the sixth paragraph, the start sentence describes implementations aspects like: "The algorithm has been implemented n the top of Parafrase2 compiler.".\
   The last paragraph, we have the a bolded word "Organization" that is followed by the paper structure.

   3. Can you give examples of techniques used to connect different paragraphs?\
   The firs paragraph terminates with a sentence that said that the following enumeration presents the algorithm steps. Then, in the third paragraph, when the author uses "The time complexity of the original algorithm" it links with the algorithm outlined in the last steps.\
   The next three paragraphs are not too connected with the first ones. But such three paragraphs are connected by themselves, since each first sentence of each paragraph mentions the subject discussed in the paragraph above.

   4. Can you find examples of declarative, illustrative and enumerative paragraphs?\
   The first paragraph is a declaration of intermediate representations. Then, after the first paragraph we have an enumeration of steps that outline the algorithm to compute phi-nodes placing for SEG representation. The sixth paragraph illustrates the DJ-Graph by showing what are the D and J edges. Also, this sixth paragraph mentions the Figure 1 to enforce the description of DJ-Graphs.
  
6. The related works

   1. What is the purpose of the related works section in this paper?\
   The main purpose of the related works section is brings some works that approach the same problems discussed in this paper, like the phi-nodes placing solutions, and also the use of phi-nodes in the static analysis area for SSA and SGE representations. There also are related works that brings some benchmarks papers containing the used inputs for the benchmarks obtained in this paper.

   2. What are the earliest papers about this problem?\
   R. M. Shapiro and H. Saint. The representation of algorithm. Technical Report CA-7002-1432,MCA, 1970.

   3. What is the most seminal paper in this field of research?\
   Ron Cytron and Jeanne Ferrante. Efficiently computing phi-nodes on-the-fly. In Languages and Compilers for Parallel Computing, 1993.

   4. Which good conferences have recently published papers about similar problems?
   OOPSLA, PLDI and POPL.

7. Validation

   1. Which points do the authors try to prove with experiments?\
   The author proves that its solutions runs in a linear time, considering linear in terms of nodes and edges of the flowgraph.

   2. Are the experiments rigorous enough?\
   Yes, they are. The author used the same set of benchmarks used by Cytron. So, since Cytron was the last key reference for the problem solved by this paper, using the same benchmarks is a good approach to show that the proposed solutions beats the Cytron results.

   3. Which visual resources have the authors used to present data?\
   Bar and line graphics were used to compare the current solution and the last one. Also, a table containing these results was shown. In this table is possible to observe the speedup that the newer solution has performed. Each line of the table specifies the benchmark for a given input. There are two line graphics that shows the linear behavior of the current solution against the quadratic time cost of the last solution.

   4. Which statistical theory have the authors used in this paper?\
   Actually, the paper does not present a strong statistical theory. The data are shown in a kind of "raw" table, only containing the speedup. But since we have the raw data, it is possible to calculate statistics.
  

8. Resources

   1. Do the authors use any particular type of notation?\
   Yes. A well modularized pseudo code describes the algorithm. Due to the simplicity of such algorithm, it is really easy to follow the pseudo code. In this pseudo code there are notations for structure definitions, and also it is possible to see that we have a kind of implicitly array notation for some entities like "PiggyBank".

   2. Which examples have the authors used to present their ideas?\
   The authors used only two examples to explain the ideas. The first one is the Figure 1 and 2 (They complements each other). With these figures, the authors shows how a DJ-Graph is mounted given the steps that flows from Flowgraph to dominance graph to DJ-Graph.\
   The next example is given at the end of the fourth paragraph, where briefly executes an iteration of the algorithm.

   3. Which visual resources have the authors used to explain their points?\
   Graph images, tables, pseudo codes and data graphics are used for that end.
   
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
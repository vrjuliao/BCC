# Pesquisa científica

Reis, A. S. e Frota, A. G. C., Guia básico para a elaboração do projeto de pesquisa\
Barr et al, "Designing and reporting on computational experiments with heuristic methods", Journal of Heuristics, 1: 9-32, 1995.\
McGeoch and Moret, "How to present a paper on experimental work with algorithms", ACM SIGACT, 30:85-90, 1999.\
Johnson, "A theoretician's guide to the experimental analysis of algorithms", 2001.\
Moro M. M., Guia Rápido para Avaliar Artigos: não jogue no time adversário, 2021.

## Guia básico para a elaboração do projeto de pesquisa

**O que é um projeto de pesquisa**:\
Um documento que define o que pesquisar, por que pesquisar e como pesquisar.

**Finalidades do projeto**:\
Mapear o caminho a ser seguido, orientar o pesquisador durante o percurso,
comunicar os propósitos.

**Elementos construtivos do projeto**:\
Referenciais teóricos, referenciais metodológicos e elementos complementares.

**Tema**: Áre de interesse da pesquisa,

**Problema**: Questão não resolvida e que é o objeto de investigação.

**Hipótese**: Resposta provável ao problema formulado.

**Justificativa**: Contribuições pra a compreensão ou solução do problema,
estágio de desenvolvimento do tema proposto.

**Objetivos**:
- Geral: dimensão mais ampla pretendida com a pesquisa.
- Específicos: Metas que viabilizam o alcance do objetivo geral.

**Metodologia**:\
Especificação do plano de ação,

**Definição da amostragem**:\
- Escolha do espaço e do grupo de pesquisa.
- Termos de escolha:
  - Quantitativos: Quantidade de indivíduos
  - Qualitativos: Qualidades sobre as entidade em pesquisa.

**Coleta de dados**: Há vários métodos para o exercício dessa etapa:
- entrevistas
- observações
- histórias de vida

**Organização e análise de dados**\
- estabelecimento de categorias
- codificação: dados brutos transformados em símbolos.
- Tabulação: Agrupar casos que estão em várias categorias de análise.

## Designing and reporting on computational experiments with heuristic methods
### 1 Heuristic methods
The goal of an heuristic solution is provide a solution, perhaps not optimal,
where execution time is most important than the quality of the solution.

### 2 Computational experiments with Heuristics
Computational testing consists of the execution of a solution and the results
checking.
Since the instances and the optimal results are already known it is possible 
to generate metrics of quality examining.

### 3 Setting Experimentation Goals
There is no a standard set of publishable contributions of a heuristic method.
But in general, the considered qualities are:
- Fast
- Accurate
- Robust
- Simple
- Heigh-impact
- Generalizable
- Innovate

Then, it's necessary create a experiment that identifies these properties in a
heuristic solution.

**3.1 Comparing algorithms**\
Before compare two algorithms, the goal of its must be the same.
For example: if an algorithm was developed to be a fast solution, it will
be compared with another fast solution observing which algorithm is fastest.
Furthermore, when the time-execution results does not give a winner, other
property can be selected for a new comparing.

**3.2 Describing Algorithm Performance**\
Instead of using a comparing approach, we can use a descriptive experiment.
The objective is to gain understanding of the behavior of the methodology, and 
the factors that influence that behavior.

### 4 Choosing Performance Measures and Factors
A experiment goal is analyze the performance measures using the test
environment factors.

**4.1 Measuring Performance**\
For measuring performance, we would like to answer the following questions:
- What is the quality of the best solution found?
- Hou long does it take to determine the best solution?
- How quickly does the algorithm find good solutions?
- How robust is the method?
- How faz is the best solution from those more easily found?
- What is the tradeoff between feasibility and solution quality?

**4.1.1 Quality of solutions**\
Generally, quality f solution is given by a comparison between the best 
solution known so far.
Using this approach, we are concern to publish the percent deviation from the
optimal solution.
When the optimal is unknown, then the the compared solutions used in such 
analysis are the upper and the lower bound of each metric.

**4.1.2 Computational effort**\
When the speed of an algorithm is a concern, the analysis involving this metric
should consider one or more of the:
- Time to best-found solution
- Total run time
- Time per phase

**4.1.3 Robustness**\
Robustness, generally, is classified as the ability of a heuristic to perform
well over a wide range of test problems.

**4.2 Factors to Study**\
Before considering th e categories of factors, we need choose these ones
based on:
- Which factors to study
- which to fix at some level
- which to ignore, and hope that they wll not influence the experimental 
  results.


The main categories of factors that affect the performance of an algorithm
are:
1. **Problem Factors**:\
  Characteristics of a problem, suc as dimensions, structure, parametric 
  distributions.
2. **Algorithmic Factors**:\
  Selection of heuristics and computer codes to test.
3. **Test Environment Factors**:\
  Hardware, software, system, programmer (code experting).

### 5 Designing an Executing the Experiment
Experimental design is the process of planning an experiment to ensure that
the appropriate data will be collected.

**5.1 Choosing an Experimental Design**\
Firstly: the design of the experiment and the statistical analysis of the data
are interrelated.
The most famous and well known method to collect data and analyze it is called
as DOE.
DOE is a simple process for structuring and analyzing experiments, developed
for minimizing the testing effort and maximize the information acquired.

**5.2 Selecting Test Problems**\
The choices of test problems follows directly from the experimental design.

**5.3 Executing the Experiment**\
This is the data-collection step.
The main concerns are:
- Randomization
- Uniform computing environment

### Analyzing the Results and Drawing Conclusions
**Data analysis**: Refers to evaluating the recorded empirical data with
statistical and non-statistical techniques.
Analysis should address the goals of the project for the data behavior.
After the data was analyzed, the results are interpreted as a series of
conclusions and inferences, in order to provide an evidence.
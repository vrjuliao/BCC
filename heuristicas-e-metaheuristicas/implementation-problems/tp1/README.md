# Trabalho de Implementação 1
## Vinícius Julião Ramos - 2018054630
Heurísticas e Metaheurísticas - 2020/2

O trabalho consistiu na implementação de um a heurística construtiva que se
aproxima da otimalidade do Problema do Caixeiro Viajante.
A solução escolhida foi a abordagem *Greedy TSP*, em que partindo de um nó
específico escolhe-se o próximo nó da rota como aquele de menor custo.
O nó inicial da construção da solução é obtido de maneira aleatória, então a
partir deste, escolhemos o próximo nó como aquele de menor custo que não seja
o inicial.
Cada vez que um nó é escolhido como o próximo, ele é marcado com uma *flag*,
assim, para que um nó seja escolhido como o próximo este não deve possuir
tal marcação.

Para cada nó dado como o atual, há a necessidade de avaliar os outros $n-1$ nós
quanto ao custo da aresta e se esses demais já foram visitados anteriormente.
Em resumo, para cada um dos $n$ nós, é necessário analisar o menor valor
entre os outros $n-1$, logo há um custo quadrático de execução dessa
heurística.
Portanto, o custo de execução é $\Theta(n^2)$.
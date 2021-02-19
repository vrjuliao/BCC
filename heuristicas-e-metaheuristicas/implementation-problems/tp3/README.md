# Trabalho de Implementação parte 3
## Vinícius Julião Ramos - 2018054630
Heurísticas e Metaheurísticas - 2020/2

Nessa parte final do trabalho implementou-se uma busca tabular baseada em um
algoritmo guloso par a montagem da tabela.
A tabela é criada de forma que, cada elemento da tabela é uma subrota
de tamanho $n$, em que $n$ é a quantidade de arestas das subrotas.
Então para realizar busca baseada na tabela, ordena-se os elementos
de acordo com o custo empregado a cada rota.
Para cada um dos $n$ inícios de solução na tabela, emprega-se um algoritmo
guloso para completar o ciclo e por fim comparar se aquele ciclo é o de menor
custo, alcançado até então.


A intenção dessa metaheurística é reduzir a quantidade de sub-rotas repetidas.
Logo, partindo da subrota $i$, o algoritmo guloso adicionará um novo nó $k$ ao
ciclo e validará se o caminho formado por $k$ e seus $n-1$ pontos anteriores
compõem um subrota já presente na tabela.
Caso tal subrota pertença à tabela, ela então não será utilizada mais como
ponto de partida de uma provável solução.
Isso reduz a quantidade de subrotas visitadas.

Assim como descrito na primeira parte do trabalho, a abordagem gulosa tem custo
$O(m^2)$ para encontrar um ciclo, em que $m$ é a quantidade de nós do grafo.
Nesse caso, considerando que é possível obter uma instância em que nenhuma
subrota é eliminada com a evolução da busca tabular, então há o caso em que
a heurística analisa $m$ soluções gulosas.
Daí pode-se concluir que há um custo $o(m^3)$, considerando que o custo de
avaliar a existência da subrota de tamanho $n$ seja $O(1)$.
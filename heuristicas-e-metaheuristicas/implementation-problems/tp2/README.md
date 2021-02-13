# Trabalho de Implementação parte 2
## Vinícius Julião Ramos - 2018054630
Heurísticas e Metaheurísticas - 2020/2


Para essa segunda parte do trabalho, a fim de seguir a uma heurística baseada
em VND, o algoritmo opt2 foi implementado a fim de obter a vizinhança de uma
determinada rota.
A rota inicial $x_0$ considerada é dada pela parte 1 desse trabalho, ou seja
por uma heurística gulosa.
Assim, o algoritmo opt2 é responsável por retornar a vizinhança de $x_0$
e então pode-se comparar uma solução por vez o obter $x'$ que é a melhor
solução daquela vizinhança.

O loop da heurística se dá de forma que $x' = x_0$, e busca-se substituir
$x'$ pela rota $x''$ de menor custo dentro da vizinhança.
Após tal substituição, reinicia-se a busca pela nova melhor rota dentro da
vizinhança de $x'$.
Entretanto, antes de reiniciar o laço, a heurística valida se existiu algum
$x'' \neq x'$.
Caso não exista tal $x''$, então já temos que $x'$ é a melhor solução dentro 
da da sua vizinhança dada por opt2.
Por fim, $x'$ é retornado como solução dada pela abordagem VND.
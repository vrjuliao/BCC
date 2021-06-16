# Branch and bound
L. Wolsey, Integer Programming, cap 7.\
D. Bertimas e J.N Tsitsiklis, Introduction to Linear Optimization, sec 11.2

Algoritmos de branch and bound são baseados em técnica de divisão e conquista.
Isso requer a aplicação de duas idéias:

## 1. Decomposição do espaço  (branch)
seja $S = S_1 \cup \ldots \cup S_k$ a decomposição de $S$ em $k$ subconjuntos.
Podemos obter o máximo do conjunto $S$ a partir do calculo do máximo
dos seus subconjuntos.
Ou seja: $z^k = \text{max }\{c^Tx: s \in S_k\}$, então
$z = \text{max}_{k=1,\ldots,k}\{z^k\}$.

## 2. Determinação dos limites (bound)
Uma vez que problema foi decomposto pelo passo anterior, observa-se a
inviabilidade em percorrer todo o espaço de possibilidades.
Então é necessário desenvolver um mecanismo capaz de impor limites
superiores e inferiores à determinado "branching" e a partir de tais limites,
pode-se validar se uma ramificação pode ser ignorada ou não.

os limites inferiores e superiores caracterizam  os limites duais e primais,
em que para problemas de maximização:
- limites duais = limites superiores $\bar{z}$
- limites primais = limites inferiores $\underline{z}$

E no caso de minimização
- limites duais = limites inferiores $\underline{z}$
- limites primais = limites superiores $\bar{z}$

Quando os limites coincidem em um mesmo valor, é o caso em que o problema foi
resolvido.

## Podas na árvore de soluções:
### Poda por Otimalidade
é o caso em que um nó possui $\underline{z} = \bar{z}$, portanto quando os dois
limites alcançaram um mesmo valor, temos que a expressão
$\underline{z} \leq z \leq \bar{z}$ é satisfeita por $\underline{z}=z=\bar{z}$,
portanto chegamos ao valor ótimo.
Assim não faz sentido investigar qualquer outro subconjunto, derivado do nó que
alcançou a otimalidade local.
Isso quer dizer que ainda **NÃO foi verificada a otimalidade global**,
portanto é necessário continuar investigando a árvore, exceto os nós filhos
do nó ótimo local.

### Poda por limites
Observe a seguinte árvore de soluções e seus respectivos limites:
```
         S [12, 27]
       /   \   
      /     \
     /       \
    /         \
S1 [21, 26]    S2 [18, 20]
```

Se a ordem de resolução foi dada por `S -> S1 -> S2`, e sendo este um problema
de maximização, observe que ao resolver `S1`, o limite inferior é maior que
o limite superior de `S2`.
Portanto, `S2`  não é capaz de melhorar o melhor limite encontrado até então
Que é dado por `S1`.
Logo, `S2` será podado da árvore.

### Poda por inviabilidade
Ao tentar obter o limite dual do problema, se a relaxação é inviável, então o
**IP** também é.
Logo aquele nó será cortado, da árvore, pois não há maneira de determinar
limitantes.
Quando a relaxação é inviável, no caso de maximização, $\bar{z} = -\infty$,
sendo assim, não há como limitar superiormente o problema e consequentemente
não há a expressão $\underline{z} \leq z \leq \bar{z} = -\infty$ não será
satisfeita.

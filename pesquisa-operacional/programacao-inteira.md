# Programação Inteira
L Wolsey, Integer Programming, chap 1-2

## Tipos de problemas
Dado o PPL:
$$
max\{cx: Ax \leq b, b \geq 0\}
$$

1. Se **algumas** variáveis de decisão devem assumir valores inteiros, então
  temos um Problema de Programação Linear Inteira Mista.
2. Se **todas** as variáveis de decisão devem assumir valores inteiros, temos
  um Programa Inteiro.
3. Se todas as variáveis deve assumir valores 0 ou 1, então temos um Programa
  Binário.

### Problemas de Otimização Combinatória
É um tipo de problema formulado com base em:
- um conjunto base $N=\{1,2,\ldots,n\}$
- pesos $\{c_j: j\in N\}$ associados aos elementos do conjunto base.
- Uma família $F$ de subconjuntos de $N$ que definem quais são os subconjuntos
  viáveis.

Então o POC é definido por:
$$
\text{(POC) } min \Big\{\sum_{j\in S}c_j: S\in F\Big\}
$$

## Formulação de IPs e MIPs
### Qualidade de uma formulação:
A definição de qualidade de uma formulação, essencialmente, depende dos limites
duais que essa formulação é capaz de fornecer.

### Processo
Dividido em duas etapas:
- Escolher as variáveis de decisão, identificando o tipo de cada uma delas.
- Representação o conjuntos de restrições e também da função objetivo


### Problema da mochila 0-1
**Formulação Inteira**
$$
max\Big\{\sum^n_{j=1}c_jx_j: x\in P \cap B^n\}\\
\text{em que } P\text{ é uma regiao definida por}\\
\sum^n_{j=1}a_jx_j \leq b
$$
Ainda é possível fazer a **relaxação linear**, de forma que ao invés
de exigir que $x: P \cap B^n$ ($x$ seja binário) solicitamos que $X\in [0,1]$.
Desa maneira, não temos apenas valores discretos


**Formulação Combinatória**\
Uma outra abordagem de formulação do problema da mochila é por formulação
combinatória.
Então ao invés de selecionar quais objetos a mochila irá carregar por meio
de uma multiplicação entre o peso do objeto e um numero binário, podemos
validar essa otimização por uma combinação a qual selecionamos a melhor
combinação entre o conjunto de todos os objetos disponíveis para se carregar
na mochila.\
**Conjunto base**(indices dos elementos): $N=\{1,\ldots,n\}$\
**Pesos**(objetos): $\{c_j: j \in N\}$\
**Famílias de subconjuntos**: $F$ que é dado por:
$$
F = \{ S \subseteq  S: \sum_{j\in S} a_j \leq b \}
$$
Isso quer dizer que $F$ é o conjunto de subconjuntos que obedecem à restrição
de não superar o peso máximo possível da mochila.
Por fim nossa solução é dada por:
$$
\text{(POC) } max \Big\{ \sum_{j\in S}c_j: S \in F \Big\}
$$

### Problema do caixeiro viajante, assimétrico
Assimétrico no sentido em que dadas duas cidades diferentes $i,j$, o custo da
viagem $c_{ij}$ que parte de $i$ com sentido a $j$ não tem o mesmo custo da
viagem que parte de $j$ em direção a $i$.
Em outras palavras $c_{ij} \neq c_{ji}$.

O problema é modelado de maneira que uma instância é um grafo (completo ou
esparso) $D(N, A)$ em que $N$ é o conjunto de pontos do grafo e $A$ é o
conjunto de arestas deste grafo.
Além disso, vamos demonstrar algumas propriedades:
- $\delta^+(S)$: Representa o conjunto de arestas que partem dos pontos $S$,
  mas os vértices de destino não podem pertencer a $S$.
- $\delta^{-}(S)$: Representa o conjunto de arestas que chegam nos pontos de
  $S$ e que os vértices de partida não pertencem a $S$.
- $\delta^{+(i)$: Representa o conjunto de arestas que partem do ponto $i$.
- $\delta^{-}(i)$: Representa o conjunto de arestas que chegam no ponto $i$.

**Formulação Inteira**\
Variáveis de decisão:
- um conjunto $X$ composto pelos elementos $x_{ij}$ 
em que cada elemento possui um valor binário que indica a existência
de uma rota partindo de $i$ em direção a $j$.

Restrições:
- Restrição de grau: Indica que todos os nós do grafo devem possuir grau de
  entrada e grau de saída iguais a 1:
  $$
    \sum_{(j,i)\in \delta^-(i)}^{j\neq i} x_{ij} = 1,\ \forall i\in N\\
    \sum_{(i,j)\in \delta^+(i)}^{j\neq i} x_{ij} = 1,\ \forall i\in N
  $$
- Restrição de Conexidade (evita subciclos):
  $$
    \sum_{(i,j)\in\delta^+(S)}x_{ij} \geq 1,\ S \subset N,\ S\neq \empty
  $$
- Natureza binária: $x_{ij} \in \{0,1\}$

Função objetivo:
$$
\text{min }\sum_{(i,j) \in A}c_{ij}x_{ij}
$$

Existe ainda a Formulação inteira na versão compacta para esse problema.

### Comparando Formulações de Programação inteira.
A qualidade de uma formulação é medida com base na qualidade dos limites
duais associados.
Ou seja, deve-se verificar qual formulação fornece limites duais mais fortes
para qualquer instancia do problema.
Então dado um problema de programação inteira, basta obter a relaxação linear
de tal problema e validar qual deles é o mais próximo do valor ótimo $z*$.
Um outro aspecto analisado na qualidade da formulação é o esforço computacional
necessário para avaliar tal limite dual.


### Uncapacitated Lot Sizing problem
Consiste em definir um plano de produção de mínimo custo, para um único
produto, em um período de tempo de $n$ períodos.
Além do estoque inicial do produto, $s_0$, os seguintes dados são conhecidos:
- $f_t \geq 0$: Custo fixo, caso haja produção no período $t$.
- $p_t \geq 0$: Custo unitário de produção em $t$.
- $h_t \geq 0$: Custo unitário de estoque em $t$.
- $d_t$: demanda a ser satisfeita em t.

Variáveis de decisão:
- $x_t \geq 0$: quantidade produzida em $t$.
- $s_t\geq 0$: quantidade de estoque ao fina de $t$.
- $y_t \in \{0,1\}$: 1 indica se houve produção em $t$, 0 indica o contrário.
  
Aspectos importantes:
- Garantir o balanço de fluxo em cada instante de tempo $t$.
- Garantir que o custo fixo seja incorrido em $t$ se houver produção.
  Em outras palavras, se $x_t > 0$ então $t_t = 1$.

Limite superior:
Assumimos um limite superior que é igual a $M = \sum^n_{t=1}d_t$ com $s_n =0$
e que tal limite superior é conhecido em cada tempo $t$.

**Modelo 1**:
$$
  \text{min }\Big\{ \sum^n_{t=1}p_tx_t + \sum^n_{t=1}h_ts_t + \sum^n_{t=1}f_ty_t:
    (x, s, y) \in P_1 \cap (\R^n \times \R^{n+1} \times B^n)\Big\}
$$

Em que $P_1$ é a região poliédrica:
$$
s_{t-1} + x_t = d_t+s_t, t=1, \ldots, n\\
x_t \leq My_y, t=1,\ldots, n\\
s_0 = 0\\
s_t, x_t \geq 0\\
0 \leq y_t \leq 1, t=1, \dots, n.
$$
Para cada um dos termos somatórios da função objetivo, observamos os três
fatores que desejamos minimizar.


A função objetivo pode ser reescrita se tomamos que a o estoque disponível em
um tempo $t$ é fruto da diferença entre a demanda $d_t$ e a produção $x_t$.
Dessa maneira, podemos reescrever:
$$
\sum^n_{t=1}c_tx_t + \sum^n_{t=1}f_ty_t- K\\
\text{tal que } K = \sum^n_{t-1}h_t\sum^t_{i=1}d_i
\text{ e } c_t= p_t+\sum^n_{t=1}h_i
$$
Porém para tal formulação, assumimos que $s_0=0$ e que não há transporte de
estoque entre os períodos.
Em outras palavras, assumimos que em cada período de tempo, a produção é
exatamente igual à demanda.


**Modelo 2**:\
Variáveis de decisão:
- \{$w_{it}\geq 0, i=1,\ldots, n\text{ e } t=i, \ldots, n\}$: Corresponde à
  quantidade produzida no período $i$ para atender à demanda do período $t$.
- $y_t$: é a mesma variável binária definida no modelo 1.

Novas restrições:
- $\sum^t_{i=1}wit = d_t$
- $w_{it} \leq d_ty_i\ \ t=i,\ldots, n$
- $w_{it} \geq 0,\ \ t=i,\ldots, n$
- $y_t \in \{0, 1\}$

Função objetivo:
$$
\text{min }\sum^n_{i=1}\sum^n_{t=1}c_iw_{it} + \sum^n_{t=1}f_ty_y
$$

#### **Comparando modelos**
Para comparar os dois modelos do Uncapacitated Lot Sizing, vamos tomar o limite
dual baseado na relaxação linear de ambos os modelos.
Assim, desejamos observar se a partir de tal relaxação é possível encontrar
algum ponto no poliedro o qual pertença a um modelo mas não pertença ao outro.
Esse ponto determinará que o modelo que possui tal ponto em seu poliedro de
restrições é o modelo mais fraco.

Considerando a seguinte solução fracionária:
- $x_t = d_t$
- $y_t = \frac{d_t}{M}$
- $t = 1, \ldots, n$.

Tal solução satisfaz as restrições que definem $P_1$(poliedro do modelo 1).
- $s_{t-1} + x_t = d_t + s_t\ \rightarrow$ como definimos que a demanda sempre
  seria atendida pela produção sem que haver excedentes, temo que $s_t = 0$.
  Logo a restrição é atendida
- $x_t \leq My_t\ \rightarrow$ como $y=\frac{d_t}{M}$ temos que
  $d_t \leq M\frac{d_t}{M}$ o qual $x_t = d_t$, portanto a restrição é
  satisfeita.
- $x_t \geq 0,\ 0\leq y_t\leq 1$ é satisfeito pois como $x_t =d_t$ e a demanda
  é um valor não negativo, $x_t \leq 0$. E também temos que $M \geq d_t$, uma
  vez que $M$ é o limite superior da produção, ou seja, o máximo a se produzir
  para atender toda a demanda, logo $0 \leq y_t = \frac{d_t}{M} \leq 1$.

Porém ao lidarmos com $P_2$, observamos que:
- $w_{ii} = d_i,\ w_{it}=0\ \rightarrow$ como não há produção em excesso para
  o estoque, $w_{it}$ para $i\neq t$ é sempre 0.
- $w_{it} \leq d_ty_i\ \rightarrow$ quando $i=t$ temos $d_i = w_{ii} < d_iy_i$
  $= d_i(\frac{d_i}{M}) < d_i$ o  **que é impossível**, uma vez que $d_i \div M$
  é um numero menor que $1$.

Portanto, há um ponto em $P_1$ que não está presente em $P_2$, então o método
$P_1$ não pode ser melhor do que $P_2$.
Entretanto, devemos analisar se qualquer ponto em $P_2$ também está presente em
$P_1$.

### Resolvendo um IP ou COP

Dado um problema
$$
z =\Big\{\text{max }c^Tx: x\in X \subseteq \Z^n \Big\}
$$
para comprovar que ele foi resolvido, devemos:
- Obter uma solução viável $x^* \in X$
- Garantir que $c^Tx\leq c^Tx^*$ para qualquer $x\in X$

Isso requer encontrar uma solução viável $x^*$ (que no caso de maximização)
fornece um limite inferior válido para o valor ótimo.
Ou seja, se o valor ótimo é $z^*$, então no caso do problema de maximização,
$c^Tx^* \leq z^*$.
Esse limite inferior é denominado, **solução primal**
Além disso, devemos encontrar um limite superior para o valor ótimo $z^*$,
o qual é chamado de **solução dual**.
Em outras palavras, se $x^*$ é a solução primal (limite inferior, no caso de
maximização) e $x^{**}$ é a solução dual (limite superior no caso de
maximização), temos:
$$
\bar{z} = c^Tx^{**}\\
\underline{z} = c^Tx^{*}\\
\text{em que: } \underline{z} \leq z \leq \bar{z}
$$

Quando temos que $\underline{z} = \bar{z}$, temos que os limites inferiores
e superiores são iguais, portanto, encontramos o valor ótimo.
Neste caso, $x^* = x^{**}$, que é a solução ótima do problema.

#### **Estrutura de um algoritmo exato**
- Gera uma sequencia não crescente de limites superiores $\{\bar z^k\}$
  válidos.
- Gera uma sequencia não decrescente de limites inferiores $\underline{z}^k$
  válidos.
- Quando a condição $\underline{z}^k = \bar{z}^k$ é atendida, então o algoritmo
  para, uma vez que isso é um certificado de otimalidade.

> Do contrário, se o critério de parada é:
  $\frac{\underline{z}^k-\bar{z}^k}{\underline{z}^k} \leq \epsilon$, então temos
  uma solução dita: $\epsilon$-ótima. Tratando-se de um algoritmo com garantia
  de distância.

Os algoritmos exatos devem possuir procedimentos capazes de gerar soluções
viáveis (**limites primais**), como as heurísticas.
E também ser capaz de obter os **limites primais**, por exemplo o mecanismo de
relaxações.
As relaxações produzem um limite superior que o qual todos os limites viáveis
possíveis, são pontos internos à relaxação.
Uma vez que há limites muito bem definidos em problema de programação inteira,
é possível determinar uma envoltória convexa dada pelo poliedro de restrições
$P$ do problema de otimização.

#### **Construindo relaxações para obter limites duais**
Vamos abordar o caso de maximização, no caso estamos buscando um limite
superior:\
A idéia central consiste em substituir o problema original por um problema
mais fácil de ser resolvido.
Esse problema mais fácil de se resolver, deve possuir uma função objetivo
capaz de entregar um valor não menor (idealmente maior) do que $z$.
O problema relaxado é dado por:
- Ampliação do conjunto de soluções viáveis.
- Substituição da função objetivo por outra função que assuma um valor não
  menor que a original em qualquer solução no domínio do problema original

**Definição de relaxação**:\
Dizemos que um problema de otimização:
$$
z^R = \text{max } \{f(x): x \in T \subseteq \R^n\}
$$
é uma relaxação para o problema
$$
z = \text{max }\{ c^Tx: x \in X \subseteq \R^n\}
$$
se as seguintes duas condições são atendidas:
- $X\subseteq T$: Isso quer dizer que o conjunto de soluções viáveis do
  problema relaxado contem todo o conjunto da soluções do problema
  original.
- $f(x)  \geq c^T\ \forall x \in X$: No caso de maximização, estamos procurando
  um limite superior para o problema original.

> Observe que $x \in \R^n$ mesmo no problema original.
  Isso se dá por conta que podemos lidar com problemas mistos, e não apenas
  problemas puramente inteiros.

## Relaxações

#### **Relaxação Linear**
Dado o **IP**
$$
z = \{ \text{max }c^Tx: x\in P \cap \Z^n\}
$$
e a formulação
$$
P = \{x\in \R^n: Ax \leq b\}
$$

A relaxação linear associada ao **IP** corresponde ao programa:
$$
z^{LP} = \{\text{max } c^Tx: x \in P\}
$$

**Comparando duas relaxações lineares**:\
Dadas duas relaxações lineares com formulações $P_1$ e $P_2$, se $P_1$  é
melhor do que $P_2$ isso quer dizer que $P_1 \subset P_2$ e por consequência
$z^{P_1} \leq z^{P_2}$.
Ou seja, a melhor relaxação está contida no espaço da pior, e por isso, a
melhor relaxação pode fornecer limites duais mais justos.

> se a relaxação linear é **INVIÁVEL** então o **IP** é inviável.
  Inviável = sem solução viável.

#### **Relaxação combinatória**

Um bom exemplo é o problema do caixeiro viajante assimétrico.
O qual é dado por um digrafo $D = (N, A)$ e os custos associados a cada aresta
$\{c_{ij}: (i, j) \in A\}$:
$$
\text{min } \Big\{\sum_{(i,j)\in A}x_{ij}c_{ij}: x \in P_x \cap B^{|A|}\Big\}
$$
em que $P_x$ é definido por:
$$
\sum_{(j,i)\in \delta^-(i)}x_{ij} = 1, i\in N\\
\sum_{(i,j)\in \delta^+(i)}x_{ij} = 1, i\in N\\
\sum_{(i,j)\in \delta^+(S)}x_{ij} = 1,  \forall S \subset S, S \neq \empty\\
x_{ij} \geq 0,(i,j) \in A
$$

A terceira restrição é a responsável por impedir a existência de sub ciclos,
então uma possível relaxação combinatória seria  remoção desta restrição.
Dessa maneira, a obtenção de uma solução é mais computacionalmente mais fácil
e ainda assim pode-se obter um limite dual melhor, uma vez que, para este
caso o limite dual será um limite inferior, pois tem-se um problema de
minimização.

Em resumo, a relaxação poderia ser dada por um poliedro $P_{atrib}$:
$$
\sum_{(j,i)\in \delta^-(i)}x_{ij} = 1, i\in N\\
\sum_{(i,j)\in \delta^+(i)}x_{ij} = 1, i\in N\\
x_{ij} \geq 0,(i,j) \in A
$$
em que a restrição que impede a existência de subciclos é removida.
Ainda assim, $P_x \subset P_{atrib}$, porém $z \geq z^{atrib}$, pelo fato de
trabalharmos com um problema de minimização,


### Relaxação Lagrangeana
Considerando o **IP**
$$
z=\{\text{max } c^Tx: Ax \leq b, x\in S \subseteq \Z^n\}
$$

Suponha que a restrição $Ax\leq b$ seja um dificultador do problema, que o
torna, por exemplo um problema NP-Hard.
Então o intuito é relaxar esse conjunto de restrições, a fim de facilitar a
solução.
Na Relaxação Lagrangeana, para cada restrição relaxada, associamos um índice
$i$ a um multiplicador $u_i$, sendo que esse índice será multiplicado por cada
restrição que foi relaxada.
Ou seja: $u_i(b_i - a_i^Tx)$, em que $a_i$ é uma linha da matriz $A$, das
restrições que serão relaxadas.
Por fim, a função objetivo do problema será o somatório do produto
$u_i(b_i - a_i^Tx)$ somado a $c^Tx$:

$$
c^Tx + \sum^m_ {i=1}u_i(b_i - a_i^Tx)
$$
com as restrições:
$$
x \in S \subseteq \Z^n
$$

Em resumo, o problema relaxado pela relaxação de lagrange (PLAG) é:
$$
z(u) = \text{max }\{c^Tx + u^T(b-Ax): x \in S\}
$$
em que temos:
- $z(u) > z,\ \forall u \geq 0$
- O termo $u^T(b-Ax)$ é chamado de dualização das restrição.

## Dualidade em Programação inteira:
Dado um **IP** $(P)\ z = \{$max $c^Tx: ax \leq b, x\in \Z^n_+\}$ e um problema
linear $(D)\ w^{LP}=\{$min $u^Tb: u^TA \geq c^T, u \in \R^m\}$.
Esses problema formam um par primal-dual.
Em resumo, o problema $D$ é o dual da relaxação linear de $P$, e temos que
a relação de dualidade fraca se mantém apesar de $D$ ser derivado a partir de
outro problema.
A razão para isso é: imagine que a relaxação linear de $P$ tenha um valor ótimo
$z^{LP}$, então como $D$ é o dual dessa relação, temos que $w^{LP}$ é um limite
(no caso de maximização) superior de $z^{LP}$.
Sabemos que $z \leq z^{LP}$ por conta da relaxação linear e também que
$z^{LP} \leq w^{LP}$, portanto $z \leq z^{LP} \leq w^{LP}$, e 
$w^{LP}$ é um limite para $z$ também, comprovando a dualidade.

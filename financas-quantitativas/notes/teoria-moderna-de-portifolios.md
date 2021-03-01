# Teoria Moderna de Portfolios

## Introdução
- Levar em conta não apenas o retorno, mas o risco associado a determinadas
  alocações de capital.
- Risco é derivado da incerteza
- Cada indivíduo possui tolerâncias a risco diferente de outros.

> Não existe um portfolio ideal, existem conjuntos de portfolios que podem se
  encaixar para determinados casos.

## Portfolio com 2 ativos
- Estimar valores através dos retornos históricos de dois ativos.
- Deve-se realizar suposições, que são subjetivas e dependem de análises
  financeiras.

### Suposições adotadas na teoria dos portfolios:
- Retornos são estacionários em covariância e ergódicos.
  Além disso, possuem uma distribuição conjunta normal no horizonte de
  investimento.
- Investidores conhecem os valores: média, variância e covariância dos ativos.
- Investidores se preocupam apenas com o retorno esperado e variância esperada
  do portfolio.

Partindo dessas premissas, temos que o investidor se preocupa apenas com o
retorno e com o risco associado ao portfolio, logo as variáveis que importam
em um portfolio são: retorno esperado e variância.

**Dominância de portfolios**:\
Um portfolio domina o outro (é melhor), ser o retorno é maior e a variância é
menor.
Ou seja, maior ganho associado a um risco menor.
Então imaginando uma série de portfolios (com apenas 2 ativos), pode-se criar
uma sequência de pesos tal que permita analisar a melhor escolha entre o peso
que cada ativo terá nesse portfolio.
Ao analisar um gráfico *retorno esperado* vs. *variância* observaremos que há
um ponto de variância mínima global.
Logo, todos os pontos inferiores à tal variância, são dominados pelas escolhas
de que determinam os pontos superiores à variância mínima global.
Entretanto, tomando 2 pontos quaisquer superiores à variância mínima global,
não é possível determinar qual é o dominante, uma vez que um maior risco
(variância) resultará num melhor retorno.

Para determinar a variância mínima global, devemos resolver um problema de
otimização.
$$
\begin{array}{rl}
\text{min} & \sigma^2_p = w^2_A\sigma^w_A + w^2_B\sigma^2_B +
  2w_Aw_B\sigma_{AB}\\

\text{sujeito a} & w_A+w_B=1
\end{array}
$$

## Modelo geral de Markowitz
Assuma que existam $N$ ativos que podem fazer parte do portfolio, com retornos
esperados $\mu_i = E[R_i]$.
Um portfolio é definido por um conjunto de pesos (proporções)
$(w_1, \ldots, w_n)$ em que $w_1+ \ldots + w_n = 1$, sendo que *shorting* é
permitido. Então pode haver pesos negativos.
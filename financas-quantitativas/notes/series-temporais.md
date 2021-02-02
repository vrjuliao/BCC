# Séries temporais

[Aula 7](https://www.youtube.com/watch?v=3PqhYpbtaY8&list=PLzOdjHdjXlbSoUt5qe-2HBG6RlD5JryJN&index=14)

## Processo estocástico

É uma sequência de variáveis aleatórias indexadas no tempo.
  - Espaçamento do tempo: Constante e regular, os pontos são distribuídos
  igualmente no tempo. O tempo é **DISCRETO**, ou seja, há uma quantidade
  finita e bem definida de pontos.
  
**Realização do processo estocástico**\
$\{y^t\}^{T}_{t=1}$: observação de um processo estocástico
  - **Objetivos**:
    1. Descrever o comportamento probabilístico.
    2. Observar e estimar características dadas pela amostra, inclusive a
    dependência temporal.

  A **realização de um processo estocástico** demanda a utilização de suposições:
  1. Amostras aleatórias são modeladas como sequencias de variáveis
  **independentes e identicamente distribuídas (iid))**.
  Porém para séries temporais, no escopo financeiro, isso não é tomado como
  premissa.
  2. Em séries temporais:\
    - Preservar a suposição de distribuições idênticas.\
    - Não impor independência: O objetivo é que possamos prever o comportamento
    futuro daa a dependência com os dados passados.
  3. O comportamento de distribuições identicas **dependentes** é permitido pelo
  conceito de **estacionariedade** e **ergodicidade**.

### Processos estocásticos estacionários

**Estacionariedade estrita**:\
Tomando um número fixo $n$ de pontos do espaço, a distribuição conjunta desses
pontos depende apenas da diferença entre os pontos, mas não do tempo $t$.
Ou seja:\
Dados os pontos $(Y_{t1}, Y_{t2}, ..., Y_{tn})$ o valor da distribuição
conjunta desses pontos, não depende do tempo $t$.

Além disso a distribuição deve ser invariante no tempo.
Isso quer dizer que tomado os tempos $tj$ e $ti$, em que $i,j$ são índices de
quais instantes do tempo são utilizados no subconjunto:
a distribuição conjunta de $Y_{tj} = Y_{ti}$ em que $ti - t(i+1) = tj-t(j+)$.
Por exemplo: $(Y_{1}, Y_{5}, Y_{7} = Y_{12}, Y_{16}, Y_{18})$.

Por fim: Processos estritamente estacionários a correlação entre $Y_t$ e
$Y_{tr}$ depende somente de $t- tr$ e não diretamente de $t$.\
Outra observação é que qualquer função dos elementos de $Y_t$ gera um outro
processo estacionário. Por exemplo $Y^{2}_t$ é também um processo estacionário,
desde que $T_t$ também seja.

- Se ${Y_t}$ é uma sequência **iid** então ela é estritamente estacionária.\
  Seja ${Y_t}$ uma sequência iid e $X ~ N(0, 1)$ independente de ${Y_t}$, então
  $Z_t = Y_t + X$ é uma sequência independente mas também idêntica, logo é
  estritamente estacionária.

**Estacionariedade em covariância**\
Um processo estocástico ${Y_t}^T_{t=-\infty}$ é estacionário em covariância se:
1. $E[Y]$ não depende de $t$.
2. $var(T_t)=\sigma^2$ não depende de $t$.
3. $cov(Y_t,Y_{t-j} = \gamma_j)$ é finita e depende apenas de $j$ mas não de
$t$.
O termo $\gamma_j$ é denominado **autocovariância** de $j$-ésima ordem.

Já a **autocorrelação** de $j$ésima ordem é dada por:
$\rho_j=\Large{\frac{\gamma_j}{\sigma^2}}$.\
Vale lembrar que: Autocovariância $\gamma_j$ mede a direção da  dependência
linear entre $Y_t$ e $Y_{t-j}$.
Já a autocorrelação $\rho_j$ mede a direção e a intensidade da dependência
linear.


#### Ruído Branco Gaussiano (GWN)
É um processo estocástico estacionário em covariância.
Lembra uma série de retornos.
É definido por: ${Y_t} \sim iid\ N(0, \sigma^2)$, ou resumidamente:
$Y_t~GWN(0,\sigma^2)$.
1. $E[Y_t] = 0$: observe a definição da normal com média 0.
2. $var[Y_t] = \sigma^2$: não depende de $t$.
3. $cov(Y_t,Y_{t-j} = 0$: para $j>0$ independentemente de $t$, uma vez que
cada $Y_t$ é independente.

#### Ruído Branco Independente (IWN)
Assim como o GWN, é um processo com média 0 e variância $\sigma^2$.
Entretanto não segue uma distribuição normal.
Ou seja, $Y_t \sim iid\ (0, \sigma^2)$.

#### Ruído Branco Fraco (WN)
Assim como o GWN, é um processo com média 0 e variância $\sigma^2$.
Entretanto, não há a necessidade dos valores serem iid.
Aqui basta que os valores $Y_t$ sejam **não correlacionados**.
Então uma série de WN é dada por $\{Y_t\}^Y_{t=-\infty}$ em que
$Y_t \sim WN(0, \sigma^2)$.\
Isso permite dependência temporal não linear.

**Processos estocásticos não estacionários**
Se algum a média, variância ou a covariância são dependentes do tempo, então
um processo estocástico é não estacionário.

#### **Passeio Aleatório (random walk)**
Lembra muito uma série de preços.
$Y_t = Y_{t-1}+\epsilon,\ \epsilon\sim IWN(0,\sigma^2_{\epsilon})$, sendo
$Y-0$ fixo (não aleatório).\
Por substituição recursiva, $Y_t = Y_0 + \sum^t_{j=1}\epsilon_ j$.\
Com essa observação temos que o valor esperado $E[Y_t]$ não depende de $t$, 
uma vez que os termos $\epsilon$ são independentes, então temos:
1. $E[Y_t]=Y_0$.
2. Porém $var(Y_t) = var(\sum\epsilon_j) = \sum\sigma^2_\epsilon =$
   $\sigma^2_\epsilon \times t$. LOgo a variância depende de $t$, assim esse é
   um processo não estacionário.


## Ergodicidade
Na análise de processos estocásticos em covariância não há maneiras de fazer
suposições sobre a intensidade da dependência entre as variáveis na sequência.\
Porém de forma razoável, pode-se admitir que a intensidade da dependência
diminua de acordo com a distância no tempo.
Ou seja, para um $t=1$ há um $j$ suficientemente grande o qual a dependência
entre $Y_t$ e $Y_{t+j}$ é muito próxima de 0.
> Um processo estocástico $\{Y_t\}^\infty_{t=-\infty}$ é ergódico se quaisquer
duas coleções de variáveis aleatórias distantes no tempo são essencialmente
independentes.

Quando não há o decaimento da **autocovariância**, temos que o processo é não
ergódico.

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

## Modelos de séries temporais
Os dois modelos são estacionários em covariância e ergódicos

### **Média Móvel**
**MA(1): Moving Average 1**\
Ou então **média móvel de primeira ordem**.\
Suponha o processo estocástico $\{Y_t\}$ estacionário em covariância e ergódico
em que:
  1. $Y_t$ e $T_{t-1}$ são correlacionados
  2. Mas $Y_t$ e $T_{t-j}$ para $j>1$ não são correlacionados.

Esse processo é descrito por:
$$T_t = \mu + \epsilon_t + \theta\epsilon_{t-1}$$
para $-1<\theta<1$ em que $\epsilon\sim iid\ WN(0, \sigma^2_\epsilon)$.

Em resumo observe que $Y_t$ depende do $\sigma$ do período anterior, ou seja,
para médias móveis de primeira ordem, a dependência dura apenas um período de
tempo.
Para esse caso temos que $\theta$ é o sinal e a magnitude da correlação entre
$T_t$ e o processo anterior.

Para observar que **MA(1)** é estacionário em covariância:
1. Média: $E[Y_t] = \mu + E[\epsilon_t]+\theta E[\epsilon_{t-1}] = \mu$.\
  Uma vez que $\epsilon$ segue um WN com média 0, temos que os valores
  das esperanças que envolvem $\epsilon$ são iguais a 0.
2. $var(Y_t) = \sigma^2_\epsilon + \theta^2\sigma^2_\epsilon$.
3. $\gamma_1 = cov(Y_t, T_{t-1}) = \theta\sigma^2_\epsilon$


**MA(q): Moving Average q**\
Quando há uma dependência temporal para um período de tamanho $q$.s

### **Modelo autorregressivo - AR(1)**
A característica principal de um modelo autorregressivo é tal que dada um $Y_t$,
a dependência de $Y_t$ para um $Y_{t-j}$ diminui (tendendo a 0) à medida que
$j$ cresce.
Ou seja, quão maior o período entre dois pontos, menor a dependência entre
estes.

Um modelo autorregressivo é definido  por:
$$T_t-\mu = \phi(Y_{t-1} -\mu) + \epsilon_t$$
Tal que $-1 < \phi < 1$ e $\epsilon_t \sim WN(0, \sigma^2_\epsilon)$.

Quanto a condição $-1 < \phi < 1$ é satisfeita, temos que o modelo AR(1) é
ergódico e estacionário em covariância.
É importante sustentar que $\phi$ determina o sinal e intensidade da correlação
entre $Y_t$ e $Y_{t-1}$.

### **Modelo ARMA$(p, q)$**
Combinação entre processos AR(p) e MA(q), resultando em um processo estocástico
autorregressivo de médias móveis.
Uma série temporal $\{Y_t\}^\infty_{t=-\infty}$ é uma série ARMA quando ela
generaliza processos AR e MA.

## Integração

Dados macroeconômicos e financeiros, normalmente, possuem tendência de alta.
Por exemplo a inflação.
A própria não estacionariedade dos dados é possivelmente  a manifestação de uma
tendência.
Uma série nào estacionária possui:
- Uma tendência determinística $\mu\times t$.
- Uma tendência estocástica $\sum^{t-1}_{i=0}\epsilon_{t-i}$.

Uma forma simples de transformar uma série não estacionária em uma séria
estacionária é através do processo de diferenciação:\
Se uma série precisa ser diferenciada $d$ vezes para se tornar estacionária,
então dizemos que tal série é **integrada em ordem** $d$.
Quando a série já é estacionária, ela é integrada em ordem 0.

Há o processo contrário da integração, que é a **soma cumulativa**, ou seja,
partir de uma série $I(d)$ e chegar a uma série $I(d+1)$

Pode-se executar o teste de Dicky Fuller para validar se uma série é
estacionária ou não.
Para tal teste, quando o *p-value* é pequeno (próximo de 0), existe grande
chances da série ser estacionária.

### **Modelo ARIMA$(p, d, q)$**
Processos autorregressivos integrados de médias móveis.
É uma generalização dos processos ARMA, o qual recebe também um terceiro
parâmetro $d$, que informa a ordem de integração da série.

## Cointegração
Uma combinação linear de séries temporais $(Y^1_t, Y^2_t, ..., Y^k_t)$ gera uma
nova série $Y_t$ construída da seguinte forma, para quaisquer conjunto de números
reais $b_1, b_2, ..., b_k$:
$$Y_t = b_1Y^1_t+b_2Y^2_t+...+b_kY^k_t$$

Se todas as séries são I($n$) para $n>0$, e alguma combinação linear entre elas é
I($n-1$), diz-se que tal conjunto de séries temporais é **cointegrada**.

**Teste de Engle-Granger**:\
Testar se duas séries são cointegradas.
- Dadas duas séries $X$ e $Y$.
- Verifique através de algum teste estatístico se ambas são I(1).
- Resolva o método dos quadrados mínimos para a regressão:\
  $Y=\beta_0 + \beta_1X+\epsilon$
- Verifique se a série de resíduos $\epsilon=Y-\beta_0-\beta_1X$ é I(0).


## Arbitragem estatística
É um contraponto ao conceito tradicional de arbitragem (determinística).
Na arbitragem tradicional, lucro garantido pode ser obtido ao comprar ativos e
vender (short) outros a descoberto.
Porém, em arbitragem estatística, observamos uma variação estatística na
precificação teórica de um ou mais ativos.
Na arbitragem estatística, buscamos identificar desvios de preços (ou relações)
na esperança que a tendência do desvio será revertida, gerando oportunidade de
lucro.

Uma das fórmulas de encontrar tais oportunidades é através da cointegração.
Suponha um ativo $A$ e outro ativo $B$ em que $A$ apresenta um bom valor de
entrada.
Porém você especula ou recebe uma análise de que $B$ terá um bom resultado nos
próximos dias.
Então decide realizar um teste de cointegração entre $A$ e $B$, e percebe que
ambos ativos são cointegrados entre si.
Assim, há você decide comprar $A$ uma vez que o valor de entrada é mais favorável.

Outro exemplo:\
Suponha que outros dois ativos $G$ e $H$ são cointegrados.
Então temos que há uma relação linear entre a série de $G$ e de $H$, tal que
$Z = G - 2H$.
Tome como base que $E[Z] = 0$, então se temos que em $P_{G, t-1} = 10$ e
$P_{H, t-1} = 5$ com $P_{G, t} = 11$, observamos pelo valor da esperança de $Z$
que $P_{H, t} = 5.50$, para assim satisfazer a equação linear.
Por fim, a partir dessa observação, podemos realizar alguma estratégia para
entrar em *long* em um ativo e *short* em outro de forma a proteger a carteira.

### **Modelos ARCH**
ARCH: **A**uto**r**egressive **C**ondidional **H**eteroskedasticity.

- Heteroscedasticidade: séries temporais em que a variância (ou alguma outra
  medida de dispersão) não é constante ao longo do tempo.
- Homoscedasticidade: inverso da anterior, em que as medidas de dispersão
  são constantes no tempo.

Há uma sugestão de que a volatilidade atual depende de alguma forma das
volatilidades anteriores.
Retornos de ativos são imprevisíveis, com poucas evidências de correlação
linear.
Porém para volatilidade é possível de obter uma correlação.

**ARCH($q$)**:\
Suponha um processo estocástico $\{Y_t\}^\infty_{t=-\infty}$.
Esse modelo básico diz que a variância do processor $Y_t$ é condicional em
$Y_{t-1} até Y_{t-q}$.
No caso, o erro $\epsilon_t$ é dividido em dois termos: um desvio padrão
condicional $\sigma_t$, dependente do tempo, e um outro erro $z_t$.
Sendo que temos $\epsilon_t = \sigma_t z_t$ com $z_t\sim iid\ WN(0,1)$.

Como temos que a variância $\sigma^2_t$ depende dos períodos anteriores,
podemos expressar a $t$-ésima variância como:
$$\sigma^2_t = \alpha_0 + \sum^q_{j=1}\alpha_j\epsilon^2_{t-j}$$

**GARCH**:\
É a generalização do método ARCH, o nome já indica tal feito, uma vez que
GARCH é Generalized ARCH.
A diferença é quem no modelo ARCH a dependência ocorre no fator $\epsilon_t$,
porém neste modelo, a variância dependerá também das variâncias dos períodos
anteriores, ou seja:
$$
\sigma^2_t 
  = \alpha_0 
  + \sum^q_{j=1}\alpha_j\epsilon^2_{t-j}
  + \sum^q_{j=1}\beta_j\sigma^2_{t-j}
$$
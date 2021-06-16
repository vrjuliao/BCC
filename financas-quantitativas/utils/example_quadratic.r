
# Estas duas linhas de codigo abaixo alteram o diretorio
# corrente no RStudio para o diretorio onde este arquivo
# esta localizado.
#
# Este comando funciona apenas de dentro do RStudio.
script.dir <- dirname(sys.frame(1)$ofile);
setwd(script.dir);

# Carregar as funcoes do model.r, só funciona se estiver no
# diretorio corrente do R (alterado ali em cima)
source("model.r");

# Evitar que o print do R escreva em notação 
options(scipen=999);


# 
loadPackage("RCurl");
dataURL = "http://www.dcc.ufmg.br/~arbex/portfolios/IBOV.csv";
data = getURL(dataURL, ssl.verifypeer=0L, followlocation=1L);
prices = read.csv(text = data, header = TRUE, sep = ",", stringsAsFactors = FALSE);

# Otimizar Markowitz com dados de 2019
beg = which(prices[,1] > 20190000)[1];
end = which(prices[,1] > 20200000)[1];
prices = prices[beg:end,];

# Elimina empresas que possuem zeros
prices = prices[, colSums(prices == 0) == 0];

# Tira Datas, IBOV e BOVA11 (apenas ativos do índice)
assets = prices[,4:ncol(prices)];

# Temporario: usa apenas os primeiros 5 ativos
assets = assets[,1:5];

# Calcula matriz de retornos (cada coluna contém os retornos de um ativo)
returns = apply(assets, 2, function(x){diff(x)/x[-length(x)]} ); 

# Calcula vetor de retornos esperados e matriz de covariancias
N = ncol(returns);
mu = matrix(colMeans(returns), nrow=1)
colnames(mu) = colnames(returns);
Sigma = cov(returns);


# Retorno minimo esperado 0%
minExpectedReturn = 0;

# Inicializar um objeto que vai conter um modelo de otimização.
model = initialiseModel();

# O modelFilename permite exportar o modelo para um arquivo texto em
# formato lp. Somente arquivos que terminam com .lp são aceitos. O arquivo
# ajudar a debugar um modelo para saber se está correto.
model$setModelFilename("markowitz.lp");

# Devido à limitações do pacote quadprog, modelos quadráticos por enquanto:
#   - Não aceitam limite de tempo
#   - Não aceitam debug da saída do solver
#   - São sempre de minimização, nunca maximização
#   - Não aceitam variáveis inteiras ou binárias

# Criando variáveis w1, w2, ..., wn
# Cada variável possui 0 na parte linear da função objetivo e limites de 0 a 1.
for (i in 1 : N) model$addVariable(paste0("w", i), 0, 0, 1); 

# Adiciona covariance matrix
model$addQuadraticMatrix(Sigma);

  
# Restricao de retorno esperado minimo
#  colMeans tira a média das colunas da matriz cenários (retorno esperado de cada ativo)
elements = paste0("w", seq(1, N));
model$addConstraint(">=", minExpectedReturn, elements, mu, "retornoEsperadoMinimo");

# Soma dos pesos = 1
values   = rep(1, N);
model$addConstraint("=", 1, elements, values, "somaDosPesos");

# Test constraint, limit w1 to 30%
model$addConstraint("<=", 0.3, "w1", 1, "limitW1");
 
# TODO resolver o modelo
# TODO test export model
model$solve();

printf("\nSolver took %.2fs to be solved\n\n", model$solverTime);

if (model$solutionExists) {
    printf("Solution exists.\n\n");
} else {
    printf("Solution does not exist.\n\n");
}

printf("Solution status: %s\n", model$status);

if (model$solutionExists) {
    printf("Solution objective value: %.5f\n", model$objValue);
    printf("Solution variables:\n");
    for (i in 1 : model$numVariables) {
        val = model$getSolutionValue(model$variables[i]);
        printf(" Var %2s = %8.5f\n", model$variables[i], val);
    }
}

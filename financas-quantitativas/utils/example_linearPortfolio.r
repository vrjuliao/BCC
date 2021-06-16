
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

# Primeiro vamos gerar alguns dados sintéticos.
# 5 ativos, 30 cenários:
# Gerar retornos através de distribuições normais com pequenas alterações
#   na média e retorno esperados.
T = 30;
N = 5;
scenarios = matrix(0, ncol = N, nrow = T);
scenarios[,1] = rnorm(T, mean =  0.003, sd = 0.02);
scenarios[,2] = rnorm(T, mean =  0.006, sd = 0.04);
scenarios[,3] = rnorm(T, mean =  0.009, sd = 0.06);
scenarios[,4] = rnorm(T, mean = -0.001, sd = 0.08);
scenarios[,5] = rnorm(T, mean =  0.001, sd = 0.01);

# Retorno minimo esperado 0%
minExpectedReturn = 0.0;

# Imprimindo os cenarios
printf("%d cenários para os %d ativos:\n", T, N);
printf("Cenario");
for (i in 1 : N) printf(" %6d", i); 
printf("\n");
for (t in 1 : T) {
    printf("%2d     ", t);
    for (i in 1 : N) printf(" %6.3f", scenarios[t, i]);
    printf("\n");
}

# Inicializar um objeto que vai conter um modelo de otimização.
model = initialiseModel();

# O modelFilename permite exportar o modelo para um arquivo texto em
# formato lp. Somente arquivos que terminam com .lp são aceitos. O arquivo
# ajudar a debugar um modelo para saber se está correto.
model$setModelFilename("piorRealizacao.lp");

# Ao marcar a opção solverDebug como 1, é possível ver a saída do solver
# na tela. Por default esta opção é zero, ou seja, nada é impresso na tela.
# Pode ser útil especialmente em modelos lentos, para saber como anda o solver.
model$setSolverDebug(0);

# Tempo máximo, em segundos, que o solver pode ficar tentando resolver o modelo
# Se chegar no tempo máximo, o solver para e pega a melhor solução que tiver
# encontrado até aquele momento.
model$setTimeLimit(60);

# Agora vamos criar o modelo em si. Referir aos slides de cenários e modelos lineares.
model$setDirection(1);

# Adicionando a variável M e as variáveis w. Os parâmetros são o nome das variáveis, 
#   valores na função objetivo, limite inferior e limite superior.
model$addVariable("M", 1); 
for (i in 1 : N) model$addVariable(paste0("w", i), 0, 0, 1); 

# Aqui adicionamos as restrições. Os parâmetros são:

# Soma dos pesos = 1
elements = paste0("w", seq(1, N));
values   = rep(1, 5);
model$addConstraint("=", 1, elements, values, "somaDosPesos");
   
# Restricao de retorno esperado minimo
#  colMeans tira a média das colunas da matriz cenários (retorno esperado de cada ativo)
elements = paste0("w", seq(1, N));
values   = colMeans(scenarios);
model$addConstraint(">=", minExpectedReturn, elements, values, "retornoEsperadoMinimo");

# Restricoes para limitar o valor de M ao pior cenário possível:
for (t in 1 : T) {
    elements = c("M", paste0("w", seq(1, N)));
    values   = c(1, -scenarios[t, ]);
    model$addConstraint("<=", 0, elements, values, paste0("piorRealizacao", t));
}

# Resolvemos o modelo
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


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


# Inicializar um objeto que vai conter um modelo de otimização.
model = initialiseModel();

# O modelFilename permite exportar o modelo para um arquivo texto em
# formato lp. Somente arquivos que terminam com .lp são aceitos. O arquivo
# ajudar a debugar um modelo para saber se está correto.
model$setModelFilename("capitalBudgeting.lp");

# Ao marcar a opção solverDebug como 1, é possível ver a saída do solver
# na tela. Por default esta opção é zero, ou seja, nada é impresso na tela.
# Pode ser útil especialmente em modelos lentos, para saber como anda o solver.
model$setSolverDebug(0);

# Tempo máximo, em segundos, que o solver pode ficar tentando resolver o modelo
# Se chegar no tempo máximo, o solver para e pega a melhor solução que tiver
# encontrado até aquele momento.
model$setTimeLimit(60);

# Agora vamos criar o modelo em si. Vamos criar um modelo conhecido como Capital Budgeting.
# 
# Existem 4 tipos de investimento possíveis para um empresa:
#  O primeiro exige um aporte inicial de R$5 milhões, e trará um lucro de R$8 milhões.
#  O segundo exige um aporte inicial de R$7 milhões, e trará um lucro de R$11 milhões.
#  O terceiro exige um aporte inicial de R$4 milhões, e trará um lucro de R$6 milhões.
#  O quarto exige um aporte inicial de R$3 milhões, e trará um lucro de R$3 milhões.
# 
# Temos um orçamento de R$ 14 milhões para aporte inicial. Em quais projetos devemos investir de
# forma a maximizar o lucro final?
#
# Para o modelo definidos variáveis binárias, xi, que são 1 ou 0 se decidimos ou não investir no
# investimento i. Ou seja, precisamos de variáveis inteiras. O modelo é dado por:
#
# max 8 x1 + 11 x2 + 6 x3 + 3 x4
#
# sujeito a 
#     5 x1 +  7 x2 + 4 x3 + 3 x4 <= 14
#
#     x1, ..., x4 pertence a {0, 1}
#


# Definimos se é minimização ou maximização.
# 0 = min, 1 = max
model$setDirection(1);

# Adicionando as 4 variáveis binárias. Os parâmetros são o nome das variáveis e os valores das mesmas na função objetivo.
model$addBinaryVariable("x1", 8); 
model$addBinaryVariable("x2", 11); 
model$addBinaryVariable("x3", 6); 
model$addBinaryVariable("x4", 3); 

# Aqui adicionamos a restrição. Os parâmetros são:
#   o sinal da restrição ("<=", ">=" "=")
#   o valor do lado direito (rhs), no caso 14
#   as variáveis que tem coeficientes diferente de zero na restrição (vetor elements)
#   os valores dos coeficientes das variáveis, tem que ter a mesma dimensão do 
#      vetor elements.
#   Opcionalmente, um nome para a restrição.

elements = c("x1", "x2", "x3", "x4");
values   = c(5, 7, 4, 3);
model$addConstraint("<=", 14, elements, values, "restricao1");
    
# Resolvemos o modelo
model$solve();

printf("Solver took %.2fs to be solved\n\n", model$solverTime);

if (model$solutionExists) {
    printf("Solution exists.\n\n");
} else {
    printf("Solution does not exist.\n\n");
}

printf("Solution status: %s\n", model$status);
printf("Solution objective value: %.2f\n", model$objValue);
printf("Solution variables:\n");
for (i in 1 : model$numVariables) {
    val = model$getSolutionValue(model$variables[i]);
    invest = "do not invest";
    if (val >= 0.9999) invest = "invest";
    printf(" Var %s = %d (%s)\n", model$variables[i], val, invest);
}

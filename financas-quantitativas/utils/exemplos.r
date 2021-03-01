# Altera o diretorio corrente no RStudio para o diretorio deste arquivo
# so funciona no RStudio
script.dir <- dirname(sys.frame(1)$ofile);
setwd(script.dir);

source("graficos.r");

# Colocar 1 salva todas as figuras com o nome definido em cada uma, se for
# 0 os graficos aparecem dentro do RStudio e não são salvos como pdfs
saveAllGraphics = 1;

# EXEMPLO 1: Bar Chart
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$height    = 6;
ggOptions$width     = 7;
ggOptions$imageName = "Exemplo1.pdf";
ggOptions$axisTitleSize = 16;
ggOptions$axisLabelSize = 14;
ggOptions$xTitle = "Retorno";
ggOptions$yTitle = "";
ggOptions$title  = "Distribuição binomial com p = 0.5 e n = 5";
ggOptions$percentageInYAxis = 1;
ggOptions$removeXAxisSpace  = 0;
ggOptions$barChart = 1;
x = c(0, 1, 2, 3, 4, 5);
probabilities = c(0.03125, 0.15625, 0.31250, 0.31250, 0.15625, 0.03125)
plotGraph(probabilities, xValues = x, ggOptions = ggOptions);


# EXEMPLO 2: Normal com shaded area (multiplas shaded areas nao funciona)
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo2.pdf";
ggOptions$height = 7;
ggOptions$width  = 8;
ggOptions$xTitle = "X";
ggOptions$yTitle = "PDF";
ggOptions$title  = "Curva de probabilidade para variável aleatória contínua";
ggOptions$percentageInYAxis = 0;
ggOptions$lineChart = 1;
ggOptions$removeXAxisSpace  = 1;
ggOptions$lineSize = 0.7;
ggOptions$customColours = c("black");
ggOptions$xAxisBreaks = c(-3, -2, -1, 0, 1, 2, 3);
ggOptions$shadeAreaBegin = -2;
ggOptions$shadeAreaEnd   = 0;
set.seed(125);
dat <- with(density(rnorm(5000000, 0, 1)), data.frame(x, y))
plotGraph(dat, ggOptions = ggOptions);


# EXEMPLO 3: Histograma com normal passando junto
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo3.pdf";
ggOptions$height = 7;
ggOptions$width  = 8;
numMedias = 10000;
ggOptions$titleSize = 16;
ggOptions$title     = paste0("Distribuição de médias de ", numMedias, " amostras de X ~ U(0,1)");
ggOptions$xTitle = "X";
ggOptions$yTitle    = "Frequência";
ggOptions$histogram = 1;
ggOptions$histogramAddNormal = 1;
set.seed(12345);
medias = numeric(numMedias);
for (i in 1 : numMedias) {
    medias[i] = mean(runif(1000));
}
plotGraph(medias, ggOptions = ggOptions);


# EXEMPLO 4: CDF discreta
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo4.pdf";
ggOptions$height = 7;
ggOptions$width  = 8;
ggOptions$title     = "CDF de uma distribuição discreta";
ggOptions$yTitle    = "CDF";
ggOptions$removeXAxisSpace  = 1;
ggOptions$removeAxisSpace = 1;
ggOptions$xTitle = "Distribuição discreta da PETR4";
ggOptions$lineChart = 1;
ggOptions$stepFunction = 1;
data          = c(-0.3, -0.1, 0.05, 0.2, 0.4);
probabilities = c(0.05, 0.20, 0.50, 0.20, 0.05);
plotGraph(data, ggOptions = ggOptions, probabilities = probabilities);


# EXEMPLO 5: ACF
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo5.pdf";
ggOptions$acf = 1;
ggOptions$title = "Log-retornos diários";
ggOptions$titleSize = 24;
ggOptions$lineSize = 0.6;
ggOptions$width = 10;
ggOptions$height = 7.8;
ggOptions$axisTitleSize = 22;
ggOptions$axisLabelSize = 20;
ggOptions$xTitle = "Deslocamento";
ggOptions$yTitle = "FAC";
returns = rnorm(1000, mean = 0.001, sd = 0.02);
plotGraph(returns, ggOptions = ggOptions);


# EXEMPLO 6: QQPlot
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo6.pdf";
ggOptions$qqplot = 1;
ggOptions$removeXAxisSpace = 0;
ggOptions$removeYAxisSpace = 0;
ggOptions$xTitle = "Quantis da distribuição normal";
ggOptions$title = "Gráfico Q-Q normal";
ggOptions$yTitle = "Quantis dos log-retornos diários";
returns = rnorm(1000, mean = 0.001, sd = 0.02);
plotGraph(returns, ggOptions = ggOptions);

# EXEMPLO 7: Fronteira eficiente, 
# Este exemplo adiciona texto na imagem com addText
# Scatterplot com um path adicional
# O campo categories é usado para escolher a cor de grupos de pontos
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo7.pdf";
ggOptions$height = 8;
ggOptions$width = 8;
ggOptions$titleSize = 20;
ggOptions$axisTitleSize = 17;
ggOptions$axisLabelSize = 15;
ggOptions$barFill = "blue";
ggOptions$xTitle    = "Desvio padrão";
ggOptions$yTitle    = "Retorno esperado";
ggOptions$title     = "Fronteira de portfolios";
ggOptions$removeXAxisSpace  = 0;
ggOptions$removeYAxisSpace  = 0;
ggOptions$addHorizontalLine = 0;
mu.A   = 0.175;
sig.A  = 0.258;
sig2.A = sig.A^2;
mu.B   = 0.055;
sig.B  = 0.115;
sig2.B = sig.B^2;
rho.AB = -0.164;
sig.AB = rho.AB * sig.A * sig.B;
w.A = seq(from=-0.4, to=1.4, by=0.1)
w.B = 1 - w.A
mu.p = w.A*mu.A + w.B*mu.B
sig2.p = w.A^2 * sig2.A + w.B^2 * sig2.B + 2*w.A*w.B*sig.AB
sig.p = sqrt(sig2.p)
ggOptions$xAxisLimits = c(0, max(sig.p));
ggOptions$yAxisLimits = c(0, max(mu.p ));
minIndex = -1;
minValue = 100000;
for (i in 1 : length(sig.p)) {
    if (minValue > sig.p[i]) {
        minValue = sig.p[i];
        minIndex = i;
    }
}
ggOptions$colours  = 3;
ggOptions$addText  = 1;
ggOptions$textsX   = c(sig.A + 0.03, sig.B + 0.03, sig.p[minIndex] - 0.05);
ggOptions$textsY   = c(mu.A        , mu.B        , mu.p [minIndex]       );
ggOptions$texts    = c("Ativo A", "Ativo B", "Mínimo global");
ggOptions$pointSize = 5;
ggOptions$textSize = c(6, 6, 6);
ggOptions$scatterplot = 1;
ggOptions$lineSize    = 0.6;
ggOptions$addPath     = 1;
ggOptions$lineBelowPoints       = 1;
ggOptions$singlePath            = 1;
ggOptions$pathInheritAesthetics = 0;
categories = c(rep("G", 6), rep("R", 13));
plotGraph(mu.p, xValues = sig.p, categories = categories, ggOptions = ggOptions);


# EXEMPLO 8: Assimetria 
# Usa legenda no gráfico
# Neste exemplo passo um data frame pra função e não passo xValues.
# Assim a primeira coluna do data frame é o valor de X.
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo8.pdf";
ggOptions$width = 12;
ggOptions$addLegend = TRUE;
ggOptions$lineChart = 1;
ggOptions$xTitle    = "X";
ggOptions$yTitle    = "PDF";
ggOptions$legendSize = 12;
ggOptions$lineSize = 1;
ggOptions$legendPosition = c(0.5, 0.9);
ggOptions$legend = c("Assimetria negativa", "Assimetria positiva");
loadPackage("fGarch");
x1 = seq(-6, 6, by=0.001)
A = dsnorm (x = x1, mean =  3, sd = 1, xi = 0.63);
B = dsnorm (x = x1, mean = -3, sd = 1, xi = 1.6);
df = data.frame(x1=x1, A=A, B=B);
plotGraph(df, ggOptions = ggOptions);


# EXEMPLO 9: gráfico com:
# - Pontos de cores distintas
# - Linha verticale extra
# - Linha horizontal extra
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo9.pdf";
ggOptions$height = 6;
ggOptions$width = 10;
ggOptions$titleSize = 17;
ggOptions$axisTitleSize = 16;
ggOptions$axisLabelSize = 14;
ggOptions$xTitle = "X";
ggOptions$yTitle = "Y";
ggOptions$title  = "";
ggOptions$addLegend = 0;
ggOptions$removeXAxisSpace = 0;
ggOptions$scatterplot = 1;
ggOptions$customColours = c('#FF0000', '#00CC00', '#0000FF', '#000000');
ggOptions$useShapes  = 1;
ggOptions$customShapes  = c(15, 16, 17, 18);
ggOptions$addHorizontalLine = 1;
ggOptions$addVerticalLine = 1;
num = 100;
X = rnorm(num, mean = 0, sd = 1);
Y = X + rnorm(num, 0, 1);
df = data.frame("X" = X, "Y" = Y);
meanX = mean(df$X);
meanY = mean(df$Y);
ggOptions$horizontalLines = c(meanY);
ggOptions$verticalLines = c(meanX);
categories = character(0);
for (i in 1 : nrow(df)) {
    if (df$X[i] - meanX < 0 && df$Y[i] - meanY < 0) {
        categories = c(categories, "V3");
    } else if (df$X[i] - meanX >= 0 && df$Y[i] - meanY >= 0) {
        categories = c(categories, "V2");
    } else if (df$X[i] - meanX < 0 && df$Y[i] - meanY >= 0) {
        categories = c(categories, "V4");
    } else {
        categories = c(categories, "V1");
    }
}
plotGraph(df, ggOptions = ggOptions, categories = categories);


# EXEMPLO 10 - Figura com diversos segmentos de reta adicionais
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo10.pdf";
ggOptions$height = 6;
ggOptions$width = 12;
ggOptions$titleSize = 17;
ggOptions$axisTitleSize = 16;
ggOptions$axisLabelSize = 14;
ggOptions$xTitle = "Tempo";
ggOptions$yTitle = "r(t)";
ggOptions$removeXAxisSpace = 0;
ggOptions$addHorizontalLine = 1;
ggOptions$horizontalLines   = c(0, 0.05, -0.05);
ggOptions$horizontalSizes   = c(0.4, 0.6, 0.6);
ggOptions$horizontalColours = c("black", "red", "red");
ggOptions$horizontalTypes   = c("solid", "dashed", "dashed");
ggOptions$addSegments = 1;
ggOptions$segXBegin = numeric();
ggOptions$segXEnd   = numeric();
ggOptions$segYBegin = numeric();
ggOptions$segYEnd   = numeric();
ggOptions$segColour = character();
set.seed(123);
num = 60;
y = rnorm(num, mean=0.01, sd=0.05)
for (i in 1: length(y)) {
    ggOptions$segXBegin = c(ggOptions$segXBegin, i   );
    ggOptions$segXEnd   = c(ggOptions$segXEnd  , i   );
    ggOptions$segYBegin = c(ggOptions$segYBegin, 0   );
    ggOptions$segYEnd   = c(ggOptions$segYEnd  , y[i]);
    ggOptions$segColour = c(ggOptions$segColour, "blue");
}
ggOptions$customColours = c("black");
ggOptions$scatterplot = 1;
df = data.frame(x = seq(1, num), y = y);
plotGraph(df, ggOptions = ggOptions);



# EXEMPLO 11 - Figura com AB lone - uma reta com inclinação e não necessariamente
# horizontal ou vertical
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo11.pdf";
ggOptions$addSegments = 0;
ggOptions$addABLine = 1;
ggOptions$addHorizontalLine = 0;
ggOptions$abSlope     = c(0.1);
ggOptions$abIntercept = c(0);
ggOptions$title = "Tendência determinística + ruído";
ggOptions$xTitle = "Tempo";
ggOptions$yTitle = "y(t)";
ggOptions$removeXAxisSpace = 1;
ggOptions$removeYAxisSpace = 1;
ggOptions$lineChart   = 1;
ggOptions$scatterplot = 0;
set.seed(123)
e = rnorm(250)
y.dt = 0.1*seq(1,250) + e;
plotGraph(y.dt, ggOptions = ggOptions);







# EXEMPLO 12 - Duas séries sem data frame
# Line chart mas com pontos adicionais (extraPoints)
# Interpolacao e regressao juntas, funcao lagrange auxiliar
google = c(1435.87, 1442.31, 1439.25, 1440.02, 1448.04, 1452.08);
apple  = c(321.85, 323.34, 325.12, 331.5, 333.46, 343.99)
n = length(google);
g2     = google
google = google[order(g2)];
apple  = apple [order(g2)];

ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo12.pdf";
ggOptions$title = "Google x Apple";
ggOptions$xTitle = "Preços Google (US$)";
ggOptions$yTitle = "Preços Apple (US$)";
ggOptions$axisTitleSize = 16;
ggOptions$axisLabelSize = 16;
ggOptions$axisTitleBold = 0;
ggOptions$removeXAxisSpace   = 1;
ggOptions$removeYAxisSpace   = 1;
ggOptions$yAxisLimits = c(0, 450);
ggOptions$xAxisLimits = c(1433.70, 1455);
ggOptions$customColours = c("blue", "red");
ggOptions$height = 6;
ggOptions$width = 8;
ggOptions$lineChart = 1;

lagrange <- function(x, y, ponto) {
    fx = 0;
    for (i in 1 : length(x)) {
        num = y[i];
        for (j in 1 : length(x)) {
            if (i != j) {
                num = num * (ponto - x[j])/(x[i] - x[j]);
            }
        }
        fx = fx + num;
    }
    return(fx);
}

x = seq(1434.50, 1453.90, by = 0.1);
y1 = numeric(length(x));
for (i in 1 : length(x)) {
    y1[i] = lagrange(google, apple, x[i]);
}
reg = lm(apple ~ google);
y2 = reg$coefficients[1] + x*reg$coefficients[2];
newX = 1453.90;

ggOptions$addExtraPoints = 1;
ggOptions$extraPointsX = c(google, newX, newX);
ggOptions$extraPointsY = c(apple, lagrange(google, apple, newX), reg$coefficients[1] + newX*reg$coefficients[2]);
ggOptions$extraPointsColours = "black";
ggOptions$extraPointsFills   = "black";
ggOptions$addVerticalLine = 1;
ggOptions$verticalLines   = newX;
ggOptions$verticalTypes   = "dashed";
ggOptions$verticalSizes   = 0.5;
plotGraph(y1, y2, xValues = x, ggOptions = ggOptions);





# EXEMPLO 13
# Usa um esquema em R chamado expression que pelo menos da pra colocar
# texto superscrito e outras coisas
# O expression dá uns warnings mas funciona
ano = c(1940, 1950, 1960, 1970, 1980, 1991, 2000, 2010);
pop = c(12.88, 18.78, 31.30, 52.08, 80.44, 110.99, 137.95, 160.93);
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo13.pdf";
ggOptions$lineChart = 1;
ggOptions$title = "Censo demográfico do Brasil";
ggOptions$xTitle = "Ano";
ggOptions$yTitle = "População urbana (em milhões)";
ggOptions$axisTitleSize = 16;
ggOptions$axisLabelSize = 16;
ggOptions$axisTitleBold = 0;
ggOptions$removeXAxisSpace   = 1;
ggOptions$removeYAxisSpace   = 1;
ggOptions$yAxisLimits = c(-12, 180);
ggOptions$xAxisLimits = c(1935, 2015);
ggOptions$height = 6;
ggOptions$width = 8;
ggOptions$xAxisBreaks = ano;
ggOptions$yAxisBreaks = seq(10, 170, by = 20);
ggOptions$addExtraPoints = 1;
ggOptions$extraPointsX = ano;
ggOptions$extraPointsY = pop;
ggOptions$extraPointsColours = "black";
ggOptions$extraPointsFills   = "black";
ggOptions$customColours = c("blue", "red");
ggOptions$addText    = 1;
ggOptions$textsX     = c(1950.6, 1954.9);
ggOptions$textsY     = c(164, 154);
ggOptions$textSize   = c(6, 6, 6);
ggOptions$textColour = c("blue", "red", "red");

year = ano - 1900;
year2 = year^2;
x = seq(37, 113, by = 1);
r1 = lm(pop ~ year);
y1 = r1$coefficients[1] + x*r1$coefficients[2];
r2 = lm(pop ~ year + year2);
y2 = r2$coefficients[1] + x*r2$coefficients[2] + (x^2)*r2$coefficients[3];
ggOptions$texts      = sprintf("M1: $u = %.2f + %.2f x$", r1$coefficients[1], r1$coefficients[2]);
ggOptions$texts      =  c(ggOptions$texts, sprintf("M2: $u = %.2f + %.2f x + %.2f x^2$", r2$coefficients[1], r1$coefficients[2], r2$coefficients[3]));
plotGraph(y1, y2, xValues = x+1900, ggOptions = ggOptions);




# EXEMPLO 14 e 15
# Exemplos de pesquisa operacional, mostra area viavel usando polygon
ggOptions = getGGOptions();
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo14.pdf";
ggOptions$height    = 6;
ggOptions$width     = 7;
ggOptions$axisTitleSize = 16;
ggOptions$axisLabelSize = 14;
ggOptions$xTitle = "$x_1$";
ggOptions$yTitle = "$x_2$";
ggOptions$title  = "";
ggOptions$removeXAxisSpace  = 1;
ggOptions$removeYAxisSpace  = 1;
ggOptions$xAxisLimits       = c(-0.1, 6);
ggOptions$yAxisLimits       = c(  -2, 7);
ggOptions$addVerticalLine = 1;
ggOptions$addHorizontalLine = 1;
ggOptions$addSegments = 1;
ggOptions$lineSize    = 0.5;
ggOptions$segColour   = c("blue",  "red", "purple");
ggOptions$segLineType = c("solid",  "solid", "solid");
ggOptions$segXBegin   = c(0,    0,  9/10);
ggOptions$segYBegin   = c(4, -3/2,     7);
ggOptions$segXEnd     = c(6, 17/3, 27/10);
ggOptions$segYEnd     = c(4,    7,    -2);
ggOptions$addText = 1;
ggOptions$texts  = c("$x_2 = 4$", "$3x_1 - 2x_2 = 3$", "$10x_1 + 2x_2 = 23$");
ggOptions$textsX = c(4.5, 3.6,  3.4);
ggOptions$textsY = c(4.3, 2.6, -1.3);
ggOptions$textSize = c(6,   6,    6);
ggOptions$textColour = c("blue", "red", "purple");
# Extreme vertices of feasible region
x1 = c(0, 1,   2, 3/2, 0);
x2 = c(0, 0, 3/2,   4, 4);
ggOptions$addExtraPoints = 1;
ggOptions$extraPointsX = c(0, 0, 0, 0, 0, 1, 1, 1, 1, 1);
ggOptions$extraPointsY = c(0, 1, 2, 3, 4, 0, 1, 2, 3, 4);
ggOptions$extraPointsColours = rep("red", 10);
ggOptions$extraPointsFills   = rep("red", 10);
ggOptions$scatterplot  = 0;
ggOptions$polygon      = 1;
ggOptions$polygonAlpha = 0.5;

plotGraph(x2, xValues = x1, ggOptions = ggOptions);

ggOptions$imageName = "Exemplo15.pdf";
ggOptions$segColour   = c(ggOptions$segColour, "#00CC00", "#00CC00");
ggOptions$segLineType = c(ggOptions$segLineType, "dashed", "dashed");
ggOptions$segXBegin   = c(ggOptions$segXBegin, 13/12, 1/2);
ggOptions$segYBegin   = c(ggOptions$segYBegin,     7,   7);
ggOptions$segXEnd     = c(ggOptions$segXEnd,   27/12, 5/3);
ggOptions$segYEnd     = c(ggOptions$segYEnd,       0,   0);
ggOptions$texts              = c(ggOptions$texts, "$(2, \\frac{3}{2})$", "$(1, 4)$");
ggOptions$textsX             = c(ggOptions$textsX, 2.5,  0.7);
ggOptions$textsY             = c(ggOptions$textsY, 1.45, 3.7);
ggOptions$textSize           = c(ggOptions$textSize, 6, 6);
ggOptions$textColour         = c(ggOptions$textColour, "black", "black");
ggOptions$extraPointsX       = c(ggOptions$extraPointsX, 2);
ggOptions$extraPointsY       = c(ggOptions$extraPointsY, 3/2);
ggOptions$extraPointsColours = c(ggOptions$extraPointsColours, "#00CC00");
ggOptions$extraPointsFills   = c(ggOptions$extraPointsFills,   "#00CC00");
plotGraph(x2, xValues = x1, ggOptions = ggOptions);




# EXEMPLO 16
# Multiple shaded areas
# Latex in title, xTitle and yTitle
f <- function(x) { -2*x^2 + (4)*x + 6 }

reta <- function(x, x1, y1, x2, y2) {
    m = (y2 - y1)/(x2 - x1);
    a = y1 - m*x1;
    a + m*x;
}

a = 0.5;
b = 2.5;
x = seq(0, 3, by=0.001);
y = f(x);
y2 = reta(x, a, f(a), b, f(b));

ggOptions = getGGOptions();
ggOptions$lineChart = 1;
ggOptions$yTitle = "$f(x)$";
ggOptions$xTitle = "$x$";
ggOptions$axisTitleSize = 16;
ggOptions$axisLabelSize = 16;
ggOptions$axisTitleBold = 0;
ggOptions$removeXAxisSpace   = 1;
ggOptions$removeYAxisSpace   = 1;
ggOptions$yAxisLimits = c(0, 10);
ggOptions$xAxisBreaks = seq(0, 3, by = 0.5);
ggOptions$addLegend = 0;
ggOptions$addSegments = 1;
ggOptions$segXBegin   = c(   a,    b);
ggOptions$segXEnd     = c(   a,    b);
ggOptions$segYBegin   = c(   0,    0);
ggOptions$segYEnd     = c(f(a), f(b));
ggOptions$segLineType = c("dashed", "dashed");
ggOptions$segLineSize = c( 0.2,  0.2);
ggOptions$saveGraphics = saveAllGraphics;
ggOptions$imageName = "Exemplo16.pdf";
ggOptions$height = 6;
ggOptions$width = 8;

a2 = (b - a)/2 * (-1/sqrt(3)) + (a + b)/2;
b2 = (b - a)/2 * ( 1/sqrt(3)) + (a + b)/2;
y2 = reta(x, a2, f(a2), b2, f(b2));

ya = reta(a , a2, f(a2), b2, f(b2));
yb = reta(b , a2, f(a2), b2, f(b2));
ya2 = reta(a2, a2, f(a2), b2, f(b2));
yb2 = reta(b2, a2, f(a2), b2, f(b2));

ggOptions$segXBegin   = c(  a,   b);
ggOptions$segXEnd     = c(  a,   b);
ggOptions$segYBegin   = c(  0,   0);
ggOptions$segYEnd     = c( ya,  yb);
ggOptions$segLineType = c("dashed", "dashed");
ggOptions$segLineSize = c( 0.2,  0.2);
ggOptions$howManyShadedAreas = 4;
ggOptions$shadedAreaPoints = list(
            data.frame(x = c(a,   seq(a, a2, by=0.1) ,   a2,    seq(b2, b, by=0.1) , b, b), 
                       y = c(0, f(seq(a, a2, by=0.1)), f(a2), f(seq(b2, b, by=0.1)), f(b), 0)
                      ),
            data.frame(x = c(   a2,    b2, seq(b2, a2, by = -0.1)    ), 
                       y = c(f(a2), f(b2), f(seq(b2, a2, by = -0.1)))
                      ),
            data.frame(x = c(  a,   seq(a2, a, by=-0.01) ,    a),
                       y = c( ya, f(seq(a2, a, by=-0.01)), f(a))
                      ),
            data.frame(x = c(   b2,  b,   seq(b, b2, by=-0.01) ,   b2),
                       y = c(f(b2), yb, f(seq(b, b2, by=-0.01)), f(b2))
                      )
                     );
ggOptions$shadedAreaColour  = c("gray", "blue", "green", "green");
ggOptions$shadedAreaOpacity = c(0.4, 0.3, 0.3, 0.3);
ggOptions$title = "Aproximação de $\\int_{\\frac{1}{2}}^{\\frac{5}{2}} (-2x^2 + 4x + 1) dx$ por Gauss-Legendre";
plotGraph(y, y2, xValues = x, ggOptions = ggOptions);





###################################################################
# EXEMPLO 17: Gráfico de profit and loss para um portfolio de exemplo, 
# Vários retângulos para o PnL diário
portfolio = c(100000.0, 100132.2, 100637.3, 100539.7, 101185.2, 101239.6, 100579.8, 101418.1, 101647.7, 102662.2, 
              102767.5, 103023.6, 103814.4, 101780.3, 102165.1, 103039.5, 102788.1, 102218.4, 102913.7, 102559.9, 
              102525.6, 101579.1);
xValues   = c(20190401, 20190402, 20190403, 20190404, 20190405, 20190408, 20190409, 20190410, 20190411, 20190412, 
              20190415, 20190416, 20190417, 20190418, 20190422, 20190423, 20190424, 20190425, 20190426, 20190429, 
              20190430, 20190501);

portfolio = portfolio - portfolio[1];
pnl = c(0, diff(portfolio));
upFactor  = 1.005;
lowFactor = 0.995;
ymin = min(min(pnl), min(portfolio));
ymin = ymin * ifelse(ymin < 0, upFactor, lowFactor);
ymax = max(max(pnl), max(portfolio));
ymax = ymax * ifelse(ymax < 0, lowFactor, upFactor);

ggOptions = getGGOptions();
ggOptions$saveGraphics      = saveAllGraphics;
ggOptions$imageName         = "Exemplo17.pdf";
ggOptions$height            = 6;
ggOptions$width             = 9;
ggOptions$title             = "Daily Profit & Loss";
ggOptions$xTitle            = "Date";
ggOptions$yTitle            = "Value";

ggOptions$lineChart         = 1;
ggOptions$removeXAxisSpace  = 1;
ggOptions$formatXAxisAsDate = 1;
ggOptions$yAxisLimits       = c(ymin, ymax);

# Add line in portfolio = initialValue
ggOptions$addHorizontalLine = 1;
ggOptions$horizontalLines   = portfolio[1];

# Funcao auxiliar para subtrair datas em formato numérico YYYYMMDD
subtractDate <- function(date, numDays) {
    year = floor(date / 10000);
    month = floor((date - (year*10000)) / 100);
    day = date - year*10000 - month*100;
    ## do for non leap years every 400 years
    if (numDays < 0) numDays = -numDays;
    for (i in 1 : numDays) {
        day = day - 1;
        if (day == 0) {
            month = month - 1;
        }
        if (month == 0) {
            year = year - 1;
            month = 12;
        }
        if (day == 0) {
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                day = 31;
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                day = 30;
            } else {
                if (year %% 4 == 0) {
                    day = 29;
                } else {
                    day = 28;
                }
            }
        }
    }
    date2 = year * 10000 + month * 100 + day;
    return(date2);
}
# Add rectangle bars 
if (length(pnl) > 0) {
    x1     = numeric  (0);
    x2     = numeric  (0);
    y1     = numeric  (0);
    y2     = numeric  (0);
    fill   = character(0);
    size   = numeric(0);
    colour = character(0);
    for (i in 2 : length(pnl)) {
        if (pnl[i] != 0) {
            x1  = c(x1, subtractDate(xValues[i], 1));
            x2  = c(x2, xValues[i]);
            y1  = c(y1, 0);
            y2  = c(y2, pnl[i]);
            fill = c(fill, ifelse(pnl[i] < 0, "red", "green"));
            size   = c(size, 1);
            colour = c(colour, "white"); 
            
        }
        #t = length(x1);
        #printf("Point %d: %4.1f, %4.1f, %8.2f, %8.2f, %s\n", t, x1[t], x2[t], y1[t], y2[t], fill[t]);
        #if (t > 0) break;
    }
    if (length(x1) > 0) {
        ggOptions$addRectangles        = 1;
        ggOptions$rectanglesX1         = x1;
        ggOptions$rectanglesY1         = y1;
        ggOptions$rectanglesX2         = x2;
        ggOptions$rectanglesY2         = y2;
        ggOptions$rectanglesFillColour = fill;
        ggOptions$rectanglesLineColour = colour;
        ggOptions$rectanglesFillColour = fill;
    }
}

plotGraph(portfolio, xValues = xValues, ggOptions = ggOptions);
###################################################################













# EXEMPLO 18: Uma figura única com 6 plots
# Para plotar múltiplos plots em uma figura, é preciso setar 
#   returnPlot = 1
#  na função plotGraph (abaixo)

set.seed(123);
n = 100;
X = rnorm(n, mean = 0.005, sd = 0.07);
Y = X + rnorm(n, mean = 0, sd = 0.02) - 0.002;
W = rnorm(n, mean = 0.006, sd = 0.10);
Z = rnorm(n, mean = -0.002, sd = 0.03);

ggOptions = getGGOptionsStandard();
ggOptions$saveGraphics = save;
ggOptions$scatterplot = 1;
plotScatterplot <- function(ggOptions, x, y, tx, ty) {
    ggOptions$xTitle = tx;
    ggOptions$yTitle = ty;
    ggOptions$pointSize = 1;
    ggOptions$axisLabelSize = 8;
    ggOptions$imageName = paste0("scatterplot", tx, ty, ".png");
    return (plotGraph(y, xValues = x, ggOptions = ggOptions, returnPlot = 1));
}


p1 = plotScatterplot(ggOptions, X, Y, "X", "Y");
p2 = plotScatterplot(ggOptions, X, W, "X", "W");
p3 = plotScatterplot(ggOptions, X, Z, "X", "Z");
p4 = plotScatterplot(ggOptions, Y, W, "Y", "W");
p5 = plotScatterplot(ggOptions, Y, Z, "Y", "Z");
p6 = plotScatterplot(ggOptions, W, Z, "W", "Z");


layout = matrix(seq(1, 6), ncol = 3, byrow = TRUE);
# Other layout matrices:
# https://cran.r-project.org/web/packages/gridExtra/vignettes/arrangeGrob.html
plotMultipleGraphs(p1, p2, p3, p4, p5, p6, imageName = "Exemplo18.pdf", save = saveAllGraphics, layout = layout, width = 9, height = 6);



printf("Os warnings são causados pelo uso de latex em R, que são convertidos em um tal formato expression.\nNão sei tira-los, mas podem ser ignorados.\n");


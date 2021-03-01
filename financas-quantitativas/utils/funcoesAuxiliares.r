
printf <- function(...) invisible(cat(sprintf(...)))

# Funcao para parar o codigo em caso de erro
stop0 <- function(...) stop(..., call.=FALSE);

# Funcao para carregar um pacote em R. Esta função já verifica
# se o pacote está instalado e instala se não tiver.
loadPackage <- function(package) {
    if (!package %in% rownames(installed.packages())) {
        install.packages(package);
    }
    suppressMessages(library(package, character.only = TRUE));
}

stats.mean <- function(x) {
    n = length(x);
    sum(x)/n;
}

stats.variance <- function(x, sample = 0) {
    n = length(x);
    if (sample) {
        sum((x - mean(x))^2)/(n-1);  
    } else {
        sum((x - mean(x))^2)/n;  
    }
}

stats.sd <- function(x, sample = 0) {
    sqrt(stats.variance(x, sample));
}

stats.skewness <- function(x) {
    n = length(x);
    (sum((x - mean(x))^3)/n)/(sum((x - mean(x))^2)/n)^(3/2);
}

stats.kurtosis <- function(x) {
    n = length(x);
    sum((x - mean(x))^4)/n * 1/((sum((x - mean(x))^2)/n)^2);
}


stats.cov <- function(x, y, sample = 0) {
    if (length(x) != length(y)) stop0("Error: x and y must have the same length.");
    n = length(x);
    if (sample) n = n -1;
    xy = (x - mean(x))*(y - mean(y));
    1/n * sum(xy);
}

stats.cor <- function(x, y) {
    stats.cov(x, y) / (stats.sd(x) * stats.sd(y));
}

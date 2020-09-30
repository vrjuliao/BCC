# Biblioteca Digital de Arendelle
[Documentação](doc.pdf)
### Descrição
------
- Implementação de variantes do algorítmo quicksort.

### Como executar
------
1. No diretório raiz do programa (o mesmo que possui este arquivo) execute o comando ```make``` para compilar.
2. O arquivo binário chamado ```executavel``` será gerado após o item acima.
3. Caso seja necessário recompilar o programa, execute ```make clean``` antes de retornar ao passo 1.
4. o programa possui uma lista de parâmetros que podem ser recebidos em sua execução da seguinte mane
ira:
```console
foo@bar:~<mydir>/tp2$ executavel <algoritmo> <disposição do vetor> <quantidade de elementos> <-p>
```
Se nenhum parâmetro for recebido na execução do programa, este será executado para todos os tipos de algorítmos implementados, para todos os tipos de ordenação inicial do vetor. Sendo que cada variação algorítmica e ordenação do vetor é executada para 50000 elementos, aumentando-se de 50000 em 50000 ,  até atingir 500000 elementos .

| algoritmo  |   |
|------------|---|
| QC |Quicksort recursivo, selciona o pivô usando o elemento central do subvetor |
| QNR |Quicksort não recursivo, selciona o pivô usando o elemento central do subvetor |
| QPE |Quicksort recursivo, selciona o pivô usando o primeiro elemento do subvetor |
| QM3 | Quicksort recursivo, selciona o pivô usando o elemento que é a mediana entre os elementos da borda e o elemento central do subvetor |
| QI1 | Quicksort recursivo, selciona o pivô da mesma maneira que `QM3`. Quando o subvetor possuir 1% do total de elmentos dados no vetor inicial, este subvetor será ordenado via *insertion sort* |
| QI5 | Quicksort recursivo, selciona o pivô da mesma maneira que `QM3`. Quando o subvetor possuir 5% do total de elmentos dados no vetor inicial, este subvetor será ordenado via *insertion sort* |
| QI10 |Quicksort recursivo, selciona o pivô da mesma maneira que `QM3`. Quando o subvetor possuir 1% do total de elmentos dados no vetor inicial, este subvetor será ordenado via *insertion sort* |

| disposição do vetor |   |
|---------------------|---|
|OrdC|Vetor inicial está ordenado de forma crescente|
|OrdD|Vetor inicial está ordenado de forma decrescente|
|Ale|Vetor inicial está embaralhado de forma ordenada|

|Quantidade de elementos|
|---|
| Um número inteiro com a quantidade de elmentos que o vetor inicial possuirá |

|-p|
|---|
| Parâmetro opcional, passado apenas quando se deseja printar os vetores utilizados na ordenação |

- Um exemplo de como executar
```console
foo@bar:~<mydir>/tp2$ executavel QC Ale 12390  -p
```

------
wordkeys: `quicksort` `quicksort non recursive` `quicksort não recursivo`


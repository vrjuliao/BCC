# Writing assignment 4
Vinicius Julião Ramos - 2018054630

## Performance of recommender algorithms on top-N recommendation tasks

O artigo propõe uma comparação entre diferentes classes de recomendadores.
Para tal, a primeira seção apresenta as diferentes categorias de soluções, que agrupam-se em dois grandes grupos: (i) Que utilizam métricas de erro para definir similaridade e (ii) que se baseiam em métodos de acurácia.
Então, as estratégias de recomendação são contrastadas entre si num experimento que consiste em identificar os $N$ melhores itens que podem ser recomendados a para cada usuário. Esse tipo de problema é chamado de **Top-N**.
Entretanto, antes de apresentar os resultados do experimento, os recomendadores e as respectivas classes são detalhados e explicados.
Também são explicadas as justificativas dos possíveis motivos pelos quais os recomendadores baseados em acurácia têm melhor peformance para problemas **Top-N**, o que inclui a solução proposta pelo artigo.

Em linhas gerais, o artigo possui linguagem acessível ao leitor leigo -- com baixa carga de terminologias próprias da área de ciência de dados e com explicações de conceitos básicos, para introduzir os assuntos tratados.
Porém a estrutura poderia ser melhor organizada, como a mudança da segunda seção do artigo para próximo da quarta seção, uma vez que são extremamente similares.
Dessa forma, dado que o título do aritgo e também o resumo (*abstract*) não citam a existência de uma nova técnica de recomendação, a estrutura estaria mais condizente, uma vez que a quarta seção descreve os testes realizados e também os resultados, assim como a quinta seção explora com um pouco mais de profundidade a nova técnica **PureSVD**.
Entretanto, a abordagem da estrutura possui a vantagem de que ao exemplificar a metodologia de testes logo no início do artigo auxiliou a exemplificação e explicação das técnicas apresentadas na seção três.
#!/usr/bin/python3
import numpy as np
import random

N = random.randint(5, 20)

# O número mínimo de arestas possíveis ocorre quando o grafo é
# minimamente conectado, e é `N-1`. O número máximo -- lembrando que o
# grafo é um grafo acíclico dirigido (DAG) -- ocorre quando todo vértice
# possui uma aresta a todos os outros vértices à sua frente na ordenação
# topológica, e é `N * (N - 1) / 2`.
M = random.randint(N - 1, N * (N - 1) / 2)

I = 0 # @TODO: gerar também instruções aleatórias

print(N, M, I)

# `random.sample` retorna uma lista de inteiros _únicos_.
idades = random.sample(range(100), N)
print(" ".join(str(x) for x in idades))

# Todas as arestas possiveis do grafo, respeitando uma ordenação
# topológica arbitrária. No caso, a ordenação topológica é crescente,
# i.e., uma aresta de x para y só pode existir se x < y.
possiveis = np.vstack([
    np.array([(i, j) for j in range(i + 1, N)])
    for i in range(N - 1)
])

# Seleciona M arestas aleatórias, sem repetição. Também garante que as
# selecionadas estejam em uma ordem aleatória.
np.random.shuffle(possiveis)
arestas = possiveis[:M]

# Estamos mapeando os valores dos vértices para uma permutação
# aleatória. Isso torna a ordenação topológica que antes era crescente
# numa ordenação aleatória.
mapeamento = np.random.permutation(N)
arestas = list(map(
    lambda x: (mapeamento[x[0]], mapeamento[x[1]]),
    arestas
))

for a in arestas:
    print(a[0] + 1, a[1] + 1)

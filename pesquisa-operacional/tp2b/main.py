import numpy as np

# Padronizacao da saida
def stringfying_float_value(data):
  epsilon = 1e-10
  return ('%.10f' % round(data + epsilon, 5)).rstrip('0').rstrip('.')

def main():
  #  Ler entrada
  n,m = map(int, input().split())
  c = list(map(int, input().split()))
  matA  = []
  for i in range(n):
    line = list(map(int, input().split()))
    matA.append(line)
  
  matA = np.array(matA)
  x = np.zeros(n)
  y = np.zeros(m)
  
  # nos que ja estao cobertos
  covered = set()
  for i in range(n):
    if i in covered:
      continue

    # obtem todos os conjuntos que elemento `i` esta contido
    in_set = np.where(matA[i,:]==1)[0]

    # pega o menor valor que o `i` pode assumir e qual conjunto este valor
    # minimo de `i` cobre com igualdade
    x[i], min_y = min([(c[j], j) for j in in_set])
    y[min_y] = 1

    # marca todos os elementos do conjunto satisfeito com igualdade como cobertos
    for ii in range(n):
      if matA[ii, min_y] == 1:
        covered.add(ii)

    # atualiza a capacidade suportada por todos os conjuntos que `i` esta contido
    for j in in_set:
      c[j] -= x[i]

  print(" ".join(map(stringfying_float_value, y)))
  print(" ".join(map(stringfying_float_value, x)))

if __name__ == '__main__':
  main()
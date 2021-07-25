import numpy as np

class Tableau:
  self.__n = 0
  self.__m = 0
  self.__c = np.array([])
  self.__A = np.attay([])
  self.__b = np.attay([])
  self.__vero = np.attay([])
  self.__y = np.attay([])

  def __init__(self, n, m, c, A, b):
    self.__n = n
    self.__m = m
    self.__c = np.array(c)
    self.__A = np.array(A)
    self.__b = np.array(b)
    self.__vero = np.eye(N=n)
    self.__y = np.zeros(n)

  def __create_aux_tableau(self):
    tb = np.zeros((self.__n+self.__m+self.__n+1, self.n+1))
    tb[1:,self.__n: self.__m] = self.__A
    
    for i in range(1, self.__n+1):
      if(self.b[i-1] < 0):
        tb[i, :] = -tb[i, :]
    
    tb[1:, -1] = np.abs(self.__b)
    tb[:, :self.__n] = self.__vero
    tb[:, self.__n+self.__m:-1] = np.eye(self.__n)
    tb[0, self.__n+self.__m:-1] = np.ones(self.__n)
    for line in tb[1:,:]:
      tb[0,:] -= line
    
    return tb

  # return -1 if there is no pivot to choose
  def __get_pivot_index(self, vecC):
    for i in range(len(vecC)):
      if round(vecC[i], 5) < 0:
        return i
      return -1

  def __solve_tableau(self, tb):
    # 1 -  pegar o indice da coluna que será pivoteada usando a regra de Bland
    pivot = self.__get_pivot_index(tb[0, self.__n:-1])

    while pivot != -1:
      # 1 - escolher qual a linha ideal para o pivot segundo Bland
      # 2 - escalonar a matriz
      # 3 - pegar o novo pivot
      pass

    return tb

  def solve(self):
    # solve the auxiliar
    table = []
    #create the auxiliar tableau
    tb = self.__create_aux_tableau()
    tb = self.__solve_tableau(tb)
    
    if round(table[0][-1], 5 < 0):
      # inviável - printar o certificado (self.__y)
      return

    # copiar remontar o tableau:
    #   1 - remover a parte auxiliar da matrix A
    #   2 - Colocar o vetor minus_C no cabeçalho
    for i in range(self.__n):
      for j in range(self.__m):
        self.__A[i][j] = auxA[i][j]

    #TODO: resolver o tableau remontado
    # extrair as informações do tableu para as variáveis corretas

      
def main():
  n,m = map(int, input().split())
  c = list(map(int, input().split()))
  matA  = []
  b = []
  for i in range(n):
    line = list(map(int, input().split()))
    matA.append(line[:-1])
    b.append(line[-1])

  tb = Tableau(n,m,c,matA,b)
  tb.solve()


if __name__ == 'main':
  # create function to read the input and start the tableau resolution
  main()
  pass

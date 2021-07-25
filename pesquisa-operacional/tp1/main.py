import numpy as np
from numpy.lib.twodim_base import _min_int

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

  # return -1 if there is no column to choose
  def __get_pivot_column_index(self, vecC):
    for i in range(len(vecC)):
      if round(vecC[i], 5) < 0:
        return i
      return -1

  # return -1 if there is no pivot to choose -> it means unlimited
  def __get_pivot_row_index(self, column, b):
    min_idx = -1
    min_val = -1
    for i in range(self.__m):
      if round(column[i], 5) > 0:
        factor = round(column[i]/b[i], 5)
        if min_idx == -1 or factor < min_val:
          min_idx = i
          min_val = factor
    
    return min_idx

  def __escalonar(self, pcol, prow, tb):
    tb[prow, :] = np.round(tb[prow, :] * (1/tb[prow, pcol]), 5)

    for i in range(self.__m):
      if i == prow:
        continue
      factor = -tb[i, pcol]
      tb[i, :] += (factor*tb[prow,:])

  def __solve_tableau(self, tb):
    # 1 -  pegar o indice da coluna que será pivoteada usando a regra de Bland
    pcol = self.__get_pivot_column_index(tb[0, self.__n:-1])

    while pcol != -1:
      # 1 - escolher qual a linha ideal para o pivot segundo Bland
      pcol += self.__n
      prow = self.__get_pivot_row_index(tb[1:, pcol], tb[1:, -1])
      if(prow == -1):
        #ilimitado
        pass
      prow += 1
      # 2 - escalonar a matriz
      self.__escalonar(pcol, prow, tb)
      
      # 3 - pegar o novo pivot
      pcol = self.__get_pivot_column_index(tb[0, self.__n:-1])

    return tb

  def solve(self):
    #create the auxiliar tableau
    tbAux = self.__create_aux_tableau()
    # solve the auxiliar
    tbAux = self.__solve_tableau(tbAux)
    
    if round(tbAux[0][-1], 5 < 0):
      # inviável - printar o certificado (self.__y)
      return

    # remover a parte auxiliar da matrix A
    tb = np.array((self.__n+1, self.__n+self.__m+1))
    tb[0, :self.__n] = tbAux[0, :self.__n] # y
    tb[1:, :self.__n] = tbAux[1:, :self.__n] # vero
    tb[1:, self.__n:self.__n+self.__m] = tbAux[1:, self.__n:self.__n+self.__m] # A
    tb[1:, -1] = tbAux[1:, -1] # b
    
    # Colocar o vetor minus_C no cabeçalho
    tb[0, self.__n:self.__n+self.__m] = -tbAux[0, self.__n:self.__n+self.__m] # -C

    #resolver o tableau remontado
    tb = self.__solve_tableau(tb)
    # extrair as informações do tableu para as variáveis corretas
    self.__y = tbAux[0, :self.__n]
    self.__vero = tbAux[1:, :self.__n]
    self.__A = tbAux[1:, self.__n:self.__n+self.__m]
    self.__b = tbAux[1:, -1]

      
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

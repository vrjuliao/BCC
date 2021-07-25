import numpy as np
from numpy.lib.twodim_base import _min_int

class Tableau:
  class Result:
    EMPTY = -3
    UNBOUND = -2
    INVIABLE = -1

  __n = 0
  __m = 0
  __c = np.array([])
  __A = np.array([])
  __b = np.array([])
  __vero = np.array([])
  __y = np.array([])
  __last_result = Result.EMPTY

  def __init__(self, n, m, c, A, b):
    self.__n = n
    self.__m = m
    self.__c = np.array(c)
    self.__A = np.array(A)
    self.__b = np.array(b)
    self.__vero = np.eye(N=n)
    self.__y = np.zeros(n)
    self.__last_result = self.Result.EMPTY
    print("self.__A", self.__A)

  def __create_aux_tableau(self):
    tb = np.zeros((self.__n+1, self.__n+self.__m+self.__n+1))
    tb[1:,self.__n: self.__n+self.__m] = self.__A
    
    tb[1:, :self.__n] = self.__vero
    for i in range(1, self.__n+1):
      factor = 1
      if(self.__b[i-1] < 0):
        factor  *= -1
      tb[i, :] = tb[i, :] * factor
    
    tb[1:, -1] = np.abs(self.__b)
    tb[1:, self.__n+self.__m:-1] = np.eye(self.__n)
    tb[0, self.__n+self.__m:-1] = np.ones(self.__n)
    for line in tb[1:,:]:
      tb[0,:] -= line
    
    print(tb)
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
    for i in range(self.__n):
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
        self.__last_result = self.Result.UNBOUND
        self.__problematic_col = pcol-self.__n
        return tb
      prow += 1
      print("pcol", pcol)
      print("prow", prow)
      # 2 - escalonar a matriz
      self.__escalonar(pcol, prow, tb)
      print(tb)
      # 3 - pegar o novo pivot
      pcol = self.__get_pivot_column_index(tb[0, self.__n:-1])

    return tb

  def stringfying_float_value(self, data):
    epsilon = 1e-10
    return ('%.10f' % round(data + epsilon, 5)).rstrip('0').rstrip('.')


  def __get_base_indexes(self):
    bases = dict()
    for col_idx in range(self.__m):
      if(round(self.__c[col_idx], 5) == 0.0):
        col = self.__A[:, col_idx]
        zeros_in_col = np.round(col, 5) == 0.0
        ones_in_col = np.round(col, 5) == 1.0
        if(np.count_nonzero(zeros_in_col) == self.__m-1 # count the quantity of zeros
          and np.count_nonzero(ones_in_col) == 1): # count the quantity of zeros
          line = np.where(ones_in_col)[0][0]
          if line not in bases:
            bases[line] = col_idx
    return list(bases.values())

  def __get_solution(self):
    col_of_basis = self.__get_base_indexes()
    print("b", self.__b)
    print("col_of_basis", col_of_basis)
    result = np.zeros(self.__m)
    for i in range(len(col_of_basis)):
      result[col_of_basis[i]] = self.__b[i]

    return result

  def __print_result(self):
    if self.__last_result == self.Result.UNBOUND:
      print("ilimitada")
      solution = self.__get_solution()
      print(" ".join(map(self.stringfying_float_value, solution)))

      ubd_certif = np.zeros(self.__m)
      ubd_col = self.__A[:, self.__problematic_col]
      ubd_val = 0

      for i in range(self.__n):
        if round(solution[i], 5) != 0.0:
          ubd_certif[i] = -ubd_col[ubd_val]
          ubd_val += 1
      ubd_certif[self.__problematic_col] = 1

      # print unbound result
      print(" ".join(map(self.stringfying_float_value, ubd_certif)))

    elif self.__last_result == self.Result.INVIABLE:
      # print inviable result
      print("inviavel")
      print(" ".join(map(self.stringfying_float_value, self.__y)))
    else:
      print("otima")
      print(self.__optimal)
      solution = self.__get_solution()
      print(" ".join(map(self.stringfying_float_value, solution)))
      print(" ".join(map(self.stringfying_float_value, self.__y)))
      # print success result
      pass

  def solve(self):
    #create the auxiliar tableau
    tb = self.__create_aux_tableau()
    # solve the auxiliar
    tb = self.__solve_tableau(tb)

    if round(tb[0][-1], 5) == 0:
      # viável : continuar a execuçao
      # remover a parte auxiliar da matrix A
      tb = np.delete(tb, np.s_[self.__n+self.__m:-1], axis=1)
      # tb = np.array((self.__n+1, self.__n+self.__m+1))
      # tb[0, :self.__n] = tbAux[0, :self.__n] # y
      # tb[1:, :self.__n] = tbAux[1:, :self.__n] # vero
      # tb[1:, self.__n:self.__n+self.__m] = tbAux[1:, self.__n:self.__n+self.__m] # A
      # tb[1:, -1] = tbAux[1:, -1] # b
      
      # Colocar o vetor minus_C no cabeçalho
      print("solving primal")
      tb[0, self.__n:self.__n+self.__m] = -self.__c # -C
      print(tb)

      #resolver o tableau remontado
      tb = self.__solve_tableau(tb)
      # extrair o vetor `c`
      self.__c =  -tb[0, self.__n:self.__n+self.__m]

      self.__optimal = tb[0, -1]

    else:
      self.__last_result = self.Result.INVIABLE
    
    # extrair as informações do tableu para as variáveis corretas
    self.__y = tb[0, :self.__n]
    self.__vero = tb[1:, :self.__n]
    self.__A = tb[1:, self.__n:self.__n+self.__m]
    self.__b = tb[1:, -1]

    self.__print_result()

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

if __name__ == '__main__':
  # create function to read the input and start the tableau resolution
  main()

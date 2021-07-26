import numpy as np

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
  __status = Result.EMPTY

  def __init__(self, n, m, c, A, b):
    self.__n = n
    self.__m = m
    self.__c = np.array(c)
    self.__A = np.array(A)
    self.__b = np.array(b)
    self.__vero = np.eye(N=n)
    self.__y = np.zeros(n)
    self.__vero_unbound = False
    self.__status = self.Result.EMPTY

  def __create_aux_tableau(self):
    tb = np.zeros((self.__n+1, self.__n+self.__m+self.__n+1))
    tb[1:, :self.__m] = self.__A
    
    tb[1:,self.__m: self.__n+self.__m] = self.__vero
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
        factor = round(b[i]/column[i], 5)
        if min_idx == -1 or factor < min_val:
          min_idx = i
          min_val = factor
    
    return min_idx

  def __escalonar(self, pcol, prow, tb):
    # tb[prow, :] = np.round(tb[prow, :] * (1/tb[prow, pcol]), 5)
    tb[prow, :] = tb[prow, :] * (1/tb[prow, pcol])

    for i in range(self.__n+1):
      if i == prow:
        continue
      factor = -tb[i, pcol]
      tb[i, :] += (factor*tb[prow,:])

  def __solve_tableau(self, tb):
    # pegar o indice da coluna que será pivoteada usando a regra de Bland
    pcol = self.__get_pivot_column_index(tb[0, :-1])
    while pcol != -1:
      # escolher qual a linha ideal para o pivot segundo Bland
      prow = self.__get_pivot_row_index(tb[1:, pcol], tb[1:, -1])
      if(prow == -1):
        self.__status = self.Result.UNBOUND
        self.__problematic_col = pcol
        self.__vero_unbound =  (pcol >= self.__m)
        return tb
      prow += 1
      # escalonar a matriz
      self.__escalonar(pcol, prow, tb)
      # pegar o novo pivot
      pcol = self.__get_pivot_column_index(tb[0, :-1])
    return tb

  def stringfying_float_value(self, data):
    epsilon = 1e-10
    return ('%.10f' % round(data + epsilon, 5)).rstrip('0').rstrip('.')

  # when a column is a piece of an identity matrix,
  # this funcion return the index of the unique 1 inside
  # that column, or return -1 if `column` is not unitary
  def __index_of_unique_one(self, col):
    zeros_in_col = np.round(col, 5) == 0.0
    ones_in_col = np.round(col, 5) == 1.0
    
    if(np.count_nonzero(zeros_in_col) == (self.__n-1) # count the quantity of zeros
      and np.count_nonzero(ones_in_col) == 1): # count the quantity of zeros
      return  np.where(ones_in_col)[0][0]
    return -1

  def __get_base_indexes(self):
    bases = dict()
    for col_idx in range(self.__m):
      if(round(self.__c[col_idx], 5) == 0.0):
        col = self.__A[:, col_idx]
        line = self.__index_of_unique_one(col)
        if line >= 0 and line not in bases:
          bases[line] = col_idx
        
    return list(bases.items())

  def __canonical_form(self, tb):
    matA = tb[1:, :self.__m].T
    vecC = tb[0, :self.__m]
    basis = set()
    for i in range(self.__m):
      one_idx = self.__index_of_unique_one(matA[i])
      if one_idx >= 0 and one_idx not in basis:
        basis.add(one_idx)
        tb[0,:] += ((-vecC[i])*tb[one_idx+1,:])

  def __get_solution(self):
    base = self.__get_base_indexes()

    # print(base)
    result = np.zeros(self.__m)
    for (line, col) in base :
      result[col] = self.__b[line]

    return result, base

  def __print_result(self):
    if self.__status == self.Result.UNBOUND:
      print("ilimitada")
      solution, base = self.__get_solution()
      print(" ".join(map(self.stringfying_float_value, solution)))

      # obtem o certificado de ilimitada
      # toma como base os valores no vetor solucao que sao diferentes de 0
      ubd_certif = np.zeros(self.__m)
      ubd_col = self.__A[:, self.__problematic_col] if not self.__vero_unbound else self.__vero[:, self.__problematic_col - self.__m]

      for (lin, col) in base:
        ubd_certif[col] = -ubd_col[lin]      
      if not self.__vero_unbound: ubd_certif[self.__problematic_col] = 1

      # print unbound result
      print(" ".join(map(self.stringfying_float_value, ubd_certif)))

    elif self.__status == self.Result.INVIABLE:
      # print inviable result
      print("inviavel")
      print(" ".join(map(self.stringfying_float_value, self.__y)))
    else:
      print("otima")
      print(self.stringfying_float_value(self.__optimal))
      solution, _ = self.__get_solution()
      print(" ".join(map(self.stringfying_float_value, solution)))
      print(" ".join(map(self.stringfying_float_value, self.__y)))

  def solve(self):
    tb = self.__create_aux_tableau()
    # solve the auxiliar
    tb = self.__solve_tableau(tb)

    if round(tb[0][-1], 5) == 0:
      # remover a parte auxiliar da matrix A
      tb = np.delete(tb, np.s_[self.__n+self.__m:-1], axis=1)
      
      # Colocar o vetor minus_C no cabeçalho
      tb[0, :self.__m] = -self.__c # -C
      tb[0, self.__m:self.__n+self.__m] = np.zeros(self.__n)
      
      # canoic form
      self.__canonical_form(tb)

      #resolver o tableau remontado
      tb = self.__solve_tableau(tb)

      self.__c =  -tb[0, :self.__m]
      self.__optimal = tb[0, -1]

    else:
      self.__status = self.Result.INVIABLE
    
    # extrair as informações do tableau para as variáveis corretas
    self.__y = tb[0, self.__m:self.__n+self.__m]
    self.__vero = tb[1:, self.__m:self.__n+self.__m]
    self.__A = tb[1:, :self.__m]
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

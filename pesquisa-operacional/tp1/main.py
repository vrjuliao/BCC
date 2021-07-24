class Tableau:
  self.__n = 0
  self.__m = 0
  self.__c = []
  self.__A = []
  self.__b = []
  self.__vero = []
  self.__y = []

  def __init__(self, n, m, c, A, b):
    self.__n = n
    self.__m = m
    self.__c = c
    self.__A = A
    self.__b = b
    self.__vero = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
      self.__vero[i][i] = 1

    self.__y = [0 for _ in range(n)]

  def __create_aux_A(self):
    auxA = [[0 for _ in range(self.__n)] for _ in range(self.__m + self.__n)]
    for i in range(self.__n):
      for j in range(self.__m):
        auxA[i][j] = self.__A[i][j]

    for i in range(self.__n):
      auxA[self.__m + i]  = 1
    
    return auxA

  def __create_aux_C(self):
    auxC = [0 for _ in range(self.__m + self.__n)]
    for i in range(self.__n):
      auxC[i+self.__m] = 1
    
    return auxC


  def solve(self):
    # solve the auxiliar
    table = []
    #create the auxiliar tableau
    auxA = self.__create_aux_A()
    auxC = self.__create_aux_C()
    table = self.__start(True, matA=auxA, vecC=auxC)

    if round(table[0][-1], 5 < 0):
      # inviável - printar o certificado (self.__y)
      return
    
    # sobrescrever self.__A com a respectiva parte
      
    


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



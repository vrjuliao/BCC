from simplex import Tableau
import numpy as np

def main():
  curr_n,m = map(int, input().split())
  n = curr_n+m-2
  b_list = list(map(int, input().split()))
  incidencyMat  = []
  for i in range(curr_n):
    line = list(map(int, input().split()))
    incidencyMat.append(line)

  # mount the matrix A of the tableau
  matA = np.zeros((n,m))
  matA[:m,:] = np.eye(m)
  matA[m:,:] = np.array(incidencyMat[1:-1])

  b = np.zeros(n)
  b[:m] = np.array(b_list)

  c = [1 if x < 0 else 0 for x in incidencyMat[0]]
  
  tb = Tableau(n,m,c,matA.tolist(),b.tolist())
  tb.solve()

  print(tb.stringfying_float_value(tb.get_result()))
  solution, _ = tb.get_solution()
  print(" ".join(map(tb.stringfying_float_value, solution)))
  y = tb.get_certified()
  print(" ".join(map(tb.stringfying_float_value, y[:m])))

if __name__ == '__main__':
  # create function to read the input and start the tableau resolution
  main()
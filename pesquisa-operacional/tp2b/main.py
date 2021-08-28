import numpy as np

def stringfying_float_value(data):
  epsilon = 1e-10
  return ('%.10f' % round(data + epsilon, 5)).rstrip('0').rstrip('.')

def main():
  n,m = map(int, input().split())
  c = list(map(int, input().split()))
  matA  = []
  for i in range(n):
    line = list(map(int, input().split()))
    matA.append(line)
  
  matA = np.array(matA)
  x = np.zeros(n)
  y = np.zeros(m)
  covered = set()
  for i in range(n):
    if i in covered:
      continue
    in_set = np.where(matA[i,:]==1)[0]
    x[i], min_y = min([(c[j], j) for j in in_set])
    y[min_y] = 1
    for ii in range(n):
      if matA[ii, min_y] == 1:
        covered.add(ii)

    for j in in_set:
      c[j] -= x[i]

  print(" ".join(map(stringfying_float_value, y)))
  print(" ".join(map(stringfying_float_value, x)))

if __name__ == '__main__':
  main()

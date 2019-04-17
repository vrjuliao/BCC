import numpy as np

matrix = np.array([
    [0.9, 0.07, 0.02, 0.01],
    [0., 0.93, 0.05, 0.02],
    [0., 0., 0.85, 0.15],
    [0., 0., 0., 1]
])

multiple_matrix = np.array([0.85, 0.1, 0.05, 0.])

for i in range(10):
    multiple_matrix = np.dot(matrix.T, multiple_matrix)
    print(str(multiple_matrix))
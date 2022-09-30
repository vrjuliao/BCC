import sys
import pandas as pd
import numpy as np
from svd1 import svd

# melhor configuracao ate então: 20 epochs, 5 factors, alpha=0.005 e reg=0.1
# depois testar com factors = 6 e reg = 0.2
if __name__ == "__main__":
    ratings_path = sys.argv[1]
    targets_path = sys.argv[2]
    # 2:45 - 1.229
    # svd_ = svd(epochs = 22, lr = 0.0001, n_factors=4, reg=0.1)
    
    # 3:09 - 1.220
    # svd_ = svd(epochs = 25, lr = 0.0001, n_factors=4, reg=0.1)
    
    # 4:07 - 1.217
    # svd_ = svd(epochs = 30, lr = 0.0001, n_factors=4, reg=0.1)
    
    # 4:06 - 1.21571 
    # svd_ = svd(epochs = 33, lr = 0.0001, n_factors=4, reg=0.1)

    # 4:16 - 1.21343
    # svd_ = svd(epochs = 38, lr = 0.0001, n_factors=4, reg=0.1)

    # 4:39 - 1.21260
    # svd_ = svd(epochs = 40, lr = 0.0001, n_factors=4, reg=0.1)
    
    # 4:43 - 1.19421
    # svd_ = svd(epochs = 39, lr = 0.0005, n_factors=4, reg=0.08)
    
    # 3:42 - 1.19414
    svd_ = svd(epochs = 39, lr = 0.0005, n_factors=4, reg=0.09)
    svd_.read_ratings(ratings_path)
    svd_.stochastic_gradient()
    svd_.submission(targets_path)
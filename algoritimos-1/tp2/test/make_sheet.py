import numpy as np
import pandas as pd
from scipy import stats
import sys
def main():
    current_list = ['2', '4','8', '12','16', '20']
    print('n', 'mu_greedy', 'sigma_greedy', 'mu_pd', 'sigma_pd')
    for qtt in current_list:
        compute_line_sheet(qtt)

def compute_line_sheet(qtt):
#     print('n', 'm', 'n+m', 'mu', 'sigma')  
    
    data = np.genfromtxt('out/out_'+qtt+'.txt')
    mean1, sigma21 = stats.norm.fit(data[0, :])
    mean2, sigma22 = stats.norm.fit(data[1, :])
    print(qtt, int(round(mean1)), int(round(sigma21**(0.5))), int(round(mean2)), int(round(sigma22**(0.5))))
    
if __name__ == "__main__":
   main()
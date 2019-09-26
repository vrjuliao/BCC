import numpy as np
import pandas as pd
from scipy import stats
import sys
def main(argv):
    command = argv[0]
    swap_list = [(['swap_05_1', 'swap_05_2', 'swap_05_3', 'swap_05_4'], 'swap_05'),
                 (['swap_10_1', 'swap_10_2', 'swap_10_2'],'swap_10'),
                 (['swap_15_2', 'swap_15_2', 'swap_15_1'], 'swap_15'),
                 (['swap_20_1', 'swap_20_1', 'swap_20_1'], 'swap_20'),
                 (['swap_25_1', 'swap_25_2'], 'swap_25'),
                 (['swap_30_1', 'swap_30_1'], 'swap_30'),
                 (['swap_35_1', 'swap_35_1'], 'swap_35'),
                 (['swap_40_1', 'swap_40_2'], 'swap_40'),
                 (['swap_45_1', 'swap_45_1'], 'swap_45'),
                 (['swap_50_1', 'swap_50_2'], 'swap_50'),
                 (['swap_55_1', 'swap_55_2'], 'swap_55')]

    commander_list = [(['commander_05'], 'commander_05'),
                      (['commander_10'], 'commander_10'),
                      (['commander_15'], 'commander_15'),
                      (['commander_20'], 'commander_20'),
                      (['commander_25'], 'commander_25'),
                      (['commander_30'], 'commander_30'),
                      (['commander_35'], 'commander_35'),
                      (['commander_40'], 'commander_40'),
                      (['commander_45'], 'commander_45'),
                      (['commander_50'], 'commander_50'),
                      (['commander_55'], 'commander_55')]

    meeting_list = [(['meeting_05'], 'meeting_05'),
                     (['meeting_10'], 'meeting_10'),
                     (['meeting_15'], 'meeting_15'),
                     (['meeting_20'], 'meeting_20'),
                     (['meeting_25'], 'meeting_25'),
                     (['meeting_30'], 'meeting_30'),
                     (['meeting_35'], 'meeting_35'),
                     (['meeting_40'], 'meeting_40'),
                     (['meeting_45'], 'meeting_45'),
                     (['meeting_50'], 'meeting_50'),
                     (['meeting_55'], 'meeting_55')]
    
    if(command == 'S'): current_list = swap_list
    elif(command == 'C'): current_list = commander_list
    elif(command == 'M'): current_list = meeting_list

    print('n', 'm', 'n+m', 'mu', 'sigma')
    for row in current_list:
        compute_line_sheet(row[0], row[1])

        

def compute_line_sheet(entire_files, out_file):
#     print('n', 'm', 'n+m', 'mu', 'sigma')
    n = 0
    m = 0
    for file in entire_files:
        f = open('in/'+file+'.txt')
        line = f.readline().split(' ')
        n+=int(line[0])
        m+=int(line[1])
        f.close()
        
    n = round(n/len(entire_files))
    m = round(m/len(entire_files))
    
    data = np.genfromtxt('out/'+out_file+'.txt')
    mean, sigma2 = stats.norm.fit(data)
    print(n, m, n+m, int(round(mean)), int(round(sigma2**(0.5))))
    
if __name__ == "__main__":
   main(sys.argv[1:])
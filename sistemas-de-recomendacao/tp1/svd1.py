import numpy as np
import pandas as pd

class svd():

    def __init__(self, epochs = 20, lr = 0.005, n_factors=5, reg=0.1):
        self.epochs = epochs
        self.lr = lr
        self.n_factors = n_factors
        self.reg = reg

    def read_ratings(self, ratings_path):
        # print("read ratings")
        df = pd.read_csv(ratings_path, encoding='latin-1', sep=',|:', engine='python')
        self.user_index = {}
        self.item_index = {}
        self.user_avg = {}
        self.item_avg = {}
        u_ind = 0
        i_ind = 0
        self.ratings = []
        for row in df.itertuples():
            # print(row)
            userid = row.UserId
            itemid = row.ItemId
            if userid not in self.user_index.keys():
                self.user_index[userid] = u_ind
                self.user_avg[userid] = []
                u_ind+=1
            self.user_avg[userid].append(row.Rating)
            if itemid not in self.item_index.keys():
                self.item_index[itemid] = i_ind
                self.item_avg[itemid] = []
                i_ind+=1
            self.item_avg[itemid].append(row.Rating)
            self.ratings.append((self.user_index[userid], self.item_index[itemid], float(row.Rating)))
        self.average_rating = df["Rating"].mean()

    def predict(self, u, i):
        pred = 0.0
        for f in range(self.n_factors):
            pred += self.P[u][f] * self.Q[f][i]
        return pred

    def stochastic_gradient(self):
        # print("stochatiscc gradiant")
        self.P = np.ones((len(self.user_index), self.n_factors))
        self.Q = np.ones((self.n_factors, (len(self.item_index))))
        # print(type(self.P))
        # self.Q = self.Q.T
        # self.lr = 0.01
        sum_ = 0
        for s in range(self.epochs):
            rmse = 0
            for u, i, rui in self.ratings:
                eui = rui -  self.predict(u, i)
                # rmse += eui*eui
                
                for f in range(self.n_factors):
                    #  prestar atenção na multiplicação por 2 abaixo
                    self.P[u][f] = self.P[u][f] + self.lr * (2*eui*self.Q[f][i] - self.reg*self.P[u][f])
                    self.Q[f][i] = self.Q[f][i] + self.lr * (2*eui*self.P[u][f] - self.reg*self.Q[f][i])
                sum_+=1
            # self.lr -= 0.00025
            # rmse/=sum_
            # print("Epoch {}, rmse: {}".format(s, rmse))


    def submission(self, targets_path):
        # print("submission")
        df = pd.read_csv(targets_path)
        print("UserId:ItemId,Rating")
        for row in df.itertuples():
            userid = row[1].split(":")[0]
            itemid = row[1].split(":")[1]
            # usa a média do usuário ou a média do item caso o id do usuário ou o id do item não sejam encontrados
            if userid in self.user_index.keys() and itemid in self.item_index.keys():
                prediction = self.predict(self.user_index[userid], self.item_index[itemid])
                if prediction > 5:
                    prediction = 5
                elif prediction < 0:
                    prediction = 0
            elif userid in self.user_index.keys():
                prediction = np.mean(self.user_avg[userid])
            elif itemid in self.item_index.keys():
                prediction = np.mean(self.item_avg[itemid])
            else:
                prediction = self.average_rating 
            print("{}:{},{}".format(userid, itemid, prediction))
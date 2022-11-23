import pandas as pd

class Rocchio:

    def __init__(self, ratings_df):
        self.__ratings = ratings_df[['UserId', 'ItemId', 'Rating']].copy()
        self.__ratings['Rating'] = self.__ratings['Rating'].apply(lambda x: self.__rescaleRating(x))

    def fit(self, features_df):
        self.__features = self.__ratings.copy()

        # Também pode ser compreendido como a computação da matriz de utilizade dos itens.
        self.__split_features_into_columns(features_df)
        self.__compute_user_utility()

    def predict(self, user_item_df):
        targets = user_item_df[['ItemId', 'UserId']].copy()
        targets = targets.merge(self.__features, on='ItemId', how='outer')
        targets = targets.fillna(0)

        targets = pd.merge(targets, self.__user_utility, on='UserId')

        consine_sim = targets[['UserId', 'ItemId']]
        consine_sim['user_DOT_item'] = 0
        consine_sim['user_distance'] = 0
        consine_sim['item_distance'] = 0

        for feat in self.__features_list:
            consine_sim['user_DOT_item'] += targets['u_' + feat] * targets[feat]
            consine_sim['user_distance'] += targets['u_' + feat] * targets['u_' + feat]
            consine_sim['item_distance'] += targets[feat]        * targets[feat]

        consine_sim['user_distance'] = consine_sim['user_distance'].pow(1./2)
        consine_sim['item_distance'] = consine_sim['item_distance'].pow(1./2)
        consine_sim['Similarity']    = consine_sim['user_DOT_item'] / \
                                            (consine_sim['user_distance'] * consine_sim['item_distance'])

        consine_sim = consine_sim.drop(['user_DOT_item', 'user_distance', 'item_distance'], axis=1)

        return consine_sim

    def __split_features_into_columns(self, features_df):
        self.__features = features_df[['ItemId', 'Features']].copy()
        splitted_features = self.__features['Features'].str.split(' ')
        self.__features_list = list(dict.fromkeys([y for x in splitted_features for y in x]).keys())

        for feat in self.__features_list:
            self.__features[feat] = self.__features['Features'].apply(lambda x : 1 if feat in x else 0)

        self.__features = self.__features.drop(['Features'], axis=1)

    def __rescaleRating(self, old_rating):
        if old_rating == 10:
            return 3
        elif old_rating > 7:
            return 2
        elif old_rating > 5:
            return 1
        return 0

    def __compute_user_utility(self):
        self.__user_utility = self.__ratings.copy()
        self.__user_utility = self.__user_utility.merge(self.__features, on='ItemId')

        self.__user_utility['Frequency'] = self.__user_utility.groupby('UserId')['UserId'].transform('count')

        for feat in self.__features_list:
            self.__user_utility[feat] = self.__user_utility[feat] * self.__user_utility['Rating'] / self.__user_utility['Frequency']

        self.__user_utility = self.__user_utility.drop(['ItemId', 'Frequency', 'Rating'], axis=1)
        self.__user_utility = self.__user_utility.groupby('UserId').sum()

        for feat in self.__features_list:
            self.__user_utility['u_' + feat] = self.__user_utility[feat]
            self.__user_utility = self.__user_utility.drop(feat, axis=1)

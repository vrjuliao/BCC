import json
import numpy as np
import pandas as pd

from surprise import Reader
from surprise import Dataset
from surprise.model_selection import cross_validate
from surprise import NormalPredictor
from surprise import KNNBasic
from surprise import KNNWithMeans
from surprise import KNNWithZScore
from surprise import KNNBaseline
from surprise import SVD
from surprise import BaselineOnly
from surprise import SVDpp
from surprise import NMF
from surprise import SlopeOne
from surprise import CoClustering
from surprise.accuracy import rmse
from surprise import accuracy
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity

# ML Pre processing
from surprise.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

# Hyperparameter tuning
from surprise.model_selection import GridSearchCV

train = pd.read_json('./ratings.jsonl', lines=True)
df_movies = pd.read_json('./content.jsonl', lines=True)

# df_train = train.copy()
# df_merge1 = df_train.merge(df_movies, on='ItemId')
# df_merge1.head()

# df_merge1.rename(columns={'rating_x': 'Rating', 'rating_y': 'numRatings'}, inplace=True)
# num_ratings = pd.DataFrame(df_merge1.groupby('ItemId').count()['Rating']).reset_index()
# df_merge1 = pd.merge(left=df_merge1, right=num_ratings, on='ItemId')
# df_merge1.rename(columns={'rating_x': 'rating', 'rating_y': 'numRatings'}, inplace=True)

df_1 = df_movies[['ItemId', 'Actors', 'Director', 'Genre', 'Title']]
df_1['Actors'] = df_1.Actors.astype(str)
# df_1['plot_keywords'] = df_1.plot_keywords.astype(str) # get keywords from the 'Plot' field
df_1['Genre'] = df_1.Genre.astype(str)
df_1['Director'] = df_1.Director.astype(str)


# Removing spaces between names
df_1['Director'] = df_1['Director'].apply(lambda x: ' '.join(x.replace(' ', '').lower() for x in x.split(', ')))
df_1['Actors'] = df_1['Actors'].apply(lambda x: ' '.join(x.replace(' ', '').lower() for x in x.split(', ')))

# Discarding the pipes between the plot keywords' and getting only the first five words
# df_1['plot_keywords'] = df_1['plot_keywords'].map(lambda x: x.split('|')) # 'Plot' field but only the keywords
# df_1['plot_keywords'] = df_1['plot_keywords'].apply(lambda x: " ".join(x)) #  'Plot' field but only the keywords

# Discarding the pipes between the genres
df_1['Genre'] = df_1['Genre'].apply(lambda x: ' '.join(x.replace(' ', '').lower() for x in x.split(', ')))


df_features = df_1[['Actors', 'Director', 'Genre', 'ItemId']]


indices = {row['ItemId']: index for (index, row) in df_features.iterrows()}


df_features = df_1[['Actors', 'Director', 'Genre', 'ItemId']]
df_1['combined_features'] = df_features['Actors'] +' '+ df_features['Director'] +' '+ df_features['Genre']

cv = CountVectorizer()
# cv_matrix = cv.fit_transform(df_1['combined_features'].sample(frac=.9))
cv_matrix = cv.fit_transform(df_1['combined_features'])
print("================= HERE")

#now we obtain the cosine similarity matrix from the cv matrix
sim_score = cosine_similarity(cv_matrix, cv_matrix)
print("================= HERE2")

# df_1.set_index('ItemId', inplace = True)

# dictionary with ItemId -> Index in the similarity matrix
indices = {row['ItemId']: index for (index, row) in df_features.iterrows()}

# def recommendations(title, n, sim_score=sim_score):
#     recommended_movies = []

#     # gettin the index of the movie that matches the title
#     idx = indices[indices == title].index[0]

#     # creating a Series with the similarity scores in descending order
#     score_series = pd.Series(sim_score[idx]).sort_values(ascending = False)

#     # getting the indexes of the 10 most similar movies
#     top_n_indexes = list(score_series.iloc[1:n+1].index)

#     # populating the list with the titles of the best n matching movies
#     for i in top_n_indexes:
#         recommended_movies.append(list(df_1.index)[i])

#     return recommended_movies
# recommendations('Species', 15, sim_score)

def get_similar_by_items(user_rated_items, target_item):
    sims = []
    for item_id in user_rated_items:
        sims.append(sim_score[indices[item_id]][indices[target_item]])

    return pd.DataFrame({'ItemId': user_rated_items, 'Similarity': sims})


def get_rated_items(user_id):
    rated_items = train[train['UserId'] == user_id][['ItemId', 'Rating']]
    return rated_items


# llist = [
# 'c9f0f895fb',
# 'd3d9446802',
# 'c20ad4d76f',
# '8e296a067a',
# '54229abfcf'
# ]

# df_similarity = get_similar_by_items(llist, '1afa34a7f9')
# rated_items = get_rated_items('a87ff679a2')


# rated_items['ItemId'].tolist()

def predict(user_id, item_id):
    related_items = get_rated_items(user_id)
    similarities = get_similar_by_items(related_items['ItemId'].tolist(), item_id)
    merged_df = related_items.merge(similarities, on='ItemId')
    # print(similarities)
    # print(related_items)

    if(merged_df.shape[0] != 0):
        user_mean = 0.0
        for (_, row) in merged_df.iterrows():
            user_mean += (row['Rating']*row['Similarity'])

        return user_mean/(merged_df.shape[0])
    else:
        return 0.


# predict('0006246bee','01d2404d4c')

df_to_predict = pd.read_csv('targets.csv', encoding='latin-1', sep=',')
user_index = 1
# user_movies = df_to_predict.iloc[user_index*100: (user_index+1)*100]
# print(user_movies.iloc[0]['UserId'])

output_file = open('out.csv','w')
print('UserId,ItemId', file=output_file)
while((user_index*100)+1 < df_to_predict.shape[0]):
    # break
    user_movies = df_to_predict.iloc[(user_index-1)*100: user_index*100]
    user_index += 1
    user_ranking = []
    uid = user_movies.iloc[0]['UserId']

    for row in user_movies.itertuples():
        user_ranking.append((predict(row.UserId, row.ItemId), row.ItemId))

    user_ranking.sort(reverse=True)
    for(rank, item_id) in user_ranking:
        print('{},{}'.format(uid,item_id), file=output_file)
    # break
# user_movies
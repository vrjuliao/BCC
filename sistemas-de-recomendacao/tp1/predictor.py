import numpy as np

class Sgd():

  def __init__(self, epochs=30, learning_ratio=0.001, n_factors=5, regulation=0.1, min_rate=0, max_rate=5):
    self.__epochs = epochs
    self.__learning_ratio = learning_ratio
    self.__n_factors = n_factors
    self.__regulation = regulation
    self.__min_rate = min_rate
    self.__max_rate = max_rate
    self.__global_average = 0.
    self.__user_index = {}
    self.__user_avg = {}
    self.__item_index = {}
    self.__item_avg = {}
    self.__ratings = []

  """
  Armazena nas estruturas internas da classe a nota que
  determinado usuário atribuira ao item.
  """
  def add_rating(self, user_id, item_id, rating):
    if user_id not in self.__user_index:
        self.__user_index[user_id] = len(self.__user_index)
        self.__user_avg[user_id] = []
    self.__user_avg[user_id].append(rating)
    
    if item_id not in self.__item_index:
        self.__item_index[item_id] = len(self.__item_index)
        self.__item_avg[item_id] = []
    self.__item_avg[item_id].append(rating)
    
    self.__ratings.append((self.__user_index[user_id],
                           self.__item_index[item_id],
                           float(rating)))

  def __predict(self, user_id, item_id):
    pred = 0.0
    for factor in range(self.__n_factors):
      pred += self.__P[user_id][factor] * self.__Q[factor][item_id]
    return pred

  """
  Método publico que retornará o resultado da predição.
  Este método, já trata os corner-cases.
  """
  def predict(self, user_id, item_id):
    if user_id in self.__user_index and item_id in self.__item_index:
      # O resultado da predição por gradiente estogástico
      # é utilizado somente quando o usuário e o item requisitados existem.
      prediction = self.__predict(self.__user_index[user_id], self.__item_index[item_id])
      if prediction > self.__max_rate:
        return self.__max_rate
      elif prediction < self.__min_rate:
        return self.__min_rate
      return prediction
    elif user_id in self.__user_index:
      return np.mean(self.__user_avg[user_id])
    elif item_id in self.__item_index:
      return np.mean(self.__item_avg[item_id])
    else:
      return self.__global_average

  """
  Aplica o gradiente estocástico para uma determinada quantidade de
  épocas. 
  """
  def fit(self):
    # A média global será utilizada como resultado da predição,
    # para cobrir corner-cases
    self.__global_average = np.mean([x[2] for x in self.__ratings])

    # Computando o gradiente estocástico
    self.__P = np.ones((len(self.__user_index), self.__n_factors))
    self.__Q = np.ones((self.__n_factors, (len(self.__item_index))))
    for _ in range(self.__epochs):
      for user, item, rating in self.__ratings:
        rating_error = 2*(rating - self.__predict(user, item))
        for factor in range(self.__n_factors):
            self.__P[user][factor] = self.__P[user][factor] + \
                                     self.__learning_ratio * (rating_error*self.__Q[factor][item] - \
                                     self.__regulation*self.__P[user][factor])

            self.__Q[factor][item] = self.__Q[factor][item] + \
                                     self.__learning_ratio * (rating_error*self.__P[user][factor] - \
                                     self.__regulation*self.__Q[factor][item])

import predictor
import sys
import pandas as pd


def read_ratings(ratings_path, prediction_model):
  df = pd.read_csv(ratings_path, encoding='latin-1', sep=',|:', engine='python')

  for row in df.itertuples():
    prediction_model.add_rating(row.UserId, row.ItemId, row.Rating)


def run_predictions(targets_path, prediction_model):
  df = pd.read_csv(targets_path, encoding='latin-1', sep=':')
  print("UserId:ItemId,Rating")
  for row in df.itertuples():
    print("{}:{},{}".format(row.UserId, row.ItemId,
                            prediction_model.predict(row.UserId, row.ItemId)))

def main():
  sgd = predictor.Sgd(epochs=39, learning_ratio=0.0005, n_factors=4, regulation=0.09)
  read_ratings(ratings_path=sys.argv[1], prediction_model=sgd)
  sgd.fit()
  targets_file_path = sys.argv[2]
  run_predictions(targets_file_path, sgd)
  

if __name__ == '__main__':
  main()
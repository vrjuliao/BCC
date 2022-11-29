from content_rocchio import Rocchio
import sys
import pandas as pd

def get_item_contents_data_frame(contents_file):
  content = pd.read_json(contents_file, lines=True)
  content = content[['ItemId', 'Genre', 'imdbVotes']]

  # Gera todas as features em um único campo do DF, separado por espaços.
  content['Genre']    = content['Genre'].map(lambda x: x.lower().replace(', ', ' '))
  content['Features'] = content['Genre']
  content = content.drop(['Genre'], axis=1)

  # Trata os campos que serão utilizados para o desempate na ordenação das recomendações.
  content['imdbVotes'] = content['imdbVotes'].str.replace('N/A', '1', regex=True)
  content['imdbVotes'] = content['imdbVotes'].str.replace(',', '', regex=True)
  content['imdbVotes'] = content['imdbVotes'].astype(str).astype('float64')
  content['imdbVotes'] = content['imdbVotes'].fillna(0.0)

  return content

def sort_recommendations(content, similarities_df):
  sorted_recommendations = similarities_df.merge(content[['ItemId', 'imdbVotes']], on='ItemId')
  sorted_recommendations['Similarity'] = sorted_recommendations['Similarity']*sorted_recommendations['imdbVotes']
  fields_to_be_sorted = ['UserId','Similarity','imdbVotes']
  sorting_order_ascending = [True, False, False]
  sorted_recommendations = sorted_recommendations.sort_values(fields_to_be_sorted, ascending=sorting_order_ascending)
  return sorted_recommendations

def print_sorted_recommendations(sorted_recommendations):
  output_file = sys.stdout
  print('UserId,ItemId', file=output_file)
  pd.set_option("display.max_rows", None, "display.max_columns", None)
  for row in sorted_recommendations.itertuples():
    print('{},{}'.format(row.UserId, row.ItemId), file=output_file)

def main():
  ratings = pd.read_json(sys.argv[1], lines=True)
  content = get_item_contents_data_frame(sys.argv[2])
  targets = pd.read_csv(sys.argv[3], encoding='latin-1', sep=',')

  rocchio = Rocchio(ratings)
  rocchio.fit(content[['ItemId', 'Features']])
  rocchio_similarities = rocchio.predict(targets)

  sorted_recommendations = sort_recommendations(content, rocchio_similarities)
  print_sorted_recommendations(sorted_recommendations)

if __name__ == '__main__':
  main()
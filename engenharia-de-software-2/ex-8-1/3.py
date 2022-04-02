import pydriller
from pydriller.metrics.process.code_churn import CodeChurn
from pydriller.metrics.process.contributors_count import ContributorsCount

hash1 = "f858260790250880fc74ab7108073435f534d7f1"
hash2 = "319f616e572a03b984013d04d1b3a18ffd5b1190"
repo_path = "~/workfolder/dayjs"

churn_metric = CodeChurn(path_to_repo=repo_path,
                   from_commit=hash1,
                   to_commit=hash2)
files_count = churn_metric.count()
files_max = churn_metric.max()
files_avg = churn_metric.avg()
print('Code churn total para cada arquivo: {}'.format(files_count))
print('Maximo code churn para cada arquivo: {}'.format(files_max))
print('Code churn médio para cada arquivo: {}'.format(files_avg))

count_metric = ContributorsCount(path_to_repo=repo_path,
                           from_commit=hash1,
                           to_commit=hash2)
count = count_metric.count()
minor = count_metric.count_minor()
print('Numero de contribuidores por arquivo: {}'.format(count))
print('Numero de contribuidores "menores" por arquivo: {}'.format(minor))
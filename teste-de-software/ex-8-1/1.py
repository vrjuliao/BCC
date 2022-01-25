import pydriller
from datetime import datetime

ff = datetime(2021, 1, 1, 0, 0)
tt = datetime(2021, 12, 31, 23, 59)
repo = pydriller.Repository("~/workfolder/dayjs/", since=ff, to=tt)

for commit in repo.traverse_commits():
    print('{} - {} - {} - {}'.format(commit.hash, commit.committer_date, commit.files ,commit.author.email))
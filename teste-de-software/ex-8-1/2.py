import pydriller

repo = pydriller.Git("~/workfolder/dayjs/")
commit = repo.get_commit("f2e479006a9a49bc0917f8620101d40ac645f7f2")

for file in commit.modified_files:
    print("{} - LOC {} - Ciclomatic Compl {} - Token Count {}".format(file.filename, file.nloc, file.complexity, file.token_count))
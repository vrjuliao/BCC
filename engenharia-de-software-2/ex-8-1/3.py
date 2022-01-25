import pydriller

repo = pydriller.Git("~/workfolder/dayjs/")
hash1 = "f858260790250880fc74ab7108073435f534d7f1"
commit1 = repo.get_commit(hash1)

print("Commit1:",hash1)
added, removed = 0, 0
for file in commit1.modified_files:
    added += file.added_lines
    removed += file.deleted_lines
    print("{} - Added lines {} - Removed Lines {}".format(file.filename, file.added_lines, file.deleted_lines))
print("Total added lines: {} - Total removed lines: {}".format(added, removed))

print()

hash2 = "319f616e572a03b984013d04d1b3a18ffd5b1190"
commit2 = repo.get_commit(hash2)

print("Commit2:",hash2)
added, removed = 0, 0
for file in commit2.modified_files:
    added += file.added_lines
    removed += file.deleted_lines
    print("{} - Added lines {} - Removed Lines {}".format(file.filename, file.added_lines, file.deleted_lines))
print("Total added lines: {} - Total removed lines: {}".format(added, removed))

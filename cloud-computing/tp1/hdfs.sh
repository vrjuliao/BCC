# Create a directory test in the user's directory:
hdfs dfs -mkdir /user/$USER/test
# Adding a file to the filesystem:
hdfs dfs -put $HADOOP_HOME/LICENSE.txt /user/$USER/test
# Listing the contents of a directory:
hdfs dfs -ls /user/$USER/test
# Determine the size of a file on HDFS:
hdfs dfs -du -h /user/$USER/test
# Get the contents of a file, then pike into the `head` command
# to get only the first 10 lines:
hdfs dfs -cat /user/$USER/test/LICENSE.txt | head
# Making a copy of a file:
hdfs dfs -cp /user/$USER/test/LICENSE.txt /user/$USER/test/LICENSE.backup
# Getting a local copy of a file on HDFS:
hdfs dfs -get /user/$USER/test/LICENSE.txt LICENSE.local
# Check the integrity of the filesystem:
hdfs fsck /
# Delete a file on HDFS:
hdfs dfs -rm /user/$USER/test/LICENSE.backup
# Recursively remove a directory on HDFS:
hdfs dfs -rm -r /user/$USER/test
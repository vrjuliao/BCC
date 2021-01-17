#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

cd $DIR
cd instances

start=$(($(date +%s%N)/1000000))
result=$(./../main att48.tsp)
end=$(($(date +%s%N)/1000000))

runtime=$((end-start))
printf "att48.tsp \t $result \t"
printf %.3f\\n "$(($runtime))e-3"


search_dir="EUC_2D"
for entry in "$search_dir"/*
do
  start=$(($(date +%s%N)/1000000))
  result=$(./../main "$entry")
  end=$(($(date +%s%N)/1000000))

  runtime="$((end-start))"
  printf "$entry \t $result \t"
  printf %.3f\\n " $(($runtime))e-3"
done


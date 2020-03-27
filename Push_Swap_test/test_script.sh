#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
RESET='\033[0m'

# input="numsfail.txt"
input="$1"

counter=0
while IFS= read -r line
do
  output="$(./push_swap $line | ./checker $line)"
  # echo "$line"
  numbers=0
  for number in $line
  do
      let numbers++
  done
  let counter++
  if [ "$output" == "OK" ]
  then
    printf "Test $counter\t[$GREEN $output $RESET]\t(for $numbers random numbers)\n"
  else
    printf "Test $counter\t[$RED $output $RESET]\t(for $numbers random numbers)\n"
    exit 1
  fi
done < "$input"


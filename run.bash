#!/bin/bash

#ls b* >bfiles.txt
#
#for i in {1..100}; do {
#  touch "file$i.txt"
#}
#done

#sum=$(($1 + $2))
#product=$(($1 * $2))
#
## Write the numbers, their sum, and their product to the log file
#echo "Numbers: $1, $2" >> logfile.log
#echo "Sum: $sum" >> logfile.log
#echo "Product: $product" >> logfile.log


A=$1
B=$((100 * $A + 5))
C=$2
STRING="yello hat is a string"
SUBSTRING="hat"
expr index "$STRING" "$SUBSTRING"
echo "${#C} ${B}"
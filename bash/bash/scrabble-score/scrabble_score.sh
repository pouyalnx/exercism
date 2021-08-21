#!/usr/bin/env bash

# The following comments should help you get started:
# - Bash is flexible. You may use functions or write a "raw" script.
#
# - Complex code can be made easier to read by breaking it up
#   into functions, however this is sometimes overkill in bash.
#
# - You can find links about good style and other resources
#   for Bash in './README.md'. It came with this exercise.
#
#   Example:
#   # other functions here
#   # ...
#   # ...
#
#   main () {
#     # your main function code here
#   }
#
#   # call main with all of the positional arguments
#   main "$@"
#
# *** PLEASE REMOVE THESE COMMENTS BEFORE SUBMITTING YOUR SOLUTION ***
tb="
letter                           value\n
A,E,I,O,U,L,N,R,S,T       1\n
D,G                               2\n
B,C,M,P                         3\n
F,H,V,W,Y                      4\n
K                                  5\n
J,X                               8\n
Q,Z                               10
"

inp=`echo -n "$1" | tr a-z A-Z`
sum=0
for i in `seq 1 ${#inp}`
do
	digit=`echo -n $inp | head -c $i | tail -c 1` 
	#echo $digit
	score=`echo -e $tb | grep $digit | cut -d ' ' -f 3`
	#echo $score
	score=${score:-0}
	sum=$((sum+score))
done


echo $sum
exit 0

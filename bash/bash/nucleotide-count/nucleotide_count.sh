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

data="$1"

l=${#data}
A=0
C=0
G=0
T=0
for i in `seq 0 $((l-1))`
do
	digit=${data:i:1}
	if [ "$digit" == "A" ]
	then
		A=$((A+1))
        elif [ "$digit" == "C" ]
        then
                C=$((C+1))
        elif [ "$digit" == "G" ]
        then
                G=$((G+1))
        elif [ "$digit" == "T" ]
        then
                T=$((T+1))
	else
		echo "Invalid nucleotide in strand"
		exit 1
	fi
done	

echo -e  "A: $A\nC: $C\nG: $G\nT: $T"
exit 0







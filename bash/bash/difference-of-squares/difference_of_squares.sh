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
n=$2

s1=0
s2=0

for i in `seq 1 $n`
do
	s1=$((s1+i))
	s2=$((s2+i*i))	
done

s1=$((s1*s1))


if [ "$1" == "square_of_sum" ]
then
	echo $((s1))
elif [ "$1" == "sum_of_squares" ]
then
	echo $((s2))
else
	echo $((s1-s2))

fi

exit 0

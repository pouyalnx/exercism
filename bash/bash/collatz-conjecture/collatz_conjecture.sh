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

n=$1
step=0


if [ $n -le 0 ]
then
	echo "Error: Only positive numbers are allowed"
	exit 1
fi


while [ "$n" -ne "1" ]
do
	sp=$((n%2))
	if [ $sp -eq 0 ]
	then
		n=$((n/2))
	else
		n=$((3*n+1))
	fi
	step=$((step + 1))
done


echo $step
exit 0

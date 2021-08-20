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

num=${1:-0}
sum=0
n=${#num}
for i in `seq 1 ${#num}`
do
	digit=`echo -n $num | tail -c $i | head -c1`
	#echo $digit $i $sum
	sum=$((sum + digit**n))
done


if [ $sum -eq $num ]
then
	echo "true"
else
	echo "false"
fi
exit 0


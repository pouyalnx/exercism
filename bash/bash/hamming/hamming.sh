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

l1="$1"
l2="$2"

ll1=${#l1}
ll2=${#l2}
cnt=0

if [ $# -ne 2 ]
then
        echo "Usage: hamming.sh <string1> <string2>"
        exit 1
fi



if [ $ll1 -ne $ll2 ]
then
	echo "left and right strands must be of equal length" 
	exit 1
fi


if [ $# -ne 2 ]
then
	echo "Usage: hamming.sh <string1> <string2>"
	exit 1
fi


for i in `seq 1 $ll1`
do
al1=`echo "$l1" | head -c $i | tail -c1`
al2=`echo "$l2" | head -c $i | tail -c1`

if [  $al1 != $al2 ]
then
	let "cnt += 1"
fi


done



echo "$cnt"
exit 0


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

check=`echo -n $1 | tr -d A | tr -d T | tr -d C | tr -d G`
if [ "$check" != "" ]
then
	echo "Invalid nucleotide detected."
	exit 1
fi



for i in `seq 1 ${#1}`
do
	digit=`echo -n $1 | head -c $i | tail -c1`
	case $digit in
		G ) echo -n "C" ;;
		C ) echo -n "G" ;;
		T ) echo -n "A" ;;
		A ) echo -n "U" ;;
	esac
done

echo
exit 0

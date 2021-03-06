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


if [ "$1" == "total" ]
then
	python -c "print(sum([2**x for x in range(64)]))"
	exit 0
fi

num=${1-:0}

if [ $num -gt 64 -o $num -le 0 ]
then
	echo "Error: invalid input"
	exit 1
fi

python -c "print(2**($num-1))"
exit 0

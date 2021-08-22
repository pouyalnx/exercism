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

if [ $# -ne 2 ] || [ ! -z`echo -n "$1" | tr -d 0-9` ]
then
	echo "Usage: leap.sh <year>"
	exit 1
fi



val=$1

[ $((val%4)) -eq 0 ]
c1=$?

[ $((val%100)) -eq 0 ]
c2=$?

[ $((val%400)) -eq 0 ]
c3=$?


if [ $c1 -eq 0 ] && [ $c2 -eq 1 ] && [ $c3 -eq 1 ]
then
	echo "true"
	exit 0
fi


echo "false"
exit 0



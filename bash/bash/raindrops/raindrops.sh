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

num="$1"
resp=

t=$((num%3))
if [ $t -eq 0 ]
then
	resp=$resp"Pling"
fi
t=$((num%5))
if [ $t -eq 0 ]
then
        resp=$resp"Plang"
fi
t=$((num%7))
if [ $t -eq 0 ]
then
        resp=$resp"Plong"
fi

if [ -z "$resp" ]
then
	resp=$num
fi

echo $resp

exit 0






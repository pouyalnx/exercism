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


data=`echo "$1" | tr 'A-Z' 'a-z' | tr -d 0-9 | tr -d \" | tr -d _ | tr -d , | tr -d . | tr -d - | tr -d ' '`


#test -z `echo -n "$data" | tr -d a-z`

#if [ $? -ne 0 ]
#then
#	echo "false"
#	exit 0
#fi

cnt=$(for i in `seq 1 ${#data}`
do
	digit=`echo $data | head -c $i | tail -c 1`
	echo $digit
done | sort | uniq | wc -l )



if [ $cnt -eq 26 ]
then
	echo "true"
else
	echo "false"
fi

exit 0


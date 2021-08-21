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

inp=`echo -n "$1" | tr -d ' ' | tr -d '\n' | tr -d '\t' | tr -d '\r'`

inp_cap=`echo -n "$inp" | tr a-z A-Z`
inp_has_cap=`echo -n "$inp" | tr -d A-Z`
inp_no_letter=`echo -n "$inp" | tr -d A-Z | tr -d a-z`

lst=`echo -n $inp | tail -c 1`

#echo $inp $inp_cap $lst



if [ -z "$inp" ]
then
        echo "Fine. Be that way!" 
        exit 0
fi


if [ "$inp" == "$inp_cap" ]  && [ "$lst" == "?" ] && [ "$inp_has_cap" != "$inp" ]
then
        echo "Calm down, I know what I'm doing!"
        exit 0
fi



if [ "$lst" == "?" ]
then
        echo "Sure."
        exit 0
fi


if [ "$inp_no_letter" == "$inp" ]
then
	echo "Whatever."
	exit 0
fi


if [ "$inp" == "$inp_cap" ]
then
	echo "Whoa, chill out!"
	exit 0
fi



echo "Whatever."
exit 0

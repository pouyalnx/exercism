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
inp=`echo -en "$1" | tr '&' ' ' | tr '@' ' ' | tr '$' ' ' | tr '%' ' ' | tr '^' ' ' | tr '&' ' ' |  tr $'\n' ' ' | tr '\n' ' ' | tr '.' ' ' | tr ',' ' ' | tr '*' ' ' | tr ':' ' ' | tr '!' ' ' | tr '?' ' ' | tr '"' ' ' | tr A-Z a-z`
for word in $inp
do
	end=`echo -n $word | tail -c1`
	sta=`echo -n $word | head -c1`
	if [ "$end" == "'" ] && [ "$sta" == "'" ]
	then
		echo ${word:1:-1}
	else
		echo $word
	fi

done | sort | uniq -c | sed 's/      //' | awk '{ printf  $2": " $1"\n" }'
 

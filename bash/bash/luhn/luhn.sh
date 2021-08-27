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

inp=`echo "$1" | tr -d ' '`

if [ "${#inp}" -le 1 ]
then
	echo "false"
	exit 0
fi

cs=`echo "$inp" | tr -d 0-9`

if [ "${#cs}" -ge 1 ]
then
	echo "false"
	exit 0
fi


sum=0


[ "${inp:0:1}" -eq "0" ] && inp=${inp:1}
len="${#inp}"
[ "$((len%2))" -eq "1" ] && inp="0$inp" 
len="${#inp}"

for i in `seq 0 $((len-1))`
do
	digit=${inp:i:1}
	if [ $((i%2)) -eq 0 ]
	then
		digit=$((digit*2))
		if [ $digit -gt 9 ]
		then
			digit=$((digit - 9))
		fi
	fi
	sum=$((sum+digit))

done

if [ $((sum%10)) -eq 0 ]
then
	echo "true"
else
	echo "false"
fi

exit 0










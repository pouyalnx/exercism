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

cmd="$1"
a="$2"
b="$3"
c="$4"

l1=`echo "( $a + $b ) > $c" | bc `
l2=`echo "( $b + $c ) > $a" | bc `
l3=`echo "( $a + $c ) > $b" | bc `



if [ "$(( l1 + l2 + l3 ))" -ne "3" ]
then
	echo "false"
	exit 0
fi


l1=`echo "$a == $c" | bc `
l2=`echo "$b == $a" | bc `
l3=`echo "$c == $b" | bc `


if [ "$cmd" == "equilateral" ]
then 
	if [ "$l1" -eq "1" ] && [ "$l2" -eq "1" ] && [ "$l3"  -eq "1" ]
	then
        	echo "true"
	else
        	echo "false"
	fi
elif [ "$cmd" == "isosceles" ]
then
	
	if [ "$l1" -eq "1" ] || [ "$l2" -eq "1" ] || [ "$l3"  -eq "1" ]
	then
		echo "true"
	else
		echo "false"
	fi
else
	if [ "$((l1+l2+l3))" -eq "0" ]
	then
                echo "true"
        else
                echo "false"
        fi
		
fi

exit 0

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
number=`echo -n "$1" | tr -d ' ' | tr -d ',' | tr -d '.' | tr -d '-' | tr -d '(' | tr -d ')' | tr -d '_'`

l=${#number}
f0=${number:0:1}
f1=${number:1:1}

if [ "$l" -eq "12" ]
then
	if [ "$f1" -eq "1" ] && [ "$f0" == "+" ] 
	then
		number=${number:2}
	else
		echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
		exit 1
	fi
elif [ "$l" -eq "11" ]
then
        if [ "$f0" -eq "1" ]
        then
                number=${number:1}
        else
                echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
                exit 1
        fi

elif [ "$l" -ne  "10" ]
then
	echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
        exit 1
fi



l0=${number:0:1}
if [ "`echo -n $l0 | tr -d 2-9`" != "" ]
then
 	echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi

l1=${number:1:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi
l0=${number:2:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi
l0=${number:3:1}
if [ "`echo -n $l0 | tr -d 2-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi


l0=${number:4:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
 	echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
        exit 1
fi


l0=${number:5:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi
l0=${number:6:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi

l0=${number:7:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi
l0=${number:8:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi

l0=${number:9:1}
if [ "`echo -n $l0 | tr -d 0-9`" != "" ]
then
        echo "Invalid number.  [1]NXX-NXX-XXXX N=2-9, X=0-9"
       exit 1
fi



echo $number
exit 0





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
val=$1
dg0=$((val%2))
val=$((val/2))
dg1=$((val%2))
val=$((val/2))
dg2=$((val%2))
val=$((val/2))
dg3=$((val%2))
left=$((val/2))
dg4=$((val%2))
left=$((val/2))
dg4=$left
resp=""
pos=0

if [ $dg0 -eq 1 ]
then
    resp[pos]="wink"
        pos=$((pos+1))
fi

if [ $dg1 -eq 1 ]
then
    resp[pos]="double blink"
    pos=$((pos+1))
fi

if [ $dg2 -eq 1 ]
then
    resp[pos]="close your eyes"
    pos=$((pos+1))
fi

if [ $dg3 -eq 1 ]
then
    resp[pos]="jump"
    pos=$((pos+1))
fi

if [ $dg4 -eq 0 ]
then
    df=`seq 0 $((pos-1))`
else
    df=`seq $((pos-1)) -1 0`
fi

t=0
for i in $df
do
    if [ $t -ne 0 ]
    then
        echo -n ","
    fi
    t=$((t+1))
    echo -n ${resp[i]}
done 

echo
exit 0


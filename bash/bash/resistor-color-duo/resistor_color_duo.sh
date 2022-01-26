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
value=0
result=0

convert(){
    declare -g value=0
    case "$1" in
    "black") value=0;;
    "brown") value=1;;
    "red") value=2;;
    "orange") value=3;;
    "yellow") value=4;;
    "green") value=5;;
    "blue") value=6;;
    "violet") value=7;;
    "grey") value=8;;
    "white") value=9;;
    *)value=-1;;
    esac
}


convert "$1" 
if [ $value -eq "-1" ]
then
    echo "invalid color"
    exit 1
fi
result=$value

convert "$2"
if [ $value -eq "-1" ]
then
    echo "invalid color"
    exit 1
fi

result=$((result*10 + value))
echo $result
exit 0
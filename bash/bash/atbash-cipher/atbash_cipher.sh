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
result=
converter_ci(){
    declare -g result
    case "$1" in
    "a"|"A" ) result="z";;
    "b"|"B" ) result="y";;
    "c"|"C" ) result="x";;
    "d"|"D" ) result="w";;
    "e"|"E" ) result="v";;
    "f"|"F" ) result="u";;   
    "g"|"G" ) result="t";;
    "h"|"H" ) result="s";;
    "i"|"I" ) result="r";;
    "j"|"J" ) result="q";;
    "k"|"K" ) result="p";;
    "l"|"L" ) result="o";;  
    "m"|"M" ) result="n";;
    "n"|"N" ) result="m";;
    "o"|"O" ) result="l";;
    "p"|"P" ) result="k";;
    "q"|"Q" ) result="j";;
    "r"|"R" ) result="i";;
    "s"|"S" ) result="h";;
    "t"|"T" ) result="g";;
    "u"|"U" ) result="f";;
    "v"|"V" ) result="e";;
    "w"|"W" ) result="d";;
    "x"|"X" ) result="c";;
    "y"|"Y" ) result="b";;
    "z"|"Z" ) result="a";;
    "1" ) result="1";;
    "2" ) result="2";;
    "3" ) result="3";;
    "4" ) result="4";;     
    "5" ) result="5";;  
    "6" ) result="6";;
    "7" ) result="7";;
    "8" ) result="8";;
    "9" ) result="9";;                
    *   ) result="";;
    esac     
}

inp="$2"
l=${#inp}

cnt=0
for i in `seq 1 $l`
do
    word=`echo $inp | head -c $i | tail -c 1`
    converter_ci $word
    echo -n $result
    if [ ! $result == "" ] && [ $1 == "encode" ]
    then
        cnt=$((cnt+1))
    fi
    if [ $cnt -eq 5 ] && [ $((i+1)) -ne $l ]
    then
        echo -n  " "#"-$i|$l-"
        cnt=0
    fi
done
echo
exit 0

#"gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt"

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

prA=`echo -n $1 | tr A-Z a-z`
key=`python -c "print(sorted(list(\"$prA\")))"`
frst=""
for word in $2
do
	pr=`echo -n $word | tr A-Z a-z`
	key_pat=`python -c "print(sorted(list(\"$pr\")))"`
	if [ "$key" == "$key_pat" ] && [ "$prA" != "$pr" ]
	then
		echo -n "${frst}${word}"
		frst=" "
	fi
done
echo
exit 0

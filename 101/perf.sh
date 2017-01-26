#! /bin/bash

NB_TEST=1
PARAMS="10000 100000 1000000 10000000"

for param in $PARAMS
do
	for test in `seq $NB_TEST`
	do
		echo -en "$test\t$param\t"
		(/usr/bin/time -f "%U\t%M" ./recherche $param > /dev/null) 2>&1
	done
done
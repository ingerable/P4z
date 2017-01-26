#! /bin/bash

NB_TEST=10

for test in `seq $NB_TEST`
do
	echo -en "$test\t"
	/usr/bin/time -f "%U\t%M" ./recherche 100000 > /dev/null
done
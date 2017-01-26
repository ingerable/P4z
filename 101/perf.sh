#! /bin/bash

NB_TEST=10

FUNS="generer_tableau afficher_tableau rechercher"

echo -e "test\ttaille\texectime\tmemory\tgenerer_tableau\tafficher_tableau\trechercher"

for test in `seq $NB_TEST`
do
	param="${RANDOM}000"

	echo -en "$test\t$param\t"
	echo -en `(/usr/bin/time -f "%U\t%M" ./recherche $param > /dev/null) 2>&1`
	
	gprof recherche > /tmp/gprof.out
	for fun in $FUNS
	do
		echo -en "\t`cat /tmp/gprof.out | grep $fun | awk '{print $6}' | head -1`"
	done

	echo 

done

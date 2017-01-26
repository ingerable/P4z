#! /bin/bash

NB_TEST=30

FUNS="generer_tableau afficher_tableau rechercher"

EXES="rechercheV0 recherche"

echo -e "test\ttaille\texe\texectime\tmemory\tgenerer_tableau\tafficher_tableau\trechercher"

for test in `seq $NB_TEST`
do
	param="${RANDOM}000"

	for exe in $EXES
	do
		(
			echo -en "$test\t$param\t$exe\t"
			echo -en `(/usr/bin/time -f "%U\t%M" ./$exe $param $test > /dev/null) 2>&1`

			gprof $exe > /tmp/gprof.out
			for fun in $FUNS
			do
				echo -en "\t`cat /tmp/gprof.out | grep $fun | awk '{print $6}' | head -1`"
			done

			echo 
		) &
	done

done

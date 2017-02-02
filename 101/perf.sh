#! /bin/bash

NB_TEST=100

FUNS="generer_tableau afficher_tableau rechercher"

EXES="rechercheV0 rechercheV1 rechercheV2"

echo -e "test\ttaille\texe\texectime\tmemory\tgenerer_tableau\tafficher_tableau\trechercher"


for test in `seq $NB_TEST`
do
	param="${RANDOM}000"

	PIDS=""

	for exe in $EXES
	do
		(
			RES="$test\t$param\t$exe\t"
			RES="$RES`(/usr/bin/time -f "%U\t%M" ./$exe $param $test > /dev/null) 2>&1`"

			gprof $exe > /tmp/gprof.$exe.out
			for fun in $FUNS
			do
				RES="$RES\t`cat /tmp/gprof.$exe.out | grep $fun | awk '{print $6}' | head -1`"
			done

			echo -e $RES

		)  &
		PIDS="$PIDS $!"
	done

	wait $PIDS

done

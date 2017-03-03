#! /bin/bash

NB_TEST=100

FUNS="insert"

EXES="insertion"

echo -e "test\ttaille\texe\texectime\tmemory\tgenerer_tableau\tinsert"


for test in `seq $NB_TEST`
do
	param=$((($RANDOM*1000)%60000))

	PIDS=""

	for exe in $EXES
	do
		(
			RES="$test\t$param\t$exe\t"
			RES="$RES`(/usr/bin/time -f "%U\t%M" ./$exe $param > /dev/null) 2>&1`"

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

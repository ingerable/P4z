#! /bin/bash

NB_TEST=500

FUNS="TriFusion"

EXES="fusDec fusCroi fusAlea"

echo -e "test\ttaille\texe\texectime\tmemory\tmmm"


for test in `seq $NB_TEST`
do
	param=$((($RANDOM*20)))
	#param=350000

	PIDS=""

	for exe in $EXES
	do
		(
			RES="$test\t$param\t$exe\t"
			RES="$RES`(/usr/bin/time -f "%U\t%M" ./$exe $param > /dev/null) 2>&1`"

			gprof $exe > ./gprof.$exe.out
			for fun in $FUNS
			do
				RES="$RES\t`cat ./gprof.$exe.out | grep $fun | awk '{print $4}' | head -1`"
			done

			echo -e $RES

		)  &
		PIDS="$PIDS $!"
	done

	wait $PIDS

done


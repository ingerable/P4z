#! /bin/bash

NB_TEST=200	

ARGSTRI="insertion"

ARGSTAB="croissant"

echo -e "test\ttaille\ttri\ttableau\texe\texectime\tmemory"

EXE="nonOpti opti"


for test in `seq $NB_TEST`
do
	taille=$((($RANDOM*1000)))

	for tri in $ARGSTRI
	do
		for exe in $EXE
		do
		
			for tab in $ARGSTAB
			do
				(
				RES="$test\t$taille\t$tri\t$tab\t$exe\t"
				RES="$RES`(/usr/bin/time -f "%U\t%M" ./$exe $taille $tri $tab> /dev/null) 2>&1`"

				echo -e $RES
				)  &
				while [ `ps -A | grep -c main` -ge 3 ]
				do 
					sleep 1
				done
			done 
		done

	done

	

done


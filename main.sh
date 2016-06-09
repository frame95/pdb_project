#!/bin/bash

cd utilities;
if [ `./is_protein ".$1"` -eq 0 ]; then
	echo "$1 non è una proteina.";
	exit 1;
fi

if [ `./is_protein ".$2"` -eq 0 ]; then
	echo "$2 non è una proteina.";
	exit 1;
fi

cd ..;
rm result.txt;
cd body;

A=$( ./MCCIS ".$1" ".$2" );

read -r BOND1 S1 < <( ./guarantee ".$1" );
read -r BOND2 S2 < <( ./guarantee ".$2" );

APPR1=$( echo "100*$A/(($BOND1+1)*($A+$S1))" | bc -l );
APPR2=$( echo "100*$A/(($BOND2+1)*($A+$S2))" | bc -l );

if [ $(echo "$APPR1 < $APPR2" | bc -l) -eq 1 ] ; then
	S=$APPR2;
else
	S=$APPR1;
fi

cd ..;
printf "Garanzia: la soluzione è almeno il %.2f%% della soluzione ottima.\n" $(echo -n "$S" | sed "s/\./,/g" ) >> result.txt;
cat result.txt;


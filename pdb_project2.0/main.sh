#!/bin/bash

rm result.txt;
./MCCIS "$1" "$2";
a=`./guarantee "$1"`;
b=`./guarantee "$2"`;
if [ "$a" -lt "$b"  ]; then
	S=$(echo "100/$a" | bc -l);
else
	S=$(echo "100/$b" | bc -l);
fi
printf "Garanzia: la soluzione è il %.2f%% della soluzione ottima.\n" $(echo -n "$S" | sed "s/\./,/g" ) >> result.txt;
cat result.txt;


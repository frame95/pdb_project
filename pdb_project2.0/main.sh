#!/bin/bash

./MCCIS;
a=`./guarantee "./input/proteina_A.txt"`;
b=`./guarantee "./input/proteina_B.txt"`;
if [ -lt "$a" "$b"  ]; then
	S=$(echo "100/$a" | bc -l);
else
	S=$(echo "100/$b" | bc -l);
fi
echo "Garanzia: la soluzione è il $S della soluzione ottima.\n" >> result.txt;

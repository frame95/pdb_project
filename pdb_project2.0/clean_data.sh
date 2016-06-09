#!/bin/bash

for F in $(ls ./rough_data); do
	if [ $(./is_protein ./rough_data/$F) -eq 0 ]; then
		rm ./rough_data/$F;
		echo "Removing $F..";
	fi 
done

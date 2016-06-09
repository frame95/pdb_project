#!/bin/bash

for D in `ls ../temporary/`; do
	for F in `ls ../temporary/$D`; do 
		if [[ $F =~ .*?\.gz ]]; then
			gunzip "../temporary/$D/$F";
			echo "Unzipping $F..";
		fi
	done
done

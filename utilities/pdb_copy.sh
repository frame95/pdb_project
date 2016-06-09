#!/bin/bash

for D in `ls ../temporary/`; do
	for F in `ls ../temporary/$D`; do 
		echo "Copying $F..";
		mv "../temporary/$D/$F" "../rough_data/";
	done
done

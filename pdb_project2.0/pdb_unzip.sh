#!/bin/bash

for D in `ls ../temporary/`; do
	for F in `ls ../temporary/$D`; do 
		if [[ $F =~ .*?d\..*? ]]; then
			rm "../temporary/$D/$F";
		elif [[ $F =~ .*?\.gz ]]; then
			gunzip "../temporary/$D/$F";
		fi
	done
done

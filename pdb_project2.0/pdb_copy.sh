#!/bin/bash

for D in `ls ../temporary/`; do
	for F in `ls ../temporary/$D`; do 
		mv "../temporary/$D/$F" "./";
	done
done

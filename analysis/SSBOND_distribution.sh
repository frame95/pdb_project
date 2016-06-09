#!/bin/bash

for F in `ls ../rough_data/`; do
	echo "Analyzing $F..";
	./SSBOND_distribution "../rough_data/$F";
done

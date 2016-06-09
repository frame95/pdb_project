#!/bin/bash

for F in `ls ../rough_data/`; do
	echo "Analyzing $F..";
	./SSBOND_distribution_named "../rough_data/$F";
done

for F in `find ../clean_data/ -type f`
do
	echo $F
	./linker $F
done
	

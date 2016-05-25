#include "../pdb_lib/protein.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	printf("** INIZIALIZZAZIONE ** \n"); getchar();
	protein P;
	FILE * fin;
	fin=fopen(argv[1], "r");
	P.plain_read(fin);
	fclose(fin);
	
	printf("** LINKING ** \n"); getchar();
	P.link();
	
	printf("** SCRITTURA ** \n");
	FILE *fout;
	fout =fopen(argv[1], "w+");
	P.write(fout);
	fclose(fout);
	
	return 0;
}

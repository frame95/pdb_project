#include "../pdb_lib/protein.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	protein P;
	FILE * fin;
	fin=fopen(argv[1], "r");
	P.plain_read(fin);
	fclose(fin);
	P.link();
	FILE *fout;
	fout =fopen(argv[1], "w+");
	P.write(fout);
	fclose(fout);
	
	return 0;
}

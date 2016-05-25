#include "protein.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[] ) {
	printf("FIRST SECTION : ATOM ---------------	\n"); getchar();

	printf(" ** INIZIALIZZAZIONE ** \n"); getchar();
	atom A(0,1.22,4.3,1,72);
	
	printf(" ** SCRITTURA ** \n"); getchar();
	FILE *fout;
	fout =fopen(argv[1], "w");
	A.write(fout);
	fclose(fout);
	
	printf(" ** LETTURA ** \n"); getchar();
	FILE *fin;
	fin =fopen(argv[1], "r");
	A.read(fin);
	A.write(stdout);
	fclose(fin);
	
	printf("SECOND SECTION: PROTEIN ------------- \n"); getchar();
	
	printf(" ** INIZIALIZZAZIONE ** \n"); getchar();
	protein P; int check=1;
	while(check==1) {
		printf("Vuoi aggiungere un atomo (1 si, 0 no)?\n");
		cin >> check;
		if(check==1) {
			atom A;
			printf("Inserisci le tre coordinate:\n");
			cin >> A.coord[0] >> A.coord[1] >> A.coord[2];
			printf("Inserisci il numero seriale:\n");
			cin >> A.serial;
			printf("Inserisci il numero di catena:\n");
			cin >> A.chainId;
		}
		P.add_atom(A);
	}
	return 0;
}

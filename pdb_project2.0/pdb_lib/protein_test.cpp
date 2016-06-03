#include "protein.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[] ) {
	printf("FIRST SECTION : ATOM ---------------	\n"); getchar();

	printf(" ** INIZIALIZZAZIONE ** \n"); getchar();
	atom A(1.22,4.3,1,72, 'C');
	
	printf(" ** SCRITTURA ** \n"); getchar();
	FILE *fout;
	fout =fopen(argv[1], "w+");
	A.write(fout);
	fclose(fout);
	
	printf(" ** LETTURA ** \n"); getchar();
	FILE *fin; atom B;
	fin =fopen(argv[1], "r");
	B.read(fin);
	B.write(stdout);
	fclose(fin);
	
	printf("SECOND SECTION: PROTEIN ------------- \n"); getchar();
	
	printf(" ** INIZIALIZZAZIONE ** \n"); getchar();
	protein P; int check=1; atom C;
	while(check==1) {
		printf("Vuoi aggiungere un atomo (1 si, 0 no)?\n");
		cin >> check;
		if(check==1) {
			printf("Inserisci le tre coordinate:\n");
			cin >> C.coord[0] >> C.coord[1] >> C.coord[2];
			printf("Inserisci il numero di catena:\n");
			cin >> C.chainId;
			printf("Inserisci il tipo:\n");
			cin >> C.type;
			P.add_atom(C);
		}
		
	}
	
	printf(" ** LINKING ** \n"); getchar();
	P.link();
	
	printf(" ** SCRITTURA ** \n"); getchar();
	fout=fopen(argv[1], "w+");
	P.write(fout);
	fclose(fout);
	
	printf(" ** LETTURA ** \n"); getchar();
	fin=fopen(argv[1], "r"); protein Q;
	Q.read(fin);
	Q.write(stdout);
	fclose(fin);	
	
	return 0;
}

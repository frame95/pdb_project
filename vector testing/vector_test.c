#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {
	char temp,check; int numb, cock;
	// INIZIALIZZAZIONE
	vector V=vector_init();
	
	// STAMPA
	printf("Actual state:\n");
	vector_print(V, stdout);
	
	// INSERIMENTO E MODIFICA
	do {	
		//if(check == '\n') {
		//	scanf("%c", &check);
			printf("Inserisci:\n");
			printf("\tq, per uscire;\n");
			printf("\ti, per inserire;\n");
			printf("\tm, per modificare;\n");
			printf("\ts, per stampare.\n");
			fflush(stdin); scanf("%c", &check); 
			printf("Hai digitato queswto cazzo di carattere : %c\n", check);
			getchar();
		
		//} else {
			switch(check) {
			
				case 'i':
					printf("Inserisci un numero:\n");
					scanf("%d", &numb); fflush(stdin);
					vector_add(&V, numb);
					break;
			
				case 'm':
					printf("Inserisci un indice minore di %d", V.full);
					scanf("%d", &numb); fflush(stdin);
					printf("Inserisci un numero:\n");
					scanf("%d", &cock); fflush(stdin);
					V.in[numb]=cock;
					break;
		
				case 's':
					vector_print(V, stdout);
					break;
			
				default:
					printf("porcatroia!\n");
					printf("Ritenta, sarai più fortunato.\n");
					break;
			}
		//}
	} while(check!='q');

	return 0;
}

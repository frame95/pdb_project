#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "./pdb_lib2.0/linear_protein.h"

using namespace std;

int main(int argc, char * argv[]) {
	FILE *weight_file, *dictionary,*fout;
	ifstream fin_A, fin_B;
	int i,j;
	fin_A.open(argv[1]);
	fin_B.open(argv[2]);
	fout=fopen("result.txt", "a");
	weight_file=fopen("./weight/ammino_weight.txt", "r");
	dictionary=fopen("./weight/ammino_dictionary.txt", "r");
	
	//LETTURA MATRICE DEI PESI
	int M[20][20];
	for(i=0;i<20;i++) {
		for(j=i;j<20;j++) {
			fscanf(weight_file,"%d", &M[i][j]);
			M[j][i]=M[i][j];
		}	
	}
	
	//LETTURA DIZIONARIO
	char D[20][3]; int dummy;
	for(i=0;i<20;i++) {
		fscanf(dictionary, "%d %s", &dummy, &D[i]);
	}
	
	//LETTURA PROTEINE
	protein A,B;
	A.read(&fin_A, D); B.read(&fin_B, D);
	
	// ALGORITMO RISOLUTIVO
	int result=0;
	for(i=0;i<A.Subunit.size();i++) {
		for(j=0;j<B.Subunit.size();j++) {
				result=max(result, A.Subunit[i].match(B.Subunit[j], M)); 
		}
	}
	
	fprintf(fout, "Massima componente connessa indotta comune trovata: %d\n", result);
	return 0;
}

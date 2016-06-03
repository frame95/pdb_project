#include <stdio.h>
#include <vector>
#include "linear_protein.h"
using namespace std;


int main() {
	int i, dummy,j;
	//DICTIONARY LOADING TEST
	printf("Loading dictionary..\n"); getchar();
	FILE *dict;
	dict=fopen("../weight/ammino_dictionary.txt", "r");
	char dictionary[20][3];
	for(i=0;i<20;i++) {
		fscanf(dict, "%d %s",&dummy, &dictionary[i]);
		printf("%d is %s\n", i, dictionary[i]);
	}
	
	// WEIGHT LOADING TEST
	printf("Loading weights..\n"); getchar();
	FILE *we;
	we=fopen("../weight/ammino_weight.txt", "r");
	int weight[20][20];
	for(i=0;i<20;i++) {
		for(j=i;j<20;j++) {
			fscanf(we,"%d", &weight[i][j]);
			weight[j][i]=weight[i][j];
			printf("%d ", weight[i][j]);
		}	
		printf("\n");
	}
	
	// AMMINOACID TEST
	amminoacid A;
	A.ResSeqName[0]='T';
	A.ResSeqName[1]='H';
	A.ResSeqName[2]='R';
	A.ResSeqNum=13;
	
	printf("Identifying %s..\n", A.ResSeqName); getchar();
	A.identify(dictionary);
	printf("%s correspond to %d", A.ResSeqName, A.ResId); getchar();
	
	printf("Amminoacid description:\n");
	A.print(stdout);
	
	// POLYPEPTID TEST
	polypeptid P;
	P.Seq.push_back(A);
	amminoacid B;
	B.ResSeqName[0]='S';
	B.ResSeqName[1]='E';
	B.ResSeqName[2]='R';
	B.ResSeqNum=12;
	B.identify(dictionary);
	P.Seq.push_back(B);
	P.chainId='A';
	
	printf("Printing polypeptid P..\n"); getchar();
	P.print(stdout);
	
	polypeptid Q;
	Q.Seq.push_back(A);
	Q.Seq.push_back(B);
	Q.chainId='B';
	
	printf("Matching polypeptid P,Q..\n"); getchar();
	printf("MCCIS: %d", P.match(Q,weight));
	return 0;
}

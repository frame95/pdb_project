#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "../pdb_lib/protein.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	FILE *dictionary;
	dictionary=fopen("../weight/ammino_dictionary.txt", "r");
	int i; int check; int found;
	
	char D[20][3]; int dummy;
	for(i=0;i<20;i++) {
		fscanf(dictionary, "%d %s", &dummy, &D[i]);
	}
	
	atom A;
	ifstream fin;
	fin.open(argv[1]);
	string line;

	while(getline(fin,line)) {
		if((line.substr(0,4).compare("ATOM") == 0) ) {
			A.readline(line);
			found=0;
			for(i=0;i<20;i++){
				check=1; 
				if(D[i][0] != A.ResName.at(0)) check=0; 
				if(D[i][1] != A.ResName.at(1)) check=0; 
				if(D[i][2] != A.ResName.at(2)) check=0; 
				if(check==1) {
					found=1;
				}
			}
			
			if(found==0 ) {
				printf("0");
				fin.close();
				return 0;
			}
		}
	}

	fin.close();
	printf("1");
	return 1;
}

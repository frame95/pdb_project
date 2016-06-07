#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "./pdb_lib/protein.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	int mixing_SSBOND=0;
	int cycling_SSBOND=0;
	vector<atom> cys;
	atom A;
	int i,j, atom_number=0;
	float d;
	ifstream fin;
	fin.open(argv[1]);
	
	string line;
	while(getline(fin,line)) {
		if((line.substr(0,4).compare("ATOM") == 0) ) {
			atom_number++;
			if (line.at(77) == 'S') {
				A.readline(line);
				cys.push_back(A);
			}
		}
	}
	
	for(i=0;i<cys.size();i++) {
		for(j=i+1;j<cys.size();j++) {
			d=cys[i].distance(cys[j]);
			if( d<=3.2 && d>=2) {
				if(cys[i].ResSeqNum == cys[j].ResSeqNum) {
					cycling_SSBOND++;
				} else {
					mixing_SSBOND++;
				}
			} 
		}
	}

	fin.close();	
	printf("%d", mixing_SSBOND + cycling_SSBOND+1);
	return mixing_SSBOND + cycling_SSBOND;
}

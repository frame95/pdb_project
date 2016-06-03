#ifndef _PDB_LINEAR_PROTEIN__
#define _PDB_LINEAR_PROTEIN__ 

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int max(int a, int b) {
	return (a>b)?a:b;
}

int min(int a, int b) {
	return (a<b)?a:b;
}

class amminoacid {
	public:
		char ResSeqName[3];
		int ResSeqNum;
		int ResId;
		amminoacid(){};
		
		int identify(char dictionary[20][3]) {
			int i; int check;
			for(i=0;i<20;i++){
				check=1; 
				if(dictionary[i][0] != ResSeqName[0]) check=0; 
				if(dictionary[i][1] != ResSeqName[1]) check=0; 
				if(dictionary[i][2] != ResSeqName[2]) check=0; 
				if(check == 1) {
					ResId=i; 
					return 1;
					}
			}
			return 0;
		}
		
		void print(FILE *output) {
			fprintf(output, "%s (%d) at %d\n", ResSeqName, ResId, ResSeqNum);
			return;
		
		}
	};
	
class polypeptid {
	public:
		vector<amminoacid> Seq;
		char chainId;
		polypeptid(){};
		
		void print(FILE* output) {
			int i;
			fprintf(output, "UNIT %c\n", chainId);
			for(i=0;i<Seq.size();i++) { 
				Seq.at(i).print(output);
			}
			return;
		}
		
		// Senza accortezza per evitare di matchare coppie di CYS, una con SSBOND, l'altra no
		int match(polypeptid B, int weight[20][20] ) { 
			int N=Seq.size();
			int M=B.Seq.size();
			int dp[N+1][M+1];
			int i,j;
			for(i=0;i<N+1;i++) {
				dp[i][0]=0;
			}
			for(j=0;j<M+1;j++) {
				dp[0][j]=0;
			}
			for(i=2;i<=N+M;i++) {
				for(j=max(1, i-M);j<=min(N,i-1);j++) {
					dp[j][i-j] = dp[j-1][i-j-1]+weight[Seq.at(j).ResId][B.Seq.at(i-j).ResId];
				}
			}
			int result=0;
			for(i=1;i<N+1;i++) {
				result=max(result, dp[i][M]);
			}
			for(j=1;j<M+1;j++) {
				result=max(result, dp[N][j]);
			}
			return result;
		
		}
	};
	
class protein {
	public:
		vector<polypeptid> Subunit;
		protein(){};
		
		void read(ifstream input, char dictionary[20][3]) {
			string line;
			int counter=0;
			int actual_resnum=-1;
			char actual_unit='Z';
			while(getline(input,line)) {
				if((line.substr(0,4).compare("ATOM") == 0) ) {
					
					if(line.at(22) != actual_unit) {
						Subunit.resize(Subunit.size()+1);
						Subunit.at(Subunit.size()-1).chainId=line.at(22);
						actual_unit=line.at(22);
					} 
					
					if(atoi(line.substr(22,26).c_str()) != actual_resnum) {
						actual_resnum=atoi(line.substr(22,26).c_str());
						Subunit.at(Subunit.size()-1).Seq.resize(Subunit.at(Subunit.size()-1).Seq.size()+1);
						Subunit.at(Subunit.size()-1).Seq.at(Subunit.size()-1).ResSeqNum=actual_resnum;
						Subunit.at(Subunit.size()-1).Seq.at(Subunit.size()-1).ResSeqName[0]=line.at(17);
						Subunit.at(Subunit.size()-1).Seq.at(Subunit.size()-1).ResSeqName[1]=line.at(18);
						Subunit.at(Subunit.size()-1).Seq.at(Subunit.size()-1).ResSeqName[2]=line.at(19);
						if( !Subunit.at(Subunit.size()-1).Seq.at(Subunit.size()-1).identify(dictionary) ) {
							fprintf(stderr, "An error occurred: cannot identify UNIT %c, SEQNUM %d, RESNAME %s.\n", actual_unit, actual_resnum, line.substr(17,20).c_str() );
						}
					}
				}
			}
			return;
		}
		
		void print(FILE* output) {
			int i, j;
			for(i=0;i<Subunit.size();i++) {
				Subunit.at(i).print(output);
			}
			return;
		}
		
	};

#endif

#ifndef __PDB_LIB__ 
#define __PDB_LIB__ 1

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <math.h>
#include <string>

using namespace std;

class atom {
	
	public:
		float coord[3];
		int ResSeqNum;
		string ResName;
		char type;
		atom(){};
		atom(float coord1, float coord2,float coord3,int cha, char ty) {
			coord[0]=coord1;
			coord[1]=coord2;
			coord[2]=coord3;
			ResSeqNum=cha;
			type=ty;
		}
	
		void write(FILE * output) { //aggiorna con nuovi parametri
			fprintf(output, "%d ", ResSeqNum);
			fprintf(output, "%f %f %f ", coord[0], coord[1], coord[2]);
			fprintf(output, "%c\n", type);
			return;
		}

		void read( FILE * input) { //aggiorna con nuovi parametri
			fscanf(input, "%d", &ResSeqNum);
			fscanf(input, "%f %f %f", &coord[0], &coord[1], &coord[2]);
			fscanf(input, " %c", &type);
			return;
		}
		
		float distance (atom A) {
			return pow(pow(A.coord[0]-coord[0],2)+pow(A.coord[1]-coord[1],2)+pow(A.coord[2]-coord[2],2),0.5);
			}
		
		void readline(string line) {
			ResSeqNum=atoi(line.substr(22,25).c_str());
			ResName=line.substr(17,19);
			coord[0]=atof(line.substr(30,37).c_str());
			coord[1]=atof(line.substr(38,45).c_str());
			coord[2]=atof(line.substr(46,53).c_str());
			type=line.at(77);
			return;
		}
		
	
	};

// Il protein serve se un giorno vorrò reperire la MCCIS come grafo e non solo la grandezza.
class protein {
	
	public:
		graph space;
		vector<atom> content;
		protein(){};
		
		void read(FILE * input) {
			int i,a;
			printf("Reading graph.\n"); getchar();
			space.read(input);
			printf("Resizing content to %d. \n", space.adj.size()); getchar();
			content.resize(space.adj.size());
			for(i=0;i<content.size();i++) {
				printf("reading dummy character (i=%d).\n",i); getchar();
				fscanf(input, "%d", a);
				printf("Reading atom.\n"); getchar();
				content[i].read(input);
			}
			return;
		}
		
		void plain_read(FILE * input) {
			int i,n; atom C;
			fscanf(input, "%d", &n);
			for(i=0;i<n;i++) {
				C.read(input);
				add_atom(C);
			}
			return;		
		}
		
		void write(FILE * output) {
			int i;
			space.write(output);
			for(i=0;i<content.size();i++) {
				fprintf(output, "%d ", i);
				content[i].write(output);
			}			
			return;
		}

		void add_atom(atom A) {
			content.push_back(A);
			space.add_node();
			return;
		}

		void link() { // rough version
			int i,j; float d;
			for(i=0; i<space.adj.size(); i++) {
				for(j=i+1; j<space.adj.size(); j++) {
					d=content[i].distance(content[j]);
					if((d <= 3.2) && ( d>=2) ){
						space.add_edge(i,j);
					}
				}
			}
			return;
		}

	};



#endif

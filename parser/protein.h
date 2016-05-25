#ifndef __PDB_LIB__ 
#define __PDB_LIB__ 1

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <math.h>

using namespace std;

class atom {
	
	public:
		float coord[3];
		int serial;
		int chainId;
		atom(){};
		atom(float coord1, float coord2,float coord3,int ser,int cha) {
			serial=ser;
			coord[0]=coord1;
			coord[1]=coord2;
			coord[2]=coord3;
			chainId=cha;
		}
	
		void write(FILE * output) {
			fprintf(output, "%d\n", serial);
			fprintf(output, "%f %f %f\n", coord[0], coord[1], coord[2]);
			fprintf(output, "%d\n", chainId);
			return;
		}

		void read( FILE * input) {
			fscanf(input, "%d", &serial);
			fscanf(input, "%f %f %f", &coord[0], &coord[1], &coord[2]);
			fscanf(input, "%d", &chainId);
			return;
		}
		
		float distance (atom A) {
			return pow(pow(A.coord[0]-coord[0],2)+pow(A.coord[1]-coord[1],2)+pow(A.coord[2]-coord[2],2),0.5);
			}
	
	};


	//
	//}

class protein {
	
	public:
		graph space;
		vector<atom> content;
		protein(){};
		
		void read(FILE * input) {
			int i;
			space.read(input);
			for(i=0;i<space.adj.size();i++) {
				content[i].read(input);
			}
			return;
		}

		void write(FILE * output) {
			int i;
			space.write(output);
			for(i=0;i<content.size();i++) {
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

/* 
*/

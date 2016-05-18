#ifndef __PDB_LIB__ 
#define __PDB_LIB__ 1

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <math.h>

using namespace std;

class atom {
	
	public:
		float[3] coord;
		int serial;
		int chainId;
		atom::atom();

		void atom::write(FILE * output) {
			fprintf(output, "%d\n", serial);
			fprintf(output, "%f %f %f\n", coord[0], coord[1], coord[2]);
			fprintf(output, "%d\n", chainId);
			return;
		}

		void atom::read( FILE * input) {
			fscanf(input, "%d", &serial);
			fscanf(input, "%f %f %f", &coord[0], &coord[1], &coord[2]);
			fscanf(input, "%d", &chainId);
			return;
		}

	};

float distance (atom A, atom B) {
	return sqrt( (A.coord[0]-B.coord[0])^2+(A.coord[1]-B.coord[1])^2+(A.coord[2]-B.coord[2])^2);
	}

class protein {
	
	public:
		graph space;
		vector<atom> content;
		protein::protein();
		
		void protein::read(FILE * input) {
			int i;
			space.read(input);
			for(i=0;i<space.adj.size();i++) {
				content[i].read(input);
			}
			return;
		}

		void protein::write(FILE * output) {
			int i;
			space.write(output);
			for(i=0;i<content.size();i++) {
				content[i].write(output);
			}			
			return;
		}

		void protein::add_atom(atom A) {
			content.push_back(A);
			space.add_node();
			return;
		}

		void protein::link() { // rough version
			int i,j; float d;
			for(i=0; i<space.adj.size(); i++) {
				for(j=i+1; j<space.adj.size(); j++) {
					d=distance(content[i],content[j]);
					if((d <= 3.2) && ( d>=2) ){
						space.add_edge(i,j);
					}
				}
			}
			return;
		}

	};



#endif

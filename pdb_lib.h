#ifndef __PDB_LIB__ 
#define __PDB_LIB__ 1

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

typedef struct atom {
	int[3] coord;
	int serial;
	int chainId;
	} atom;

typedef struct protein {
	graph space;
	atom * content;
	int size;

	} protein;

typedef 



#endif

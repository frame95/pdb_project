#ifndef __VECTOR_LIB__ 
#define __VECTOR_LIB__ 1

#include <stdio.h>
#include <stdlib.h>

typedef struct vector {
	int * in;
	int size;
	int full;
	} vector;

vector vector_init() {
	vector V;
	V.size = 1;
	V.full=0;
	V.in=(int*)malloc(sizeof(int));
	}

void vector_add( int k) {
	int i;
	if(2*(V.full +1)<V.size) {
		V[V.full++] = k;
	} else {
		int * temp;
		temp = (int*)malloc(2*V.size*sizeof(int));
		for(i=0;i<V.full;i++) {
			temp[i] = V.in[i];
		}
		temp[V.full++] = k;
		V.in = temp;
	}
	return;
}

void vector_print(FILE * out) {
	int i;
	for(i=0;i<V.full;i++) {
		fprintf(out,"%d\n", V[i]);
	}
	return;
}

typedef struct dbl_vector {
	int * vector;
	int size;
	int full;
	} dbl_vector;

void vector_add( vector V) { // CHANGE !!
	int i;
	if(2*(V.full +1)<V.size) {
		V[V.full++] = k;
	} else {
		int * temp;
		temp = (int*)malloc(2*V.size*sizeof(int));
		for(i=0;i<V.full;i++) {
			temp[i] = V.in[i];
		}
		temp[V.full++] = k;
		V.in = temp;
	}
	return;
}


#endif

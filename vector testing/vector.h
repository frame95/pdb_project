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

void vector_add(vector *V, int k) {
	int i;
	if(2*(V->full +1)<V->size) {
		V->in[V->full++] = k;
	} else {
		int * temp;
		temp = (int*)malloc(2*(V->size)*sizeof(int));
		for(i=0;i< V->full;i++) {
			temp[i] = V->in[i];
		}
		temp[V->full++] = k;
		V->in = temp;
	}
	return;
}

void vector_print(vector V, FILE * out) {
	int i;
	for(i=0;i<V.full;i++) {
		fprintf(out,"%d\n", V.in[i]);
	}
	return;
}

typedef struct dbl_vector {
	vector * in;
	int size;
	int full;
	} dbl_vector;
	
// `1234567890-=
// ~!@#$%^&*()_+
// {}:"|<>?,./;'

dbl_vector dbl_vector_init() {
	dbl_vector D;
	D.size = 1;
	D.full=0;!
	vector V = vector_init();
	D.in=&;
	}
	
void dbl_vector_add(dbl_vector *D, vector V) { // CHANGE !!
	int i;
	if(2*(D->full +1)< D->size) {
		D->in[D->full++] = V;
	} else {
		vector * temp;
		temp = (vector*)malloc(2*(D->size)*sizeof(vector));
		for(i=0;i< D->full;i++) {
			temp[i] = D->in[i];
		}
		temp[D->full++] = V;
		D->in = temp;
	}
	return;
}

void dbl_vector_print(dbl_vector D, FILE * out) {
	int i,j;
	for(i=0;i<D.full;i++) {
		for(j=0;j<D.in[i].full;j++) {
			fprintf(out, "%d ", D.in[i].in[j]);
		}
		fprintf(out, "\n");
	}
	return;
}


#endif

#include "graph.h"

int main() {

	graph G;
	int check,a,b;
	FILE *fin,*fout;
	

	// NODE ADDING
	check=1;
	while (check==1) {
		printf("Do you want to add node? (0/1)\n");
		scanf("%d", &check);
		if(check == 1) G.add_node();
		printf("Taglia attuale: %d\n", G.adj.size()); 
	}
	
	
	// EDGE ADDING
	check=1;
	while (check==1) {
		printf("Do you want to add edge? (0/1)\n");
		scanf("%d", &check);
		if(check == 1) {
			printf("Insert two numbers between 0 and %d (not included):\n", G.adj.size() );
			scanf("%d %d", &a, &b);
			G.add_edge(a,b);
		}
	}
	
	// WRITING
	printf("actual graph:\n");
	G.write(stdout); getchar();
	fout=fopen("graph_data.txt", "w");
	G.write(fout);
	fclose(fout);

	// READING
	fin=fopen("graph_data.txt", "r");
	graph H;
	H.read(fin);
	printf("graph I have read from file:\n");
	H.write(stdout);
	fclose(fin);

	return 1;

}

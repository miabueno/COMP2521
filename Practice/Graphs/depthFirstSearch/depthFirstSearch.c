
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

// Putting this here bc they should be testing us on DFS
// not how to access hidden Graph ADTs smh
struct graph {
	int nV;
	bool **edges;
};

// Function Declaration
void DFS(Graph g, int *visited, int nV, int v);


void depthFirstSearch(Graph g, int src) {
	
	int *visited = calloc(g->nV, sizeof(int));
	
	DFS(g, visited, g->nV, src);
	
	free (visited);
}

void DFS(Graph g, int *visited, int nV, int v) {
    
    printf("%d ", v);
    visited[v] = 1;
    
    for (int w = 0; w < nV; w++) {
        if (!visited[w] && g->edges[v][w] == true) DFS(g, visited, nV, w);
    }
    
}

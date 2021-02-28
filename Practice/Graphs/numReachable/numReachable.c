
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

struct graph {
    int nV;
    bool **edges;
};

int DFS(Graph g, int *visited, int v);

int numReachable(Graph g, int src) {
	
	int *visited = calloc(g->nV, sizeof(int));
	for (int i = 0; i < g->nV; i++) visited[i] = -1;
	
	visited[src] = src;
	
	int numReachable = DFS(g, visited, src);

	free (visited);
	
	return 1 + numReachable;
}

int DFS(Graph g, int *visited, int v) {

    int count = 0;

    for (Vertex w = 0; w < g->nV; w++) {
        if (visited[w] == -1 && g->edges[v][w] == true) {
            visited[w] = v;
            count += 1 + DFS(g, visited, w);
        } 
    }
    
    return count;
    
}

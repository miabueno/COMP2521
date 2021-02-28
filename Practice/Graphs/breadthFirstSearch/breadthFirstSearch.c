/*
    BFS helpful for finding the shortest path on an unweighted graph
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Graph.h"
#include "Queue.h"

struct graph {
	int nV;
	bool **edges;
};

void breadthFirstSearch(Graph g, int src) {
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	
	int *visited = calloc(g->nV, sizeof(int));
	for (int i = 0; i < g->nV; i++) visited[i] = -1;
	
	visited[src] = src;
	
	while(!QueueIsEmpty(q)) {
	    
	    int v = QueueDequeue(q);
	    printf("%d ", v); 
	    
	    for (Vertex w = 0; w < g->nV; w++) {
	        if(visited[w] == -1 && g->edges[v][w] == true) {
	            visited[w] = v;
	            QueueEnqueue(q, w);
	        }
	    }    
	}
	
	free(visited);
	QueueFree(q);
}


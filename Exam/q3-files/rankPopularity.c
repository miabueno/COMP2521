// rankPopularity.c ... implementation of rankPopularity function

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void DFS(Graph g, int *reachable, Vertex src);
double popRankCalc(Graph g, Vertex v);
double inDegree (Graph g, Vertex w);
double outDegree (Graph g, Vertex v);

/* 
    You will submit only this one file.

    Implement the function "rankPopularity" below. Read the exam paper for a
    detailed specification and description of your task.  

    - DO NOT modify the code in any other files. 
    - You can add static helper functions to this file.  
    - DO NOT add a "main" function to this file. 
*/

void rankPopularity(Graph g, int src, double *mnV) {
	
	int *reachable = calloc(g->nV, sizeof(int));
	for (int i = 0; i < g->nV; i++) reachable[i] = -1;
	
	DFS(g, reachable, src);

	for (int j = 0; j < g->nV; j++) {
	    if (reachable[j] != -1) mnV[j] = popRankCalc(g, j);
	}
	
	free(reachable);
	
}

void DFS(Graph g, int *reachable, Vertex v) {
    
    reachable[v] = v;
    
    for (Vertex w = 0; w < g->nV; w++) {
        if (reachable[w] == -1 && g->edges[v][w] == true) DFS(g, reachable, w);
    }
    
}

double popRankCalc(Graph g, Vertex v) {
    return inDegree(g, v) / outDegree(g, v);
}


double inDegree (Graph g, Vertex w) {
    
    double count = 0;
    for (Vertex v = 0; v < g->nV; v++) {
        if (g->edges[v][w] == 1) count++;
    }
    
    return count;
    
}

double outDegree (Graph g, Vertex v) {
    
    double count = 0;
    for (Vertex w = 0; w < g->nV; w++) {
        if (g->edges[v][w] == 1) count++;
    }
    
    return ((count == 0) ? 0.5 : count);
}

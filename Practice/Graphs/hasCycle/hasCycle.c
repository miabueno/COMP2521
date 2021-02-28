

#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

struct graph {
    int nV;
    bool **edges;
};

bool hasCycle(Graph g) {
	
	for (Vertex v = 0; v < g->nV; v++) if (dfsCycleCheck(g, v)) return true;
	
	return false;
}

bool dfsCycleCheck (Graph g, Vertex src) {
    
    Stack new = StackNew();
    StackPush(new, src);
    
    int *visited = calloc(g->nV, sizeof(int));
    for (Vertex i = 0; i < g->nV; i++) visited[i] = -1;
    
    // Not Visited: -1, On Stack: 0, Visited = 1
    visited[src] = 0; 
    
    while (!StackIsEmpty(new)) {
    
        Vertex v = StackPeek(new);
        
        for (Vertex w = 0; w < g->nV; w++) {
            if (visited[w] == 0 && g->edges[v][w] == true) {
                free(visited);
                free(new);
                return true;
            }
            else if (visited[w] == -1 && g->edges[v][w] == true) {
                visited[w] = 0;
                StackPush(new, w);
            }
            else {
                visited[v] = 1;
                // pop stack
            }
        }
    }
    
    free(visited);
    free(new);
    return false;
}


hasCycle(G):
|  Input  graph G
|  Output true if G has a cycle, false otherwise
|
|  choose any vertex v∈G
|  return dfsCycleCheck(G,v)

dfsCycleCheck(G,v):
|  mark v as visited
|  for each (v,w)∈edges(G) do
|  |  if w has been visited then   // found cycle
|  |     return true
|  |  else if dfsCycleCheck(G,w) then
|  |     return true
|  end for
|  return false      




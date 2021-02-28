
#include <stdlib.h>

#include "tree.h"

int numNodes(Tree t);

bool TreeIsPerfectlyBalanced(Tree t) {
	if (t == NULL) return true;
	
	int heightL = numNodes(t->left);
	int heightR = numNodes(t->right);
	
	if (abs(heightL - heightR) <= 1 
	    && TreeIsPerfectlyBalanced(t->left)
	    && TreeIsPerfectlyBalanced(t->right)) {
	    return true;
	}
	else return false;
}

int numNodes(Tree t) {
    if (t == NULL) return 0;
    return 1 + numNodes(t->left) + numNodes(t->right);
}

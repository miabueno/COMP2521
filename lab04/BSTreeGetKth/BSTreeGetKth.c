
#include <stdlib.h>

#include "BSTree.h"

int BSTreeNumNodes (BSTree t);

int BSTreeGetKth(BSTree t, int k) {
	// TODO
	
	if (t == NULL) {
	    return 69;
	}
	
	int numLeftNodes = BSTreeNumNodes(t->left); 
    
    if (k < numLeftNodes) return BSTreeGetKth(t->left, k);
	else if (k == numLeftNodes) {
	    return t->value;
	}
	else {
	    k--;
	    return BSTreeGetKth(t->right, k-numLeftNodes);
	}
	
}


int BSTreeNumNodes (BSTree t)
{
	if (t == NULL)
		return 0;
	else
		return 1 + BSTreeNumNodes (t->left) + BSTreeNumNodes (t->right);
}

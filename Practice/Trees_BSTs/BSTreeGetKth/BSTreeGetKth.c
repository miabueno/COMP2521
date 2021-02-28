
#include <stdlib.h>

#include "BSTree.h"

int BSTreeNumNodes(BSTree t);

int BSTreeGetKth(BSTree t, int k) {
	
	if (t == NULL) return -1;
	
	int leftCount = BSTreeNumNodes(t->left);
	
	if (k == leftCount) return t->value;
	else if (k < leftCount) return BSTreeGetKth(t->left,k);
	
	k--;
	k = k-leftCount;
	return BSTreeGetKth(t->right, k);
	
}

int BSTreeNumNodes(BSTree t) {
    if (t == NULL) return 0;
    return 1 + BSTreeNumNodes(t->left) + BSTreeNumNodes(t->right);
}


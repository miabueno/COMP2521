
#include <stdlib.h>

#include "BSTree.h"

int BSTreeNodeDepth(BSTree t, int key) {
	
	if (t == NULL) return -1;
	
	if (t->value == key) return 0; // found
    
    else if (t->value > key) {
        
        int nd_left = BSTreeNodeDepth(t->left, key);
        if (nd_left == -1) return -1;
        return 1 + nd_left;
    }
    else {
        
        int nd_right = BSTreeNodeDepth(t->right, key);
        if (nd_right == -1) return -1;
        return 1 + nd_right;
    }
}


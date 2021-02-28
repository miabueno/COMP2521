
#include <stdlib.h>

#include "tree.h"

int countNodes (Tree t);

bool TreeIsPerfectlyBalanced(Tree t) {
	if (t == NULL) return true;
	
	int leftHeight = countNodes(t->left);
	int rightHeight = countNodes(t->right);
	
	if (abs(leftHeight - rightHeight) > 1) return false;
    
    return (TreeIsPerfectlyBalanced(t->left) && TreeIsPerfectlyBalanced(t->right));
}

int countNodes (Tree t) {
    if (t == NULL) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}


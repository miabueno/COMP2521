
#include <stdio.h>

#include "BSTree.h"

void showBSTreeNode(BSTree t);

void BSTreePostfix(BSTree t) {
	if (t == NULL) return;
	
	BSTreePostfix(t->left);
	BSTreePostfix(t->right);
	showBSTreeNode(t);
}

void showBSTreeNode(BSTree t) {
    if (t == NULL) return;
    printf("%d ", t->value);
}


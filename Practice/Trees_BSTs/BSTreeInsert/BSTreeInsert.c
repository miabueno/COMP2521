
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree newBSTNode(int v);

BSTree BSTreeInsert(BSTree t, int val) {
	
	if (t == NULL) return newBSTNode(val);
	
	if (val < t->value) {
	    t->left = BSTreeInsert(t->left, val);
	}    
    else if (val > t->value) {
        t->right = BSTreeInsert(t->right, val);
	}
	
	return t;
}

BSTree newBSTNode(int v) {
	
	BSTree t = malloc(sizeof(*t));
	
	if (t == NULL) {
		fprintf(stderr, "Insufficient memory!\n");
		exit(EXIT_FAILURE);
	}
	
	t->value = v;
	t->left = NULL;
	t->right = NULL;
	
	return t;
}

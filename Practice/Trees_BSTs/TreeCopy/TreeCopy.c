
#include "tree.h"

Tree newNode(int v);

Tree TreeCopy(Tree t, int depth) {
	if (depth < 0 || t == NULL) return NULL;
	
	if (depth == 0) return newNode(t->value);
	
	Tree newTree = newNode(t->value);
	newTree->left = TreeCopy(t->left, depth-1);
	newTree->right = TreeCopy(t->right, depth-1);
	
	return newTree;
}

Tree newNode(int v) {
    Tree new = malloc(sizeof(*new));
    
    if (new == NULL) {
        fprintf(stderr, "insufficient memory\n");
        exit(EXIT_FAILURE);
    }
    
    new->value = v;
    new->left = NULL;
    new->right = NULL;
    
    return new;
}

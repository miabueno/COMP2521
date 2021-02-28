
#include "tree.h"

struct node* newNode(int k);

struct node* newNode(int k) {
    Tree new = malloc(sizeof(struct node));
    new->value = k;
    new->left = new->right = NULL;
    return new;
}

Tree TreeCopy(Tree t, int depth) {
	if (depth < 0 || t == NULL) return NULL;
	else if (depth == 0) return newNode(t->value);
	
	Tree newTree = newNode(t->value);
	newTree->left = TreeCopy(t->left, depth - 1);
	newTree->right = TreeCopy(t->right, depth - 1);
	
	return newTree;
}


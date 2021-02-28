
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree DeleteNode(BSTree t);

BSTree joinTrees(BSTree t1, BSTree t2);

BSTree BSTreeTrim(BSTree t, int lower, int upper) {
	
	if (t == NULL) return NULL;
    
    t->left = BSTreeTrim(t->left, lower, upper);
	t->right = BSTreeTrim(t->right, lower, upper);
	
	
	if (lower <= t->value && t->value <= upper) return (DeleteNode(t));
	
	if (t->value < lower) {
	    t->left = BSTreeTrim(t->left, lower, upper);
	} 
	
	if (t->value > upper) {
	    t->right = BSTreeTrim(t->right, lower, upper);
	}

	
	return t;
	
}

BSTree DeleteNode(BSTree t) {
    
    BSTree new;
    
    // Zero Subtrees
    if (t->left == NULL && t->right == NULL) new = NULL;
    // One Subtree - right
    else if (t->left == NULL) new = (t->right); 
    // One Subtree - left
    else if (t->right == NULL) new = (t->left);
    // Two Subtrees 
    else new = joinTrees(t->left, t->right);
    
    free(t);
    return new;

}

// Then removing a node with two subtrees,
// This joins the two trees
BSTree joinTrees(BSTree t1, BSTree t2) {
    
    // if t1 is empty, we only need t2
    if (t1 == NULL) return t2;
    // if t2 is empty, we only need t1
    if (t2 == NULL) return t1;
    
    BSTree parent = NULL;
    BSTree curr = t2;
    
    while (curr->left != NULL) {
        parent = curr;
        curr = curr->left;
    }
    
    if (parent != NULL) {
        parent->left = curr->right;
        curr->right = t2;
    }
    
    curr->left = t1;
    
    return curr;
}



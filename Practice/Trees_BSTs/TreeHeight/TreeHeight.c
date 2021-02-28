
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t) {
    
    if (t == NULL) return -1;
    
    int h_left = 1 + TreeHeight(t->left);
    int h_right = 1 + TreeHeight(t->right);
    
    if (h_left > h_right) return h_left;
    
    return h_right;
}


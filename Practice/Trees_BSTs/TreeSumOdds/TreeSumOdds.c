
#include <stdlib.h>

#include "tree.h"

int TreeSumOdds(Tree t) {
	
	int sum = 0;
	if (t == NULL) return sum;
	
	if (t->value % 2 != 0) sum = t->value;
	
	return sum + TreeSumOdds(t->left) + TreeSumOdds(t->right);
	
}



#include "list.h"

bool listIsOrdered(List l) {
	
	if (l->head == NULL) return true;
	
	Node curr = l->head->next;
	
	while (curr->next != NULL) {
	    if (l->head->value < curr->value && curr->value > curr->next->value) return false;
	    if (curr->value < l->head->value && curr->value < curr->next->value) return false;
	    curr = curr->next;
	}
	
	return true;
}


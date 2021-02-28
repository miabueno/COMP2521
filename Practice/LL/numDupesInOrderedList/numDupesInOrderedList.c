
#include "list.h"

int numDupesInOrderedList(List l) {
	
	int dupCount = 0;
	if (l == NULL) return dupCount;
	
	Node prev = l->head;
	
	for (Node curr = l->head->next; curr != NULL; curr = curr->next) {
	    
	    if (prev->value == curr->value) dupCount++;
	    else prev = curr;
	  
	}
	
	return dupCount;
}


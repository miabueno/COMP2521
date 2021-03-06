
#include "list.h"
#include <assert.h>

void addToList(List l, int val);

List listSetDifference(List l1, List l2) {

	List lSD = newList();
	
	int matches;
	Node l1_curr = l1->head;
	while (l1_curr != NULL) {
	    matches = 0;
		Node l2_curr = l2->head;
		while (l2_curr != NULL) {
		    if (l1_curr->value == l2_curr->value) {
		        matches = 1;
		        break;
		    }
		    l2_curr = l2_curr->next;
		}

		if (matches == 0) addToList(lSD, l1_curr->value);
		
		l1_curr = l1_curr->next;
	}
	
	return lSD;
}

void addToList(List l, int val) {
    assert (l != NULL);
    
    Node new = newNode(val);
    
    new->next = l->head;
    l->head = new;

    
}





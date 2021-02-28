
#include <assert.h>

#include "list.h"

void insertInOrder (List l, int v);

List listSetIntersection(List s1, List s2) {
	
	List new = newList();
	
	for (Node curr1 = s1->head; curr1 != NULL; curr1 = curr1->next) {
	    
	    for (Node curr2 = s2->head; curr2 != NULL; curr2 = curr2->next) {
	        
	        if (curr1->value == curr2->value) insertInOrder(new, curr1->value);
	        
	    }    
	    
	}
	
	return new;
}

void insertInOrder (List l, int v) {
    
    assert(l != NULL);
    
    //if (alreadyExists(l, v)) return;
    
    Node n = newNode(v);
    
    // Inserting first node
    if (l->head == NULL) {
        l->head = n;
    }
    // Inserting before first node
    else if (n->value < l->head->value) {
        n->next = l->head;
        l->head = n;
    }
    else {
        Node curr = l->head->next;
        Node prev = l->head;
    
        while (prev != NULL) {
            
            // Inserting after the last node
            if (curr == NULL && prev->value < n->value) {
                prev->next = n;
                n->next = NULL;
                break;
            }
            
            // Inserting in the middle before last 
            if (n->value > prev->value && n->value < curr->value) {
                prev->next = n;
                n->next = curr;
                break;
            }
            
            curr = curr->next;
            prev = prev->next;
        }
    }
}

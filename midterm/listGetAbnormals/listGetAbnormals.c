
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List insertLLNode(List l, int n);

List listGetAbnormals(List l, int threshold) {
	
	Node curr = l->first;
	List abnormals = newList();
    
    if (l->size == 1) {
        return abnormals;
	}
    
    if (curr == l->first) curr = curr->next;
    curr->prev = l->first;	
    
    int x;
    int y;
    
	while (curr != NULL) {
	    
	    if (curr == l->last) break;
	    
	    x = abs(curr->value - curr->prev->value);
	    y = abs(curr->next->value - curr->value);
	    
	    if (x >= threshold && y >= threshold) {
	        abnormals = insertLLNode(abnormals, curr->value);
	        
	    }
	    
	    curr = curr->next;
	}
	
	
	return abnormals;
}


List insertLLNode(List l, int n) {

    Node new = newNode(n);
    
    Node curr = l->first;
    
    if (l->first == NULL) {
        l->first = new;
        l->last = new;
        l->size++;
    }
    else {
        // goes to the last node and inserts
        curr = l->last;
    
        curr->next = new;
        new->prev = curr;
        l->last = new;
        
        l->size++;
    }
    
    return l;
    
}

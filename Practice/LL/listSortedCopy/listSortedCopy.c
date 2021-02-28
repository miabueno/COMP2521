
#include <stdio.h>
#include <assert.h>

#include "list.h"

void insertLLAfter (List l, int v);


int main (int argc, char **argv) {
    
    List new = newList();
    
    for (int i = 1; i < argc; i++) {
        insertLLAfter(new, atoi(argv[i]));
    }
    
    printf("\nCurrent list is: \n");
    printList(new);
    
    List sorted = listSortedCopy(new);
    
    printf("\nSorted list is: \n");
    printList(sorted);
    
    printf("\n");
    
    return 0;
}

void insertLLAfter (List l, int v) {
    
    assert (l != NULL);
	
	Node new = newNode(v);
	
	// if list items are empty
	if (l->head == NULL) {
	    l->head = new;
	}
	else {
	// inserting an item after the last item
	    for (Node curr = l->head; curr != NULL; curr = curr->next) {
	        if (curr->next == NULL) {
	            curr->next = new;
	            new->next = NULL;
	            break;
	        }
	    }
	}    
}



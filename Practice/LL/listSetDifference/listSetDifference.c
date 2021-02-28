
#include <stdbool.h>

#include "list.h"

void insertAnyOrder (List l, int v);

List listSetDifference(List l1, List l2) {
    
    List new = newList();
    
    for (Node p1 = l1->head; p1 != NULL; p1 = p1->next) {
        
        bool exists = false;
        
        for (Node p2 = l2->head; p2 != NULL; p2 = p2->next) {
        
            if (p1->value == p2->value) {
                exists = true;
                break;
            }
            
        }
        
        if (exists == false) insertAnyOrder(new, p1->value);
    }
    
    return new;

}

/*
    INSERTS TO LIST FROM HEAD. MAIN FUNCTION SORTS IT ANYWAYS
*/
void insertAnyOrder (List l, int v) {
    
    Node n = newNode(v);
    
    if (l->head == NULL) l->head = n;
    else {
        n->next = l->head;
        l->head = n;
    }
    
}


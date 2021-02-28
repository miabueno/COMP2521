
#include "list.h"

void listReverse(List l) {

    if (l->head == NULL) return;

    Node first = l->head;
    
    if (l->head->next == NULL) return;
    
    Node rest = l->head->next;

    first->next = NULL;
    
    while (rest != NULL) {
        
        Node tmp = rest;
        rest = rest->next;
        
        tmp->next = first;
        first = tmp;
    }
    
    l->head = first;

}


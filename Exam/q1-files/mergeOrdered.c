// mergeOrdered.c ... implementation of mergeOrdered function

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void insertLL(List l, int v);

/* 
    You will submit only this one file.

    Implement the function "mergeOrdered" below. Read the exam paper for a
    detailed specification and description of your task.  

    - DO NOT modify the code in any other files. 
    - You can add static helper functions to this file.  
    - DO NOT add a "main" function to this file. 
*/

List mergeOrdered(List list1, List list2) {

    List merged = newList();

    Node *l1 = list1->first;
    Node *l2 = list2->first;
    
    while (l1 != NULL || l2 != NULL) {

        if (l1 == NULL) {
            insertLL(merged, l2->value);
            l2 = l2->next;
            continue;
        }
        
        if (l2 == NULL) {
            insertLL(merged, l1->value);;
            l1 = l1->next;
            continue;
        }

        if (l1->value <= l2->value) {
            insertLL(merged, l1->value);
            l1 = l1->next;
        }
        else {
            insertLL(merged, l2->value);
            l2 = l2->next;
        }    
        
    }

    return merged;
}

void insertLL(List l, int v) {
    
    Node *new = newNode(v);
    
    if (l->first == NULL) {
        l->first = new;
        l->last = new;
    } 
    else if (l->first == l->last) {
        l->first->next = new;
        l->last = new;
    }
    else {
        l->last->next = new;
        l->last = new;
    }
    
}

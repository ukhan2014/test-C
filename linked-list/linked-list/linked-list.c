//
//  linked-list.c
//  linked-list
//
//  Created by Cabana on 5/24/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include "linked-list.h"


/*
 Print elements of a linked list on console
 head pointer input could be NULL as well for empty list
 */
void Print(Node *head)
{
    if(!head) {
        return;
    }
    else {
        struct Node * tempPtr = head;
        while(tempPtr) {
            printf("%d\n", tempPtr->data);
            tempPtr = tempPtr->next;
        }
    }
}
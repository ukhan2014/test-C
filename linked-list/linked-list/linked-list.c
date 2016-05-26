//
//  linked-list.c
//  linked-list
//
//  Created by Cabana on 5/24/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include "linked-list.h"
#include <stdlib.h>


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

/*
 Insert Node at the end of a linked list
 head pointer input could be NULL as well for empty list
 Return the head of the updated list
 */
Node * Insert_at_end(Node *head,int data)
{
    Node * tempPtr = head;
    if(tempPtr) {
        while(tempPtr->next) {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = (Node *) malloc(sizeof(Node));
        tempPtr->next->data = data;
    }
    else {
        head = (Node *) malloc(sizeof(Node));
        head->data = data;
    }
    return head;
}

/*
 Insert Node at the begining of a linked list
 Initially head pointer argument could be NULL for empty list
 return back the pointer to the head of the linked list
 
 For example:
 1. We have an empty list, on inserting 1, 1 becomes new head.
 2. We have a list with 1 as head, on inserting 2, 2 becomes 
    the new head.
 */
Node * Insert_at_beginning(Node * head, int data)
{
    Node * temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

/*
 Insert Node at a given position in a linked list
 head can be NULL
 First element in the linked list is at position 0
 */
Node* InsertNth(Node *head, int data, int position)
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    if(!head) {
        printf("no head\n");
        head = newNode;
        head->next = NULL;
    }
    else {
        Node * temp = NULL;
        if(position == 0) {
            printf("pos is 0\n");
            temp = head;
            printf("temp->data = %d\n", temp->data);
            head = newNode;
            head->next = temp;
            
            head->next->next = NULL;
            printf("inserted at position 0\n");
        }
        else {
            printf("pos=%d\n", position);
            while((position > 1)) {
                printf("hi\n");
                temp = temp->next;
                position--;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        
    }
    return head;
}

/*
 Delete Node at a given position in a linked list
 */
Node* Delete(Node *head, int position)
{
    int traverse = 0;
    Node * tmp = head;
    Node * toDelete = NULL;
    if(!head) {
        //printf("no head");
    }
    else if(position == 0) {
        head = head->next;
        free(tmp);
    }
    else {
        while(traverse < (position - 1)) {
            //printf("traversing\n");
            tmp = tmp->next;
            traverse++;
        }
        toDelete = tmp->next;
        tmp->next = tmp->next->next;
        free(toDelete);
    }
    
    return head;
}

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

/*
 Print elements of a linked list in reverse order as standard output
 head pointer could be NULL as well for empty list
 */
void ReversePrint(Node *head)
{
    if(!head) {
        return;
    }
    else {
        ReversePrint(head->next);
    }
    printf("%d\n", head->data);
    return;
}

/*
 Reverse a linked list and return pointer to the head
 The input list will have at least one element
 */
Node* Reverse(Node *head)
{
    Node * tmp1 = NULL;
    Node * tmp2 = NULL;
    if(!head) {
        return NULL;
    }
    else {
        if(head->next) {
            tmp1 = head->next;
            tmp2 = head->next->next;
        }
        else {
            return head;
        }
    }
    head->next = NULL;
    while(tmp1 && tmp2) {
        tmp1->next = head;
        head = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    tmp1->next = head;
    
    return tmp1;
}

/*
 Reverse a linked list and return pointer to the head
 Recursive implementation
 */
Node* ReverseRecursive(Node *head)
{
    Node * temp;
    Node * newHead;
    if(!head || !head->next) {
        return head;
    }
    temp = head->next;
    head->next = NULL;
    newHead = Reverse(temp);
    temp->next = head;
    return newHead;
}

/*
 Compare two linked lists A and B
 Return 1 if they are identical and 0 if they are not.
 */
int CompareLists(Node *headA, Node* headB)
{
    while(headA && headB) {
        if(headA->data != headB->data)
            return 0;
        headA = headA->next;
        headB = headB->next;
    }
    if(!headA && !headB)
        return 1;
    return 0;
}

/*
 Merge two sorted lists A and B as one linked list
 */
Node* MergeLists(Node *headA, Node* headB)
{
    if(!headA) {
        return headB;
    }
    else if(!headB) {
        return headA;
    }
    Node * returnList;
    Node * otherList;
    if(headA->data <= headB->data) {
        returnList = headA;
        otherList = headB;
    }
    else {
        returnList = headB;
        otherList = headA;
    }
    returnList->next = MergeLists(returnList->next, otherList);
    
    return returnList;
}

/*
 Get Nth element from the end in a linked list of integers
 Number of elements in the list will always be greater than N.
 */
int GetNode(Node *head,int positionFromTail)
{
    Node * tmp1 = head;
    Node * tmp2 = head;
    while(positionFromTail) {
        tmp2 = tmp2->next;
        positionFromTail--;
    }
    while(tmp2->next) {
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return tmp1->data;
}

/*
 Remove all duplicate elements from a sorted linked list
 */
Node* RemoveDuplicates(Node *head)
{
    Node * tmp1 = head;
    Node * tmp2;
    while(tmp1->next) {
        if(tmp1->data == tmp1->next->data) {
            tmp2 = tmp1->next;
            tmp1->next = tmp1->next->next;
            free(tmp2);
        }
        else {
            tmp1 = tmp1->next;
        }
    }
    return head;
}

/*
 Detect a cycle in a linked list. Note that the head
 pointer may be 'NULL' if the list is empty. Method
 assumes that list is limited to 100 nodes.
 */

int has_cycle(Node* head) {
    Node * temp1 = head;
    Node * temp2 = head;
    int count;
    if(!head) {
        return 0;
    }
    while(temp1) {
        count = 0;
        while((temp2->next) && (count <= 100)) {
            count++;
            temp2 = temp2->next;
            if(temp1 == temp2) {
                return 1;
            }
        }
        temp1 = temp1->next;
    }
    return 0;
}

/*
 Find merge point of two linked lists
 Returns the data in the merge node
 */
int FindMergeNode(Node *headA, Node *headB)
{
    Node * temp1 = headA->next;
    Node * temp2 = headB->next;
    
    while(temp1) {
        while(temp2) {
            if(temp1 == temp2) {
                return temp1->data;
            }
            temp2 = temp2->next;
        }
        temp2 = headB->next;
        temp1 = temp1->next;
    }
    return -1; // couldnt find merge
}


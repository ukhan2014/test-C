#include <stdio.h>

typedef struct node {
    int data;
    node * next;
} node_t;

void printList (node_t * list){
    node_t * currentNode = list; //create currentNode pointer and give it address of the list
    do{
        printf ("%d\n", currentNode->data);
        currentNode = currentNode->next; //go to next node in list
    }while(currentNode != NULL);
}

// create and return a new node
// arg1: data value for the new node
node_t createNode (int data) {
    node_t newNode; //declare a new node
    newNode.data = data;
    return newNode; //return address of the new node
}

//insert a new node containing data at spot n in the list if list starts at n=1
void insertNode(node_t * list, int data, int n) {
    int temp = n;
    int counter = 1;
    node_t newNode;
    node_t * ptr = list;
    newNode.data = data;
    //traverse to spot before the spot where we are going to plug in the new node
    while(counter != temp-1){
        ptr = ptr->next;
        counter++;
    }
    //detach current node and adjust pointers
    newNode.next = ptr->next;
    ptr->next =&newNode;
    
}

//search list for first occurrence of data. if found, return the node number that it was found at; otherwise return 0;
int searchList (node_t * list, int data){
    int temp = data;
    int nodeLocation = 1;
    node_t * nodePtr = list;
    bool found = false;
    while (nodePtr->next != NULL) {
        if(nodePtr->data == temp){
            found =true;
            break;
        }
        else {
            nodePtr = nodePtr->next;
        }
    }
    
    if(found) {
        return nodeLocation;
    }
    else {
        return 0;
    }
}

//returns num of nodes in list
int listSize (node_t * list){
    //declare ptr to node, set it to start of list
    node_t * whereAmI = list;
    int count = 1; //start counter at 1 since we are at first node
    while (whereAmI->next != NULL){
        whereAmI = whereAmI->next; //go to next node
        count++; //adjust size variable
    }
    
    //if we are out here that means we have reached end of the list
    return count; //this is our list size
    
}

//deleted the node at location num where num =1 is start node of list
void deleteNode(node_t * list, int num) {
    node_t * listPtr = list;
    int counter = 1; //since we are at node 1
   //traverse until next node is the node to be deleted
    while (counter != (num-1)) {
        listPtr = listPtr->next;
        counter++;
    }
    //make next pointer point to the next-next node
    listPtr->next = listPtr->next->next;
    
}
int main () {
    node_t start, end, middle, node4;
    start.data = 1;
    end.data =2;
    middle.data = 500;
    end.next = NULL; //make end of list point to null    
    start.next = &end;
    
    //printf ("start.next data is %d\n", start.next->data);
    
    printList (&start );
    node4 = createNode (4);
    
    //printf ("Let us add a node in the middle\n");
    
    //make start point to middle node
    start.next = &middle;
    //make middle node point to end node
    middle.next = &node4;
    node4.next = &end;
    
    printf ("added two new nodes \n");
    
    printList (&start);
    printf ("list size is %d\n", listSize (&start));
    printf ("about to delete node 3\n");
    deleteNode (&start,3);
    printList (&start);
    
    return 0 ;
    
}

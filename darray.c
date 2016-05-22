#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INITIAL_CAPACITY (100)

// Define a vector type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // array of integers we're storing
} Vector;

typedef struct listNode {
    Vector * seq;
    struct listNode * next;
} listNode_t;

void vector_init(Vector *vector) {
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = (int *)malloc(sizeof(Vector));
}

void vector_double_capacity_if_full(Vector **vector){
    if((*vector)->size >= (*vector)->capacity) {
        printf("capacity before is %d\n", (*vector)->capacity);
        (*vector)->capacity *= 2;
        printf("capacity after multiply is %d\n", (*vector)->capacity);
        (*vector)->data = (int *)realloc((*vector)->data, sizeof(int)*((*vector)->capacity));
    }
}

void vector_append(Vector *vector, int value){
    vector_double_capacity_if_full(&vector);
    *((vector->data) + vector->size) = value;
    (vector->size)++;
}

void vector_free(Vector *vector){
    free(vector->data);
}

int main() {
    listNode_t * seqList = NULL;
    listNode_t * listPtr = NULL;
    int lastAns = 0;
    int N, Q, queryType, x, y;
    
    // Get values of N and Q
    //printf("Please eter values of N and Q:\n");
    scanf("%d %d", &N, &Q);
    //printf("N=%d  Q=%d\n",N,Q);
    int loopCountdown = Q;  // Loop Q times
    //N=2; Q=5;
    
    int i;
    seqList = (listNode_t *)malloc(sizeof(listNode_t));
    listPtr = seqList;
    for(i=0; i<N-1; i++) {
        listPtr->next = (listNode_t *)malloc(sizeof(listNode_t));
        listPtr = listPtr->next;
    }
    
    while(loopCountdown--) {
        //printf("Please enter queryType, x and y like: qt x y\n");
        scanf("%d %d %d", &queryType, &x, &y);
        //printf("queryType=%d  x=%d  y=%d\n", queryType,x,y);
        //queryType=1; x=0; y=5;
        int index = (x ^ lastAns) % N;
        listPtr = seqList;                          // reset pointer to beginning of seqList
        for(i=0; i<index; i++) {
            listPtr = listPtr->next;                // traverse to index in seqList
        }
        
        if(queryType == 1) {
            // if this sequence is empty
            if(!listPtr->seq) {
                //printf("Creating new sequence\n");
                listPtr->seq = (Vector *) malloc(sizeof(Vector));
                vector_init(listPtr->seq);
                vector_append(listPtr->seq, y);
            }
            else {
                vector_append(listPtr->seq, y);
            }
        }
        else if(queryType == 2) {
            int element = y % (listPtr->seq->size);
            lastAns = *((listPtr->seq->data)+element);
            printf("%d\n", lastAns);
        }
        else {
            break;
        }
    }
    
    // Free all memory allocated to vectors and listNodes
    while(seqList) {
        if(seqList->seq)
            vector_free(seqList->seq);
        listNode_t * temp = seqList;
        seqList = seqList->next;
        free(temp);
    }
    return 0;
}

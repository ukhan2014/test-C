#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INITIAL_CAPACITY (100)

// Define a vector type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // array of integers we're storing
} intVector;

typedef struct {
    int size;
    intVector * seq;    // sequence
} seqVector;

typedef struct listNode {
    intVector * seq;
    struct listNode * next;
} listNode_t;

void vector_init(intVector *vector) {
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = (int *)malloc(sizeof(int) * vector->capacity);
}

void seqVector_init(seqVector * vector, int capacity) {
    int i;
    for(i=0; i<capacity; i++) {
        (vector + i)->size = capacity;
        (vector + i)->seq = (intVector *) malloc(sizeof(intVector));
        vector_init(((vector + i)->seq));
    }
}

void vector_double_capacity_if_full(intVector **vector){
    if((*vector)->size >= (*vector)->capacity) {
        printf("capacity before is %d\n", (*vector)->capacity);
        (*vector)->capacity *= 2;
        printf("capacity after multiply is %d\n", (*vector)->capacity);
        (*vector)->data = (int *)realloc((*vector)->data, sizeof(int)*((*vector)->capacity));
    }
}

void vector_append(intVector *vector, int value){
    vector_double_capacity_if_full(&vector);
    *((vector->data) + vector->size) = value;
    (vector->size)++;
}

void vector_free(intVector *vector){
    free(vector->data);
}

int main() {
    int lastAns = 0;
    int N, Q, queryType, x, y;
    
    // Get values of N and Q
    //printf("Please eter values of N and Q:\n");
    scanf("%d %d", &N, &Q);
    //printf("N=%d  Q=%d\n",N,Q);
    
    seqVector * seqList = (seqVector *) malloc(sizeof(seqVector) * N);
    seqVector_init(seqList, N);
    
    int loopCountdown = Q;  // Loop Q times
    while(loopCountdown--) {
        //printf("Please enter queryType, x and y like: qt x y\n");
        scanf("%d %d %d", &queryType, &x, &y);
        //printf("queryType=%d  x=%d  y=%d\n", queryType,x,y);
        //queryType=1; x=0; y=5;
        int index = (x ^ lastAns) % N;
        
        if(queryType == 1) {
            // if this sequence is empty
            if( !(((seqList+index)->seq)->data) ) {
                //printf("Creating new sequence\n");
                vector_init(((seqList+index)->seq));
                vector_append(((seqList+index)->seq), y);
            }
            else {
                vector_append(((seqList+index)->seq), y);
            }
        }
        else if(queryType == 2) {
            int element = y % (((seqList+index)->seq)->size);
            lastAns = *((((seqList+index)->seq)->data)+element);
            printf("%d\n", lastAns);
        }
        else {
            break;
        }
    }
    
    // Free all memory allocated to vectors and listNodes
    int i;
    for(i=0; i<(seqList->size); i++) {
        if(((seqList+i)->seq))
            vector_free(((seqList+i)->seq));
    }
    free(seqList);
    
    return 0;
}

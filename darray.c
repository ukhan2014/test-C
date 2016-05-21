#include <stdio.h>
#include <stdlib.h>




typedef struct seqNode {
    int data;
    struct seqNode * next;
} seqNode_t;

typedef struct listNode {
    seqNode_t * seq;
    struct listNode * next;
} listNode_t;

seqNode_t * createSeqNode() {
    seqNode_t * seq = (seqNode_t *)malloc(sizeof(seqNode_t));
    seq->data = 0;
    seq->next = NULL;
    return seq;
}

listNode_t * createListNode() {
    listNode_t * list = (listNode_t *)malloc(sizeof(listNode_t));
    list->next = NULL;
    list->seq = NULL;
    return list;
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
        //printf("index=%d   Resetting to beginning of seqList\n",index);
        listPtr = seqList;                          // reset pointer to beginning of seqList
        for(i=0; i<index; i++) {
            listPtr = listPtr->next;                // traverse to index in seqList
        }
        
        if(queryType == 1) {
            // if this sequence is empty
            seqNode_t * tempSeqPtr = NULL;          // temp Ptr to traverse a sequence
            if(!listPtr->seq) {
                //printf("Creating new sequence\n");
                listPtr->seq = createSeqNode();
                listPtr->seq->data = y;
                listPtr->seq->next = NULL;
            }
            else {
                tempSeqPtr = listPtr->seq;
                while(tempSeqPtr->next) {
                    tempSeqPtr = tempSeqPtr->next;
                }
                tempSeqPtr->next = createSeqNode();
                tempSeqPtr = tempSeqPtr->next;
                tempSeqPtr->data = y;
                tempSeqPtr->next = NULL;
            }
        }
        else if(queryType == 2) {
            int size = 0;
            seqNode_t * tempSeqPtr = listPtr->seq;
            // find size of sequence
            while(tempSeqPtr) {
                tempSeqPtr = tempSeqPtr->next;
                size++;
            }
            
            int element = y % size;
            tempSeqPtr = listPtr->seq;
            // go to index element
            int i;
            for(i=0; i<element; i++) {
                tempSeqPtr = tempSeqPtr->next;
            }
            lastAns = tempSeqPtr->data;
            printf("%d\n", lastAns);
        }
        else {
            break;
        }
        
    }
        
    return 0;
}

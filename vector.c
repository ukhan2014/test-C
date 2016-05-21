//
//  vector.c
//  dynamic-array
//
//  Created by Cabana on 5/21/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector) {
    vector->size = 0;
    vector->capacity = VECTOR_INITIAL_CAPACITY;
    vector->data = (int *)malloc(sizeof(Vector));
}

void vector_append(Vector *vector, int value){
    vector_double_capacity_if_full(vector);
    *((vector->data) + vector->size) = value;
    (vector->size)++;
}

int vector_get(Vector *vector, int index) {
    if(index > ((vector->size) - 1)) {
        printf("index is out of bounds of array\n");
        return 0;
    }
    
    return *((vector->data)+(index-1));
}

void vector_set(Vector *vector, int index, int value) {
    while(index >= (vector->size)) {
        vector_append(vector, 0);
    }
    *((vector->data)+index) = value;
}

void vector_double_capacity_if_full(Vector *vector){
    if(vector->size >= vector->capacity) {
        vector->capacity *= 2;
        realloc(vector, sizeof(int)*(vector->capacity));
    }
}

void vector_free(Vector *vector){
    free(vector->data);
}

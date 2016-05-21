//
//  vector.h
//  dynamic-array
//
//  Created by Cabana on 5/21/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#ifndef vector_h
#define vector_h

#include <stdio.h>

// vector.h

#define VECTOR_INITIAL_CAPACITY 100

// Define a vector type
typedef struct {
    int size;      // slots used so far
    int capacity;  // total available slots
    int *data;     // array of integers we're storing
} Vector;

void vector_init(Vector *vector);

void vector_append(Vector *vector, int value);

int vector_get(Vector *vector, int index);

void vector_set(Vector *vector, int index, int value);

void vector_double_capacity_if_full(Vector *vector);

void vector_free(Vector *vector);


#endif /* vector_h */

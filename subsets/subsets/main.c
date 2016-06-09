//
//  main.c
//  subsets
//
//  Created by Cabana on 6/7/16.
//  Copyright © 2016 Cabana. All rights reserved.
//
//  This code takes a set S and target value t.
//  It prints out all subsets in the powerset of
//  set S and outputs a pointer to all subsets
//  of S that add up to the target t.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BIT_0       (0x01)

int main(int argc, const char * argv[]) {
    int * subsets[100];         // array of 100 pointers to int
    int subsets_index = 0;
    int set[] = {1,2,3,4,5};    // the original set
    int target = 5;             // the number subsets should add up to
    
    int set_size = sizeof(set)/sizeof(int);
    int powerset_size = pow(2,set_size);
    
    printf("powerset_size = %d\n", powerset_size);
    printf("set_size = %d\n", set_size);
    int i;
    int j;
    int sum;        // variable to hold sum of subsets
    int ham;        // variable to hold hamming weight (# of set bits)
    int hits = 0;       // how many subsets' sum is the target value t?
    
    for(i = 1; i < powerset_size; i++) {
        sum = 0;
        ham = 0;
        printf("set %d = ", i);
        for(j = 0; j < set_size; j++) {
            if((i >> j)&BIT_0) {
                ham += 1;
                sum += set[j];
                printf("%d ", set[j]);
            }
        }
        
        printf("  ham = %d \n", ham);
        
        if(sum == target) {
            hits++;
            printf("sum found!\n");
            
            // allocate memory (of size = hamming weight of i)
            int * correct_sum_subset = (int *) malloc(sizeof(ham * sizeof(int)));
            
            int new_subset_index = 0;
            // fill correct_sum_subset
            for(j = 0; j < set_size; j++) {
                if((i >> j)&BIT_0) {
                     correct_sum_subset[new_subset_index++] = set[j];
                }
            }
            // assign to next index in our int * array[100]
            subsets[subsets_index++] = correct_sum_subset;
            
        }
    }
    
    printf("Subsets that meet criteria:\n");
    for(i=0; i<hits; i++) {
        for(j=0; j<sizeof(subsets[i]); j++) {
            printf("%d ", subsets[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

//
//  main.c
//  subsets
//
//  Created by Cabana on 6/7/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define BIT_0       (0x01)

int main(int argc, const char * argv[]) {
    
    // insert code here...
    printf("Hello, World!\n");
    
    int set[] = {1,2,3,4,5};    // the original set
    int target = 5;         // the number subsets should add up to
    
    int set_size = sizeof(set)/sizeof(int);
    int powerset_size = pow(2,set_size);
    
    
    printf("powerset_size = %d\n", powerset_size);
    printf("set_size = %d\n", set_size);
    int i, j, sum;
    
    for(i = 1; i < powerset_size; i++) {
        // initialize sum to 0
        sum = 0;
        
        printf("set %d = ", i);
        for(j = 0; j < set_size; j++) {
            if((i >> j)&BIT_0) {
                sum += set[j];
                printf("%d ", set[j]);
            }
        }
        
        printf("\n");
        
        if(sum == target) {
            printf("sum found!\n");
            // find hamming weight of i (# of set bits in i)
            
            // allocate memory (of size = hamming weight of i)
            
            // assign to next index in our int * array[100]
            
        }
    }
    
    return 0;
}

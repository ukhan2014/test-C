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
    
    int set[] = {1,2,3,4,5};
    
    int set_size = sizeof(set)/sizeof(int);
    int powerset_size = pow(2,set_size);
    
    
    printf("powerset_size = %d\n", powerset_size);
    printf("set_size = %d\n", set_size);
    int i, j;
    
    for(i = 1; i < powerset_size + 1; i++) {
        printf("set %d = ", i);
        for(j = 0; j < set_size; j++) {
            if((i >> j)&BIT_0) {
                printf("%d ", set[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}

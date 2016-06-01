//
//  main.c
//  reverse-string
//
//  Created by Cabana on 6/1/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include <stdio.h>

void reverse(char * inputStr) {
    char * startPtr = inputStr;
    char * endPtr = inputStr;
    char tmp;   // for swapping chars
    
    // go to end of string just before '\0'
    while(*(endPtr + 1)) {
        endPtr++;
    }
    
    // reverse string, watch for pointer collision
    while((startPtr+1) != endPtr && startPtr != endPtr) {
        tmp = *startPtr;
        *startPtr = *endPtr;
        *endPtr = tmp;
        startPtr++;
        endPtr--;
    }
}

int main(int argc, const char * argv[]) {
    char userInput[50] = "";
    printf("Please enter a string: ");
    scanf("%s", userInput);
    //printf("userinput is: %s\n", userInput);
    
    int i = 0;
    char * endPtr = userInput;
    
    // length
    while(*endPtr) {
        i++;
        endPtr++;
    }
    printf("length is %d\n", i);
    
    reverse(userInput);
    
    printf("reversed string: %s\n", userInput);
    
    return 0;
}

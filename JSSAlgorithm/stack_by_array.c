//
//  stack_by_array.c
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 14..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "stack_by_array.h"

int64_t stack[STACK_MAX_SIZE];  // Stack Array Data
int64_t top;                    // Top of Stack

void init_stack () {
    top = -1;
}

int64_t push(u_int64_t val) {
    if (top >= STACK_MAX_SIZE-1) {
        printf("\nStack Overflow\n");
        return -1;
    }
    stack[++top] = val;
    return val;
}

int64_t pop(void) {
    if (top < 0) {
        printf("\nStack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void print_stack() {
    int64_t i;
    printf ("\n Stack From Top-----> To Bottom\n");
    for (i = top; i>=0; i--)
        printf ("%-6lld", stack[i]);
}

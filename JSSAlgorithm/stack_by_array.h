//
//  stack_by_array.h
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 14..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef stack_by_array_h
#define stack_by_array_h

#include <stdio.h>
#define STACK_MAX_SIZE 10           // Define length of stack

#ifdef __cplusplus
extern "C"
{
#endif
    void init_stack();
    int64_t push(u_int64_t val);
    int64_t pop(void);
    void print_stack();
#ifdef __cplusplus
}
#endif

#endif /* stack_by_array_h */

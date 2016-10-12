//
//  Fibonacci.cpp
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 11..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "Fibonacci.h"
#define MEMOIZATION_CONSTANT_INDEX  1000

__int64_t Fibonacci::recursiveFibo(__int64_t index) {
    
    if(index == 0) {
        return 0;
    }
    else if(index == 1) {
        return 1;
    }
    else {
        return recursiveFibo(index-1) + recursiveFibo(index-2);
    }
}

__int64_t Fibonacci::fiboDP(__int64_t index) {
    
    static __int64_t memoization[MEMOIZATION_CONSTANT_INDEX] = {};
    
    if (memoization[index] != 0) {
        return memoization[index];
    }
    
    if(index == 0) {
        return 0;
    }
    else if(index == 1) {
        return memoization[index] = 1;
    }
    
    /*
    if (index == 0 || index == 1) {
        return memoization[index] = 1;
    }
    */
    
    return memoization[index] = fiboDP(index - 1) + fiboDP(index - 2);
}

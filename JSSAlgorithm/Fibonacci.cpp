//
//  Fibonacci.cpp
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 11..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "Fibonacci.h"

__int64_t Fibonacci::fibo(__int64_t index) {
    
    if(index == 0) {
        return 0;
    }
    else if(index == 1) {
        return 1;
    }
    else {
        return fibo(index-1) + fibo(index-2);
    }
}

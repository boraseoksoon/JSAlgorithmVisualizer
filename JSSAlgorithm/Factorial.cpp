//
//  Factorial.cpp
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 11..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "Factorial.h"

__int64_t Factorial::recursiveFactorial(__int64_t number) {

    if (number <= 1) {
        return 1;
    } else {
        return number * recursiveFactorial(number - 1);
    }
}

__int64_t Factorial::iterativeFactorial(__int64_t number) {
    
    __int64_t total = 1;
    for (__int64_t i = 1; i <= number; i++) {
        total = total * i;
    }
    return total;
}

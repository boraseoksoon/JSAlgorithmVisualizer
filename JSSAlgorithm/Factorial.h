//
//  Factorial.hpp
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 11..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef Factorial_h
#define Factorial_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Factorial {
    public :
    __int64_t recursiveFactorial(__int64_t number);
    __int64_t iterativeFactorial(__int64_t number);
};

#endif /* Factorial_h */

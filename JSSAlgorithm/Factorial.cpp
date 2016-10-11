//
//  Factorial.cpp
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 11..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "Factorial.h"

__int64_t Factorial::factorial(__int64_t number) {

    if (number <= 1) {
        return 1;
    } else {
        return number * factorial(number - 1);
    }
}

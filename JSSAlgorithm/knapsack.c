//
//  knapsack.c
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 27..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "knapsack.h"

int knapsack(int i, int w, int price[], int weight[]){
    if(i == 0 || w == 0) {
        return 0;
    }
    
    int unselected_val = knapsack(i-1, w, price, weight);
    
    if(weight[i] > w) {
        return unselected_val;
    }
    
    int selected_val = knapsack(i-1, w-weight[i], price, weight) + price[i];
    int max_val = selected_val > unselected_val?selected_val:unselected_val;
    
    return max_val;
}

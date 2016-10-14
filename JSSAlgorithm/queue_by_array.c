//
//  queue_by_array.c
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 14..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "queue_by_array.h"
#include <stdio.h>

int queue[QUEUE_SIZE_MAX];
int front, rear;

void init_queue(void){
    front = rear = 0;
}

void clear_queue(void){
    front = rear;
}

int put(int k){
    // 큐가 꽉차있는지 확인
    if ((rear + 1) % QUEUE_SIZE_MAX == front){
        printf("\n   Queue overflow.");
        return -1;
    }
    
    queue[rear] = k;
    rear = ++rear % QUEUE_SIZE_MAX;
    return k;
}

int get(void){
    int i;
    if (front == rear){
        printf("\n  Queue underflow.");
        return -1;
    }
    
    i = queue[front];
    front = ++front % QUEUE_SIZE_MAX;
    return i;
}

void print_queue(void){
    int i;
    printf("\n Queue contents : Front ----------> Rear \n");
    for (i = front; i != rear; i = ++i%QUEUE_SIZE_MAX)
        printf("%-6d", queue[i]);
}

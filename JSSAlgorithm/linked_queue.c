//
//  linked_queue_node.c
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 14..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "linked_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct linked_queue_node
{
    int data;
    struct linked_queue_node *ptr;
};

struct linked_queue_node *head, *tail;

void put_linked_queue(int x)
{
    struct linked_queue_node *New, *temp;
    temp = head;
    New = (struct linked_queue_node *)malloc(sizeof(struct linked_queue_node));
    New->data = x;
    while( temp->ptr != tail ) temp = temp->ptr;
    New->ptr = tail;
    temp->ptr = New;
}

void init_linked_queue()
{
    head = (struct linked_queue_node *)malloc(sizeof(struct linked_queue_node));
    tail = (struct linked_queue_node *)malloc(sizeof(struct linked_queue_node));
    head->ptr = tail;
}

void print_linked_queue()
{
    struct linked_queue_node *Now;
    for (Now=head->ptr;Now!=tail;Now=Now->ptr)
    {
        printf("%d\t",Now->data);
    }
    printf("\n");
}

void get_linked_queue()
{
    struct linked_queue_node *del;
    if(head->ptr == tail)
    {
        printf("queue underflow\n");
        return;
    }
    del = head->ptr;
    
    head->ptr = del->ptr;
    free(del);
}

//
//  LinkedList.c
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 13..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

node* linked_list_head;

void initList()
{
    linked_list_head = (node*)malloc(sizeof(node));
    linked_list_head->next = NULL;
}

int countOfNodes()
{
    int count = 0;
    node *now;
    for(now=linked_list_head;now->next;now=now->next,count++){;}
    return count;   
}

node* nodeAtIndex(int idx)
{
    int count = countOfNodes();
    if(idx<0 || idx>count -1)
    {return NULL;}
    
    node *target = linked_list_head;
    int i=0;
    
    for(i=0;i<idx+1;i++){
        target=target->next;
    }
    
    return target;
}

void insertBefore(node* target, node* newNode)

{
    node *new;
    new = (node*)malloc(sizeof(node));
    *new = *newNode;
    
    node *left;
    left = target->prev;
    
    left->next = new;
    new->prev= left;
    target->prev = new;
    new->next = target;
}

void insertAfter(node* target, node *newNode)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    *new = *newNode;
    node *right;
    right = target->next;
    
    if(right){
        target->next = new;
        new->prev = target;
        right->prev = new;
        new->next = right;
    }
    
}

int removeNode(node *toDel)
{
    node *left, *right;
    left = toDel->prev;
    right = toDel->next;
    if(left!=NULL)
    {
        left->next = right;
        if(right!=NULL)
        {
            right->prev = left;
        }
        
        free(toDel);
        toDel=NULL;
        return 1;
    }
    
    return 0;
}

int removeNodeAt(int idx)
{
    return removeNode(nodeAtIndex(idx));
}

void addNode(node* newNode)
{
    node *new;
    new = (node*)malloc(sizeof(node));
    *new = *newNode;
    
    node *insp;
    int idx=0;
    insp = linked_list_head;
    while(insp->next != NULL)
    {
        insp = insp->next;
        idx++;
    }
    
    insp->next = new;
    new->prev = insp;
    new->next = NULL;
    
    /*	printf("idx = %d\n", idx);*/
}
void releaseList(){
    while(linked_list_head->next != NULL)
    {
        removeNode(linked_list_head->next);
    }
    
    free(linked_list_head);
    linked_list_head=NULL;
}

int indexOfValue(int value)
{
    int idx=0;
    node *now;
    for(now=linked_list_head->next;now;now=now->next){
        if( value == now->value)
        {
            return idx;
        }
        idx++;
    }
    return -1;
}

void dumpList()
{
    /*
     */
    node *temp;
    for(temp=linked_list_head->next;temp;temp=temp->next)
    {
        printf("%03d --> ",temp->value);
    }
    int count= countOfNodes();
    printf("\n\n\ncount : %03d", count);
}

//
//  LinkedList.h
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 13..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#ifdef __cplusplus
extern "C"
{
#endif
    
typedef struct __node
{
    int value;
    struct __node *prev;
    struct __node *next;
} node;

void initList();
int countOfNodes();
node* nodeAtIndex(int idx);
void insertBefore(node* target, node* newNode);
void insertAfter(node* target, node *newNode);
int removeNode(node *toDel);
int removeNodeAt(int idx);
void addNode(node* newNode);
void releaseList();
int indexOfValue(int value);
void dumpList();

#ifdef __cplusplus
}
#endif

#endif /* LinkedList_h */

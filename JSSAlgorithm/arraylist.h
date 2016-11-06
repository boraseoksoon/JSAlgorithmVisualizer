//
//  arrayList.h
//  ArrayList
//
//  Created by Seoksoon Jang on 26/09/2016.
//  Copyright © 2016 Seoksoon Jang. All rights reserved.
//

#ifndef __ARRAYLIST__
#define __ARRAYLIST__

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ArrayListNodeType {
    int data;
} ArrayListNode;

typedef struct ArrayListType {
    int maxElementCount;            // maximum element count.
    int currentElementCount;        // current element count.
    ArrayListNode* pElement;        // array to save element.
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
    
void deleteArrayList(ArrayList* pList);
    
int isArrayListFull(ArrayList* pList);
    
int addALElement(ArrayList* pList, int position, ArrayListNode element);
    
int removeALElement(ArrayList* pList, int position);
    
ArrayListNode* getALElement(ArrayList* pList, int position);
    
void displayArrayList(ArrayList* pList);
    
void clearArrayList(ArrayList* pList);
    
int getArrayListLength(ArrayList* pList);

#ifdef __cplusplus
}
#endif

#endif

#ifndef __COMMON_LIST_DEF__
#define __COMMON_LIST_DEF__

#define TRUE_VALUE    1
#define FALSE_VALUE   0

#endif

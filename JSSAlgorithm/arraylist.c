//
//  arrayList.c
//  ArrayList
//
//  Created by Seoksoon Jang on 26/09/2016.
//  Copyright © 2016 Seoksoon Jang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

ArrayList* createArrayList(int maxElementCount) {
    ArrayList* pReturn = NULL;
    
    if (maxElementCount > 0) {
        pReturn = (ArrayList*)malloc(sizeof(ArrayList));
        
        if (pReturn != NULL) {
            pReturn->maxElementCount = maxElementCount;
            pReturn->currentElementCount = 0;
            pReturn->pElement = NULL;
        } else {
            printf("error, memory allocation in %s\n", __PRETTY_FUNCTION__);
            return NULL;
        }
    } else {
        printf("error, max element count should be more than 0(zero)\n");
        return NULL;
    }
    
    pReturn->pElement = (ArrayListNode*) malloc(sizeof(ArrayListNode) * maxElementCount);
    
    if (pReturn->pElement == NULL) {
        printf("error, second memory alloc failure in %s\n", __PRETTY_FUNCTION__);
        free(pReturn);
        return NULL;
    }
    
    memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
    
    return pReturn;
}

void deleteArrayList(ArrayList* pList) {
    if (pList != NULL){
        free(pList->pElement);
        free(pList);
    }
}

int isArrayListFull(ArrayList* pList) {
    int ret = FALSE_VALUE;
    
    if (pList != NULL){
        if (pList->currentElementCount == pList->maxElementCount) {
            ret = TRUE_VALUE;
        }
    }
    return ret;
}

int addALElementFirst(ArrayList* pList, ArrayListNode element) {
    int position = 0;
    return addALElement(pList, position, element);
}

int addALElementLast(ArrayList* pList, ArrayListNode element) {
    int ret = FALSE_VALUE;
    int position = 0;
    
    if (pList != NULL){
        position = getArrayListLength(pList);
        ret = addALElement(pList, position, element);
    }
    return ret;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element) {
    int ret = FALSE_VALUE;
    int i = 0;
    
    if (pList != NULL) {
        if (isArrayListFull(pList) != TRUE_VALUE) {
            if (position >= 0 && position <= pList->currentElementCount) {
                
                for (i=pList->currentElementCount - 1; i >= position; i--) {
                    pList->pElement[i+1] = pList->pElement[i];
                }
            }
            
            pList->pElement[position] = element;
            pList->currentElementCount++;
            ret = TRUE_VALUE;
        } else {
            printf("error, position index - [%d] overflow in %s \n", position, __PRETTY_FUNCTION__);
        }
    } else {
        printf("error, list capacity overflow - [%d] / [%d] in %s\n", position, pList->maxElementCount, __PRETTY_FUNCTION__);
    }
    
    return ret;
}

int removeALElement(ArrayList* pList, int position) {
    int ret = FALSE_VALUE;
    int i = 0;
    
    if (pList != NULL){
        if(position >= 0 && position < pList->currentElementCount) {
            for (i=position; i<pList->currentElementCount-1; i++){
                pList->pElement[i] = pList->pElement[i+1];
            }
            
            pList->currentElementCount--;
            ret = TRUE_VALUE;
        } else {
            printf("error, position index overflow - [%d] in %s", position, __PRETTY_FUNCTION__);
        }
    }
    
    return ret;
}

ArrayListNode* getALElement(ArrayList* pList, int position) {
    ArrayListNode* pReturn = NULL;
    
    if (pList != NULL){
        if (position >= 0 && position < getArrayListLength(pList)) {
            pReturn = &(pList->pElement[position]);
        } else {
            printf("error, position index overflow - [%d] in %s", position, __PRETTY_FUNCTION__);
        }
    }
    
    return pReturn;
}

void displayArrayList(ArrayList* pList) {
    
    int i = 0;
    
    if (pList != NULL){
        printf("Now, maxElement is %d\n", pList->maxElementCount);
        printf("Now, currentElementCount is %d\n", pList->currentElementCount);
        
        for (i=0; i<pList->currentElementCount; i++){
            printf("[%d], %d\n", i, getALElement(pList,i)->data);
        }
        
    
        i = pList->currentElementCount;
        for (; i<pList->maxElementCount; i++){
            printf("[%d] Empty!\n", i);
        }
    } else {
        printf("ArrayList is NULL\n");
    }
}

int getArrayListLength(ArrayList* pList) {
    
    int ret = 0;
    
    if (pList != NULL) {
        ret = pList->currentElementCount;
    }
    
    return ret;
}

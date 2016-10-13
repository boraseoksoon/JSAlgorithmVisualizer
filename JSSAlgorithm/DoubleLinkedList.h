//
//  DoubleLinkedList.hpp
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 2016. 10. 3..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList
{
    
public:
    struct ListData
    {
        T nData;
        ListData *pLeft;
        ListData *pRight;
    };
    
    DoubleLinkedList();
    ~DoubleLinkedList();
    
    void PushHead(T nData);
    void PushTail(T nData);
    
    T PopHead();
    T PopTail();
    
    ListData *GetHead() { return m_pHead; }
    ListData *GetTail() { return m_pTail; }
    
    int GetSize() { return m_nSize; }
    bool IsEmpty() { return m_pTail->pRight == 0; }
    
    void Clear();
    
private:
    ListData *m_pHead;
    ListData *m_pTail;
    
    int m_nSize;
};

#endif /* DoubleLinkedList_h */

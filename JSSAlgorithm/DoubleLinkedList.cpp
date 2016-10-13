//
//  DoubleLinkedList.cpp
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 2016. 10. 3..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "DoubleLinkedList.h"

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
: m_pHead(0), m_nSize(0)
{
    m_pTail = new ListData();
    m_pTail->pLeft = m_pTail->pRight = 0;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    // destructor goes here.
}

template<typename T>
void DoubleLinkedList<T>::PushHead(T nData)
{
    if( m_pHead == NULL )
    {
        m_pHead = new ListData();
        m_pHead->nData = nData;
        
        m_pHead->pLeft = m_pHead->pRight = m_pTail;
        m_pTail->pLeft = m_pTail->pRight = m_pHead;
        return;
    }
    
    ListData *temp = m_pHead;
    m_pHead = new ListData();
    m_pHead->nData = nData;
    
    m_pHead->pLeft = temp->pLeft;
    m_pHead->pLeft->pRight = m_pHead;
    
    m_pHead->pRight = temp;
    temp->pLeft = m_pHead;
    ++m_nSize;
}

template<typename T>
void DoubleLinkedList<T>::PushTail(T nData)
{
    if( m_pHead == NULL )
    {
        m_pHead = new ListData();
        m_pHead->nData = nData;
        m_pHead->pLeft = m_pHead->pRight = m_pTail;
        m_pTail->pRight = m_pTail->pLeft = m_pHead;
        return;
    }
    
    ListData *temp = new ListData();
    temp->nData = nData;
    temp->pLeft = m_pTail->pLeft;
    m_pTail->pLeft = temp;
    
    temp->pLeft->pRight = temp;
    temp->pRight = m_pTail;
    ++m_nSize;
}

template<typename T>
T DoubleLinkedList<T>::PopHead()
{
    if( m_pHead )
    {
        if( m_pHead->pRight == m_pTail )
        {
            T data = m_pHead->nData;
            delete m_pHead;
            m_pHead = 0;
            m_pTail->pRight = m_pTail->pLeft = m_pHead;
            return data;
        }
        ListData *temp = m_pHead;
        m_pHead = temp->pRight;
        
        temp->pLeft->pRight = m_pHead;
        m_pHead->pLeft = temp->pLeft;
        T data = temp->nData;
        delete temp;
        --m_nSize;
        return data;
    }
    return T();
}

template<typename T>
T DoubleLinkedList<T>::PopTail()
{
    if( m_pHead )
    {
        if( m_pHead->pRight == m_pTail )
        {
            T data = m_pHead->nData;
            delete m_pHead;
            m_pHead = 0;
            m_pTail->pRight = m_pTail->pLeft = m_pHead;
            return data;
        }
        ListData *temp = m_pTail->pLeft;
        temp->pLeft->pRight = m_pTail;
        m_pTail->pLeft = temp->pLeft;
        
        T data = temp->nData;
        delete temp;
        --m_nSize;
        return data;
    }
    return T();
}

template<typename T>
void DoubleLinkedList<T>::Clear()
{
    while(m_pHead)
    {
        PopTail();
    }
}

template class DoubleLinkedList<int64_t>;

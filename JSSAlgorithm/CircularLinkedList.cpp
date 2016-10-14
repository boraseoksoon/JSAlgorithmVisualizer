//
//  CircularLinkedList.cpp
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 2016. 10. 3..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "CircularLinkedList.hpp"

#include <stdio.h>
#include <iostream>
using namespace std;


CLinkedList::CLinkedList()
{
    //Node *newNode = new Node; 더미노드 없음.
    tail = nullptr;
    cur = nullptr;
    before = nullptr;
    numOfData = 0;
}

void CLinkedList::LInsert(LData data)
{
    Node *newNode = new Node(data);
    
    if (tail == nullptr)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    numOfData++;
}

void CLinkedList::LInsertFront(LData data)
{
    Node *newNode = new Node(data);
    
    if (tail == nullptr)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    numOfData++;
}

bool CLinkedList::LFirst(LData *pdata)
{
    if (tail->next == nullptr)
        return false;
    
    before = tail;
    cout << "LinkedList head: " << tail << endl;
    cout << "LinkedList head->next: " << tail->next << endl;
    cur = tail->next;
    *pdata = cur->getdata();
    
    return true;
}

bool CLinkedList::LNext(LData *pdata)
{
    if (tail == nullptr)
        return false;
    
    before = cur;
    cur = cur->next;
    *pdata = cur->getdata();
    
    return true;
}

LData CLinkedList::LRemove()
{
    Node *rpos = cur;
    LData rdata = rpos->getdata();
    
    if (rpos == tail)
    {
        if (tail == nullptr)
            tail = nullptr;
        else
            tail = before;
    }
    
    before->next = cur->next;
    cur = before;
    
    delete rpos;
    numOfData--;
    return rdata;
}

int CLinkedList::LCount()
{
    return numOfData;
}

//
//  CircularLinkedList.hpp
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 2016. 10. 3..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef CircularLinkedList_hpp
#define CircularLinkedList_hpp

typedef int LData;

class Node
{
private:
    LData data;
public:
    
    Node *next;
    
    Node(){}
    Node(LData data):data(data){}
    
    LData getdata()
    {
        return data;
    }
};

class CLinkedList
{
private:
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
    
public:
    CLinkedList();
    void LInsert(LData data); //꼬리에 노드를 추가
    void LInsertFront(LData data); //머리에 노드를 추가
    
    bool LFirst(LData *pdata);
    bool LNext(LData *pdata);
    LData LRemove();
    int LCount();
};


#endif /* CircularLinkedList_hpp */

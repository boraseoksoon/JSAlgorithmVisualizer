//
//  StackByLinkedList.hpp
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 14..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef StackByLinkedList_hpp
#define StackByLinkedList_hpp

#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    Node();
    Node(T);
    void setData(T);
    T getData();
    // template <typename T> friend class stackL;
    T data;
    Node<T>* nextNode=NULL;
private:
};

template <typename T>
class stackL{
public:
    T getTop();
    void push(T);
    void pop();
    int64_t getSize();
    void printStack();
private:
    int64_t size=-1;
    Node<T>* top = NULL;
    Node<T>* bottom = NULL;
};

#endif /* StackByLinkedList_hpp */

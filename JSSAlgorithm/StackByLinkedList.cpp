//
//  StackByLinkedList.cpp
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 14..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "StackByLinkedList.hpp"

template<typename T>
Node<T>::Node(){
    data = NULL;
}

template<typename T>
Node<T>::Node(T d){
    data = d;
}

template<typename T>
void Node<T>::setData(T d){
    data = d;
}

template<typename T>
T Node<T>::getData(){
    return data;
}


template <typename T>
void stackL<T>::push(T d){
    Node<T>* n = new Node<T>(d);
    if (size == -1){
        top = n;
        bottom = n;
    }
    else{
        n->nextNode = top;
        top = n;
    }
    size++;
    
}

template <typename T>
int64_t stackL<T>::getSize(){
    return size+1;
}

template<typename T>
T stackL<T>::getTop(){
    if (size < 0){
        cout << "stack is empty" << endl;
        return NULL;
    }
    return top->data;
}

template<typename T>
void stackL<T>::pop(){
    if (size < 0){
        cout << "stack is empty" << endl;
        return;
    }
    cout << getTop() << " <- pop" << endl;
    Node<T>* temp = top->nextNode;
    top->nextNode = NULL;
    top = temp;
    size--;
}

template <typename T>
void stackL<T>::printStack(){
    cout << "stack" << endl;
    cout << "Top :";
    Node<T>* temp = top;
    for (int64_t i = 0; i <= size; i++){
        cout << "\t" << temp->data << endl;
        temp = temp->nextNode;
    }
}

template class stackL<int64_t>;

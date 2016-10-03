//
//  SingleLinkedList.hpp
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 2016. 10. 2..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#ifndef SingleLinkedList_hpp
#define SingleLinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

#endif /* SingleLinkedList_hpp */

class SingleLinkedList{
    struct Node {
        int x;
        Node *next;
    };
    
public:
    SingleLinkedList();
    void addValue(int val);
    int popValue();
    ~SingleLinkedList();
private:
    Node *head;
};

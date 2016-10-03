//
//  SingleLinkedList.cpp
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 2016. 10. 2..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include "SingleLinkedList.h"

// constructor
SingleLinkedList::SingleLinkedList(){
    head = NULL; // set head to NULL
}

// desctuctor
SingleLinkedList::~SingleLinkedList(){
    //
}

// This prepends a new value at the beginning of the list
void SingleLinkedList::addValue(int val){
    Node *n = new Node();   // create new Node
    n->x = val;             // set value
    n->next = head;         // make the node point to the next node.
    //  If the list is empty, this is NULL, so the end of the list --> OK
    head = n;               // last but not least, make the head point at the new node.
}

// returns the first element in the list and deletes the Node.
// caution, no error-checking here!
int SingleLinkedList::popValue(){
    Node *n = head;
    int ret = n->x;
    
    head = head->next;
    delete n;
    return ret;
}

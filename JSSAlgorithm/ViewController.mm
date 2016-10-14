//
//  ViewController.m
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 30/09/2016.
//  Copyright © 2016 Seoksoon Jang. All rights reserved.
//

#import "ViewController.h"
#import "arraylist.h"
#import "linkedlist.h"
#import "DoubleLinkedList.h"
#import "Fibonacci.h"
#import "Factorial.h"
#import "TowerOfHanoi.hpp"
#import "StackByLinkedList.hpp"
#import "stack_by_array.h"

#include <time.h>
#include <queue>


using namespace std;

@interface ViewController ()

@end

@implementation ViewController

void DrawFromHead(DoubleLinkedList<int64_t> *pList)
{
    DoubleLinkedList<int64_t>::ListData *list = pList->GetHead();
    while(list && list != pList->GetTail() )
    {
        printf("[%d]->", list->nData);
        list = list->pRight;
    }
    printf("[Tail]\n");
}

void DrawFromTail(DoubleLinkedList<int64_t> *pList)
{
    DoubleLinkedList<int64_t>::ListData *list = pList->GetTail()->pLeft;
    if( list )
        printf("[Tail]->");
    while(list && list != pList->GetHead() )
    {
        printf("[%d]->", list->nData);
        list = list->pLeft;
    }
    if( list )
        printf("[%d]\n", list->nData);
}

const NSArray* datalist = @[@"Algorithm", @"DataStructure"];

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    //
    
    if (indexPath.row == 0) {
        NSLog(@"algorithm!");
    } else if (indexPath.row == 1) {
        NSLog(@"datastructure!");
    }
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    /*
     *   This is an important bit, it asks the table view if it has any available cells
     *   already created which it is not using (if they are offScreen), so that it can
     *   reuse them (saving the time of alloc/init/load from xib a new cell ).
     *   The identifier is there to differentiate between different types of cells
     *   (you can display different types of cells in the same table view)
     */
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"TopFrontMainTableView"];
    
    /*
     *   If the cell is nil it means no cell was available for reuse and that we should
     *   create a new one.
     */
    if (cell == nil) {
        
        /*
         *   Actually create a new cell (with an identifier so that it can be dequeued).
         */
        
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"TopFrontMainTableView"];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    
    /*
     *   Now that we have a cell we can configure it to display the data corresponding to
     *   this row/section
     */
    cell.textLabel.text = [datalist objectAtIndex:indexPath.row];
    
    /* Now that the cell is configured we return it to the table view so that it can display it */
    
    return cell;
    
}

/*
 - (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
 //
 }
 */
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [datalist count];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    // C++ STL Queue test in Objective-C++.
    queue<char> Queue;
    
    Queue.push('A');
    Queue.push('B');
    Queue.push('C');
    
    cout << "Queue Size : " << Queue.size() << endl;
    cout << "Queue Items" << endl;
    
    while( ! Queue.empty() )
    {
        cout << Queue.front() << endl;
        Queue.pop(); 
    }
    
    // Double Linked List
    srand(time(0));
    DoubleLinkedList<int64_t>* list = new DoubleLinkedList<int64_t>();
    for(int64_t i=0; i<10; ++i)
    {
        int64_t random = rand()%100;
        list->PushTail(random);
        DrawFromHead(list);
        if( i == 5 )
        {
            list->PopHead();
            DrawFromHead(list);
        }
    }
    list->Clear();
    DrawFromHead(list);
    for(int64_t i=0; i<10; ++i)
    {
        int64_t random = rand()%100;
        list->PushHead(random);
        DrawFromTail(list);
        if( i == 5 )
        {
            list->PopTail();
            DrawFromTail(list);
        }
    }
    list->Clear();
    DrawFromTail(list);
    
    // Simple Linked List
    int64_t i = 1;
    initList();
    
    node* now;
    node temp;
    
    for(i=1;i<101;i++)
    {
        temp.value = i;
        addNode(&temp);
    }
    
    for(i=99; i>0; i-=9)
    {
        temp.value = 999;
        insertAfter(nodeAtIndex(i), &temp);
        insertBefore(nodeAtIndex(i), &temp);
    }
    
    for(i=99;i>0;i-=13)
    {
        removeNode(nodeAtIndex(i));
    }
    
    dumpList();
    printf("\n\n count of nodes : %d", countOfNodes());
    printf("\n value of node at 33 : %d", nodeAtIndex(33)->value);
    printf("\n index of node whose value is 99 : %d", indexOfValue(99));
    
    //

    

    
    // ArrayList
    i = 0;
    int64_t arrayCount = 0;
    ArrayList* pList = NULL;
    ArrayListNode* pValue = NULL;
    
    pList = createArrayList(6);
    
    if (pList != NULL){
        ArrayListNode node;
        
        // List initialization : 1,3,5 add.
        node.data = 1;
        addALElement(pList, 0, node);
        
        node.data = 3;
        addALElement(pList, 1, node);
        
        node.data = 5;
        addALElement(pList, 2, node);
        
        displayArrayList(pList);
        
        // remove the first element
        removeALElement(pList, 0);
        displayArrayList(pList);
        
        arrayCount = getArrayListLength(pList);
        
        for (i=0; i<arrayCount; i++){
            pValue = getALElement(pList, i);
            printf("position[%d] - %d\n", i, pValue->data);
        }
        
        deleteArrayList(pList);
    }
    
    __int32_t num;
    num = 2;
    
    Fibonacci* fibonacci = new Fibonacci();
    
    NSLog(@"*********** DP fibonacci started ***********");
    clock_t tStart2 = clock();
    for(__int32_t i = 0 ; i < num ; i++ ){
        printf("fiboDP : %lld\n", fibonacci->fiboDP(i));
    }
    NSLog(@"*********** DP fibonacci finished ***********");
    printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);
    printf("\n\n");

    //
    NSLog(@"*********** recursive fibonacci started ***********");
    clock_t tStart1 = clock();
    for(__int32_t i = 0 ; i < num ; i++ ){
        printf("recursiveFibo : %lld\n", fibonacci->recursiveFibo(i));
    }
    NSLog(@"*********** recursive fibonacci finished ***********");
    printf("Time taken: %.2fs\n", (double)(clock() - tStart1)/CLOCKS_PER_SEC);
    printf("\n\n");
    //
    
    
    Factorial* fact = new Factorial();
    NSLog(@"recursive version of factorial : %lld", fact->recursiveFactorial(5));
    NSLog(@"iterative version of factorial : %lld", fact->iterativeFactorial(5));
    
    TowerOfHanoi* hanoi = new TowerOfHanoi(5);
    hanoi->moveDisk(hanoi->getNumberOfDisk(), 'A', 'B', 'C');
    
    
    // Stack By LinkedList
    stackL<int64_t> s;
    s.push(2);
    s.push(23);
    s.push(24);
    s.push(25);
    s.push(26);
    cout << s.getTop() << endl;
    
    s.printStack();
    
    s.pop();
    s.pop();
    s.pop();
    
    s.printStack();
    
    s.pop();
    s.pop();
    s.pop();
    
    // Stack By Simple Array
        
    init_stack();
    
    printf ("\nPush 5, 4, 7, 8, 2, 1");
    push(5);
    push(4);
    push(7);
    push(8);
    push(2);
    push(1);
    print_stack();
    
    printf("\nPop");
    i = pop();
    print_stack();
    printf("\n  popped value is %lld\n", i);
    
    printf("\nPush 3, 2, 5, 7, 2");
    push(3);
    push(2);
    push(5);
    push(7);
    push(2);
    print_stack();
    
    printf("\nNow Stack is full, push 3");
    push(3);
    print_stack();
    
    printf("\nInitialize stack");
    init_stack();
    print_stack();
    
    printf("\nNow Stack is empty, pop");
    i = pop();
    print_stack();
    printf("\n  popped value is %lld\n", i);
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

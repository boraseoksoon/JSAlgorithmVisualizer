//
//  ViewController.m
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 30/09/2016.
//  Copyright © 2016 Seoksoon Jang. All rights reserved.
//

#import "ViewController.h"
#import "arrayList.h"
#import "Fibonacci.h"
#import "Factorial.h"
#import "TowerOfHanoi.hpp"
#include <time.h>
#import "LinkedList.h"

@interface ViewController ()

@end

@implementation ViewController

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
    
    
    int i = 0;
    int arrayCount = 0;
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
    
    // Simple Linked List
    i = 1;
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

    
    
    __int32_t num;
    num = 50;
    
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
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end

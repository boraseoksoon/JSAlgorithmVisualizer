//
//  ViewController.m
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 30/09/2016.
//  Copyright © 2016 Seoksoon Jang. All rights reserved.
//

#import "ViewController.h"
#import "arrayList.h"
#import "SingleLinkedList.h"

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
    
    SingleLinkedList list;
    
    list.addValue(5);
    list.addValue(10);
    list.addValue(20);
    
    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    
    /*
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
     */
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

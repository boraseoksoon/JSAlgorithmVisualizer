//
//  ViewController.m
//  JSSAlgorithm
//
//  Created by Seoksoon Jang on 30/09/2016.
//  Copyright © 2016 Seoksoon Jang. All rights reserved.
//

#import "ViewController.h"
#import "arrayList.h"

@interface ViewController ()

@end

@implementation ViewController

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
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

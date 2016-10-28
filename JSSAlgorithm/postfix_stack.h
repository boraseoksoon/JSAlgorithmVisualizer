//
//  postfixStack.h
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 28..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

/*  postfixStack ADT
 *
 *  objects : postfixStack has some additional functions in addition to basic stack(using array), to act as stack data         
 *            structure for postfix_notation, The detail can be read below.
 *
 *  functions :
 *            ************************ user-land functions
 *              1. StackRef createStack(StackRef, size)
 *              2. String parse_to_postfix(infix-order-character-expression)
 *              3. Result calculate(postfix-order-character-expression)
 *              4. Bool deallocationStack(StackRef)
 *            ************************ developer-land functions
 *              4. Void printStacKUpto(stackIndex)
 *              5. Void printAllStack()
 *              6. Stack push(one element)
 *              7. Element popS()
 */

#ifndef postfix_stack_h
#define postfix_stack_h

#define MAX_SIZE_STACK 100
#define True     1
#define False   0

#ifdef __cplusplus
extern "C"
{
#endif

    typedef int element;
    typedef struct {
        element* stack;
        int top;
    }StackType;

    // ADT
    StackType* create_postfix_stack(StackType* s, int stackMaxSize);
    void dealloc_postfix_stack(StackType* s);
    char* parse_from_infix_to_postfix(char* infixString);
    long calculate (char* postfixString);
    long regex_check_operator(char* infixString, char* regex_condition);
    
    StackType* postfix_push(element infixCharacter);
    element postfix_pop(element infixCharacter);
    void print_all_stack();
    void print_stack_upto(int stackIndex);
    
#ifdef __cplusplus
}
#endif

#endif /* postfix_stack_h */



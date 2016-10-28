//
//  postfixStack.c
//  JSAlgorithmVisualizer
//
//  Created by Seoksoon Jang on 2016. 10. 28..
//  Copyright © 2016년 Seoksoon Jang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "postfix_stack.h"
#include <regex.h>

#define POSTFIX_STACK_MAX_SIZE  100

// ADT
StackType* postfixStack;

StackType* create_postfix_stack(StackType* s, int stackMaxSize) {
    
    if (s->stack != NULL) {
        s->stack = (element*)malloc(sizeof(element) * stackMaxSize);
        s->top = -1;
        return s;
        
    } else {
        fprintf(stderr, "error : %s", __PRETTY_FUNCTION__);
        exit(1);
    }
}

void dealloc_postfix_stack(StackType* s) {
    
    if (s->stack != NULL) {
        free(s->stack);
        s->stack = NULL;
    } else {
        fprintf(stderr, "error : %s", __PRETTY_FUNCTION__);
        exit(1);
    }
}

long regex_check_operator(char* infixString, char* regex_condition) {
    
    regex_t regex;
    int reti;
    char msgbuf[100];
    
    /* Compile regular expression */
    reti = regcomp(&regex, infixString, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    
    /* Execute regular expression */
    reti = regexec(&regex, regex_condition, 0, NULL, 0);
    if (!reti) {
        puts("There is not supported operator.");
        
        /* Free memory allocated to the pattern buffer by regcomp() */
        regfree(&regex);
        return True;
    }
    else if (reti == REG_NOMATCH) {
        puts("All operator okay to go.");
        
        /* Free memory allocated to the pattern buffer by regcomp() */
        regfree(&regex);
        
        return False;
    }
    else {
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
    }
}

char* parse_from_infix_to_postfix(char* infixString) {
    return "test";
}

long calculate (char* postfixString) {
    
    //
    
    return 100;
}

StackType* postfix_push(element infixCharacter) {
    
    if (postfixStack->top >= POSTFIX_STACK_MAX_SIZE) {
        fprintf(stderr, "error : %s", __PRETTY_FUNCTION__);
        exit(1);
        
    } else {
        postfixStack->stack[postfixStack->top++] = infixCharacter;
    }

    return postfixStack;
}

element postfix_pop(element infixCharacter) {
    
    if (postfixStack->top >= -1) {
        fprintf(stderr, "error : %s", __PRETTY_FUNCTION__);
        exit(1);
    } else {
        return postfixStack->stack[postfixStack->top--];
    }
}

void print_all_stack() {
    
    for (int i = 0; i<postfixStack->top; i++) {
        printf("postfixStack[%d] : %c\n", i, postfixStack->stack[i]);
    }
}

void print_stack_upto(int stackIndex) {
    
    for (int i=0; i<postfixStack->stack[stackIndex]; i++) {
        printf("postfixStack[%d] : %c\n", i, postfixStack->stack[i]);
    }
}


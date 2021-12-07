#ifndef _LINKED_STACK_H
#define _LINKED_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    char name[20];
} Element;

typedef struct StackNode {
    Element data;
    struct StackNode *next;
} StackNode, *LinkStack;

int stack_init(LinkStack *stack);
int stack_is_empty(LinkStack stack);
int stack_push(LinkStack stack, Element *elem);
StackNode *stack_pop(LinkStack stack);
StackNode *stack_top(LinkStack stack);
void stack_printf(LinkStack stack);

#endif
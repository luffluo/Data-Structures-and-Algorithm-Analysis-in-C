#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Element {
    // char name[20];
    char name;
} Element;


typedef struct stack_t {
    Element data[MAX_SIZE];
    int top;
} stack_t;

void stack_init(stack_t *stack);
int bracket_check(const char *str, int length);
int stack_is_empty(stack_t *stack);
int stack_is_full(stack_t *stack);
int stack_push(stack_t *stack, Element *elem);
int stack_push_char(stack_t *stack, char c);
int stack_top(stack_t *stack, Element *elem);
char stack_pop_char(stack_t *stack);
int stack_pop(stack_t *stack, Element *elem);
void stack_print(stack_t *stack);

#endif
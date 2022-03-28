#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct Element
{
    int key;
    char name[50];
    int age;
} Element;

typedef struct List
{
    Element *data;
    int length;
} List;

int list_init(List *list);
void list_destory(List *list);
void list_clear(List *list);
int list_length(List *list);
int list_is_empty(List *list);
int list_elem_get(List *list, int i, Element *elem);
int list_elem_locate(List *list, Element *elem);
int list_elem_insert(List *list, int i, Element elem);
int list_elem_delete(List *list, int i);
int list_elem_append(List *list, Element elem);

#endif /* end _LIST_H */
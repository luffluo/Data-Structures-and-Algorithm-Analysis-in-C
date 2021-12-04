#ifndef _LINK_LIST_H
#define _LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct Element
{
    char no[10];
    char name[10];
    int score;
} Element;

// LinkList is a list
// ListNode is a node of list
// ListNode is a element for LinkList
typedef struct student
{
    Element data;
    struct student *next;
} ListNode, *LinkList;

int list_init(LinkList *liner);
int list_is_empty(LinkList liner);
int list_insert(LinkList liner, int i, Element elem);
int list_insert_next_node(ListNode *node, Element elem);
int list_insert_prev_node(ListNode *node, Element elem);
int list_delete(LinkList liner, int i);
int list_delete_node(LinkList liner, ListNode *node);
int list_get_prev_node(LinkList liner, ListNode *node, ListNode *result);
int list_tail_create(LinkList liner);
void list_print(LinkList liner);

#endif

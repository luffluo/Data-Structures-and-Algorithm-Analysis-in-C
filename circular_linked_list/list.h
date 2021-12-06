#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    char no[10];
    char name[20];
} Element;

typedef struct ListNode
{
    Element data;
    struct ListNode *next;
} ListNode, *LinkList;

int list_init(LinkList *list);
int list_is_empty(LinkList list);
int list_node_is_tail(LinkList list, ListNode *node);
int list_insert_next_node(ListNode *node, ListNode *next);
int list_insert_prev_node(ListNode *node, ListNode *prev);
ListNode *list_node_create(Element elem);
int list_node_delete(LinkList list, ListNode *node);
ListNode *list_get_prev_node(LinkList list, ListNode *node);

#endif
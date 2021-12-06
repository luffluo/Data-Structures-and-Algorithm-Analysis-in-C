#ifndef _LIST_H

#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    char no[10];
    char name[20];
} Element;

typedef struct DoublyNode
{
    Element data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode, *LinkList;

int list_init(LinkList *list);
int list_insert_next_node(DoublyNode *node, DoublyNode *next);
int list_insert_prev_node(DoublyNode *node, DoublyNode *prev);
int list_insert_node(LinkList list, int i, Element elem);
int list_delete_next_node(DoublyNode *node);
int list_destory(LinkList list);
void list_node_print(DoublyNode *);
int list_iterate(LinkList list, void (*handle)(DoublyNode *));
DoublyNode *list_create_node(Element elem);
int list_append(LinkList list, Element elem);

#endif
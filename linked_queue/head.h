#ifndef _QUEUE_HEAD
#define _QUEUE_HEAD

#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    char name[20];
} Element;

typedef struct QueueNode {
    Element data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} LinkQueue;

int queue_init(LinkQueue *queue);
int queue_is_empty(LinkQueue *queue);
int queue_send(LinkQueue *queue, Element *elem);
int queue_peek(LinkQueue *queue, Element *elem);
void queue_print(LinkQueue *queue);

#endif
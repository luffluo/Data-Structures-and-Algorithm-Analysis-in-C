#ifndef _QUEUE_HEAD
#define _QUEUE_HEAD

#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    char name[20];
} Element;

typedef struct QueueNode {
    Element data;
    struct QueueNode *prev;
    struct QueueNode *next;
} QueueNode, *LinkQueue;

#endif
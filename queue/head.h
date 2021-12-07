#ifndef _QUEUE_HEAD_H
#define _QUEUE_HEAD_H

#include <stdio.h>

#define MAX_SIZE 3

typedef struct Element {
    char name[20];
} Element;

typedef struct queue
{
    Element data[MAX_SIZE];
    int front, rear;
    // int size; // 用来记录当前队列里的元素个数
    // char tag; // 用来标记上次操作是 入队(1)/出队(0)
} queue_t;

void queue_init(queue_t *queue);
int queue_is_empty(queue_t *queue);
int queue_next_rear(queue_t *queue);
int queue_next_front(queue_t *queue);
int queue_is_full(queue_t *queue);
int queue_send(queue_t *queue, Element *elem);
int queue_peek(queue_t *queue, Element *elem);

#endif
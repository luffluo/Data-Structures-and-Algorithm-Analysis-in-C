#include "head.h"

int main(void)
{
    LinkQueue queue;

    queue_init(&queue);

    Element luff = {"Luff"};
    queue_send(&queue, &luff);

    Element rose = {"Rose"};
    queue_send(&queue, &rose);

    queue_print(&queue);

    return 0;
}

int queue_init(LinkQueue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;

    return 1;
}

int queue_is_empty(LinkQueue *queue)
{
    return queue->front == NULL;
}

int queue_send(LinkQueue *queue, Element *elem)
{
    if (queue == NULL || elem == NULL) {
        return 0;
    }

    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode));
    node->next = NULL;
    node->data = *elem;

    if (queue_is_empty(queue)) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }

    queue->rear = node;

    return 1;
}

int queue_peek(LinkQueue *queue, Element *elem)
{
    if (queue == NULL || elem == NULL || queue_is_empty(queue)) {
        return 0;
    }
    
    QueueNode *node = queue->front;
    *elem = node->data;

    // 把头节点设为出队节点的下一个节点
    queue->front = node->next;

    // 如果出队的是最后一个节点
    // 就尾节点指向头节点
    if (queue->rear == node) {
        queue->rear = queue->front;
    }

    free(node);

    return 1;
}

void queue_print(LinkQueue *queue)
{
    QueueNode *curr = queue->front;

    while (curr != NULL) {
        printf("Hi %s\n", curr->data.name);
        curr = curr->next;
    }
}

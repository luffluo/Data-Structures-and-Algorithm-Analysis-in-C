#include "head.h"

int main(void)
{
    queue_t queue;

    queue_init(&queue);

    Element luff = {"Luff"};
    queue_send(&queue, &luff);

    Element rose = {"Rose"};
    queue_send(&queue, &rose);

    Element peekOne;
    queue_peek(&queue, &peekOne);
    printf("I'm %s\n", peekOne.name);

    Element qiaoba = {"Qiaoba"};
    queue_send(&queue, &qiaoba);

    Element peekTwo;
    queue_peek(&queue, &peekTwo);
    printf("I'm %s\n", peekTwo.name);

    Element peekThree;
    queue_peek(&queue, &peekThree);
    printf("I'm %s\n", peekThree.name);
}

void queue_init(queue_t *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int queue_is_empty(queue_t *queue)
{
    return queue->front == queue->rear;
}

int queue_next_rear(queue_t *queue)
{
    return (queue->rear + 1) % MAX_SIZE;
}

int queue_next_front(queue_t *queue)
{
    return (queue->front + 1) % MAX_SIZE;
}

int queue_is_full(queue_t *queue)
{
    return queue_next_rear(queue) == queue->front;
}

int queue_send(queue_t *queue, Element *elem)
{
    if (queue_is_full(queue)) {
        return 0;
    }

    queue->data[queue->rear] = *elem;

    queue->rear = queue_next_rear(queue);

    return 1;
}

int queue_peek(queue_t *queue, Element *elem)
{
    if (queue_is_empty(queue)) {
        return 0;
    }

    *elem = queue->data[queue->front];
    queue->front = queue_next_front(queue);

    return 1;
}

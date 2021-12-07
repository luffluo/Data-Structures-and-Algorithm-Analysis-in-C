#include "head.h"

int main(void)
{
    LinkQueue queue;

}

int queue_init(LinkQueue *queue)
{
    *queue = (QueueNode *) malloc(sizeof(QueueNode));

    if (*queue == NULL) {
        return 0;
    }

    (*queue)->prev = NULL;
    (*queue)->next = NULL;

    return 1;
}



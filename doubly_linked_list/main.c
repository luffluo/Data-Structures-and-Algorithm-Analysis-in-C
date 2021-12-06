#include "list.h"

int main(void)
{
    LinkList list;

    list_init(&list);

    Element no1 = {"9527", "Luff"};
    Element no2 = {"1234", "Lily"};

    list_append(list, no1);
    list_append(list, no2);

    list_iterate(list, list_node_print);

    return 0;
}

// List init
// O(1), O(1)
int list_init(LinkList *list)
{
    *list = (DoublyNode *) malloc(sizeof(DoublyNode));

    if (*list == NULL) {
        return 0;
    }

    (*list)->prev = NULL;
    (*list)->next = NULL;

    return 1;
}

int list_insert_next_node(DoublyNode *node, DoublyNode *next)
{
    if (node == NULL || next == NULL) {
        return 0;
    }

    next->next = node->next;
    next->prev = node;

    if (node->next != NULL) {
        node->next->prev = next;
    }

    node->next = next;

    return 1;
}

// O(1)
int list_insert_prev_node(DoublyNode *node, DoublyNode *prev)
{
    if (node == NULL || prev == NULL) {
        return 0;
    }

    prev->prev = node->prev;
    prev->next = node;

    node->prev->next = prev;

    return 1;
}

DoublyNode *list_create_node(Element elem)
{
    DoublyNode *node = (DoublyNode *) malloc(sizeof(DoublyNode));
    node->data = elem;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

int list_append(LinkList list, Element elem)
{
    if (list == NULL) {
        return 0;
    }

    while (list->next != NULL)
    {
        list = list->next;
    }

    DoublyNode *node = list_create_node(elem);
    node->prev = list;
    list->next = node;

    return 1;
}

// O(n)
int list_insert_node(LinkList list, int i, Element elem)
{
    if (list == NULL || i < 1) {
        return 0;
    }

    int j = 1;
    DoublyNode *next = list->next;

    while (j < i)
    {
        if (next == NULL) {
            return 0;
        }

        next = next->next;
        j++;
    }

    DoublyNode *node = (DoublyNode *) malloc(sizeof(DoublyNode));
    node->data = elem;

    return list_insert_prev_node(next, node);
}

// O(1)
int list_delete_next_node(DoublyNode *node)
{
    if (node == NULL) {
        return 0;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    free(node);

    return 1;
}

// O(n)
int list_destory(LinkList list)
{
    if (list == NULL) {
        return 0;
    }

    while (list->next != NULL)
    {
        list_delete_next_node(list->next);
    }

    free(list);
    
    return 1;
}

void list_node_print(DoublyNode *node)
{
    printf("I'm %s, No. %s\n", node->data.name, node->data.no);
}

// O(n)
int list_iterate(LinkList list, void (*handle)(DoublyNode *))
{
    if (list == NULL) {
        return 0;
    }

    while (list->next != NULL)
    {
        handle(list->next);
        list = list->next;
    }
    
    return 1;
}

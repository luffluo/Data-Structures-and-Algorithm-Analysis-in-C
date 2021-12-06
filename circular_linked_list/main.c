#include "list.h"

int main(void)
{
    LinkList list;
}

int list_init(LinkList *list)
{
    *list = (ListNode *) malloc(sizeof(ListNode));

    if (*list == NULL) {
        return 0;
    }

    (*list)->next = *list;

    return 1;
}

int list_is_empty(LinkList list)
{
    if (list == NULL) {
        return 1;
    }

    return list->next == list;
}

// Is tail node
int list_node_is_tail(LinkList list, ListNode *node)
{
    if (list == NULL || node == NULL) {
        return 0;
    }

    return list == node->next;
}

int list_insert_next_node(ListNode *node, ListNode *next)
{
    if (node == NULL || next == NULL) {
        return 0;
    }

    next->next = node->next;
    node->next = next;

    return 1;
}

int list_insert_prev_node(ListNode *node, ListNode *prev)
{
    if (node == NULL || prev == NULL) {
        return 0;
    }

    Element elem = node->data;

    node->data = prev->data;
    
    prev->next = node->next;
    prev->data = elem;

    node->next = prev;

    return 1;
}

ListNode *list_node_create(Element elem)
{
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));

    if (node == NULL) {
        return NULL;
    }

    node->data = elem;
    node->next = NULL;

    return node;
}

int list_node_delete(LinkList list, ListNode *node)
{
    if (node == NULL) {
        return 0;
    }

    ListNode *delete;

    // 如果不是尾节点
    if (!list_node_is_tail(list, node)) {
        delete = node->next;
        node->data = delete->data;
        node->next = delete->next;

        free(delete);
    }

    ListNode *prev = list_get_prev_node(list, node);
    if (prev == NULL) {
        return 0;
    }

    prev->next = node->next;
    free(node);

    return 1;
}

ListNode *list_get_prev_node(LinkList list, ListNode *node)
{
    if (list == NULL || node == NULL) {
        return NULL;
    }

    if (list_is_empty(list)) {
        return NULL;
    }

    ListNode *prev = list;
    while (prev->next != node) {
        prev = prev->next;

        // 再次循环到头节点都没有找到，返回空
        if (prev == list) {
            return NULL;
        }
    }
    
    return prev;
}

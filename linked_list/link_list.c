/**
 * Link list data structure practice 
*/

#include "link_list.h"

int main(void)
{
    LinkList liner = NULL;
    LinkList l2 = NULL;

    if (list_init(&liner) < 1) {
        printf("List init fail");
        return -1;
    }

    if (list_init(&l2) < 1) {
        printf("List 2 init fail");
        return -1;
    }

    list_tail_create(liner);
    list_print(liner);

    list_tail_create(l2);
    list_print(l2);

    list_merge(liner, l2);
    list_print(liner);

    return 0;
}

// 初始化链表
int list_init(LinkList *liner)
{
    *liner = (LinkList) malloc(sizeof(ListNode));
    
    if (*liner == NULL) {
        return ERROR;
    }

    (*liner)->next = NULL;

    return OK;
}

// 按位查找
// O(n)
ListNode *list_get_elem(LinkList liner, int i)
{
    if (i < 1) {
        return NULL;
    }

    int j = 1; // 从第一个节点开始找
    ListNode *node = liner->next;

    // 如果就是 node, 不执行循环直接返回
    // 如果不是 再把下个节点取出
    while (j < i) {
        if (node == NULL) {
            break;
        }

        node = node->next;
        j++;
    }

    return node;
}

// 按值查找
// O(n)
ListNode *list_locate_elem(LinkList liner, Element data)
{
    if (liner == NULL) {
        return ERROR;
    }

    ListNode *node = liner->next;

    while (node != NULL && node->data.no != data.no) {
        node = node->next;
    }
    
    return node;
}

int list_length(LinkList liner)
{
    int len = 0;
    ListNode *node = liner;

    while (node != NULL && node->next != NULL) {
        node = node->next;
        len++;
    }
    
    return len;
}

// 插入到指定位置
// O(n)
int list_insert(LinkList liner, int i, Element elem)
{
    if (i < 1) {
        return ERROR;
    }

    // 处理不带头节点的链表
    if (i == 1) {
        ListNode *first = (ListNode *) malloc(sizeof(ListNode));
        first->data = elem;

        // 头节点指向 liner 指向的节点;
        // notice 指针里存放的是另一个变量的地址
        // 所以把 liner 赋值给 next，就是让 next 只想 liner 指向的变量
        first->next = liner; 
        liner = first; // 头指针指向第一个节点

        return OK;
    }

    // 找到 i 的直接前驱
    ListNode *prev = list_get_elem(liner, i - 1);

    return list_insert_next_node(prev, elem);
}

// 链表是否为空
int list_is_empty(LinkList liner)
{
    return (liner->next == NULL);
}

// 插入到指定节点之后
// O(1)
int list_insert_next_node(ListNode *node, Element elem)
{
    if (node == NULL) {
        return ERROR;
    }

    ListNode *curr = (ListNode *) malloc(sizeof(ListNode));
    if (curr == NULL) {
        return ERROR;
    }

    curr->data = elem;
    curr->next = node->next;
    node->next = curr;

    return OK;
}

// 插入到指定节点之前
// 此算法的时间复杂度为 O(n)
int list_insert_prev_node_one(LinkList liner, ListNode *node, Element elem)
{
    if (node == NULL) {
        return ERROR;
    }

    ListNode *prev = liner;

    do {
        if (prev->next == node) {
            break;
        }

        prev = prev->next;

    } while (prev != NULL);

    return list_insert_next_node(prev, elem);
}

// 把新节点插入到指定节点之前
// 这种算法的时间复杂度是 O(1)
// 创建一个新节点，把已存在节点的内容和它直接后缀的指针放到新节点中
// 再把要插入的节点内容，放到已存在节点中，已存在节点的直接后缀指向新节点
// 这样新节点就变成已存在节点，已存在节点就变成要插入节点
// 这样就把新节点插入的指定节点之前了，并且不用通过链表头一个一个的找到上一个节点
int list_insert_prev_node(ListNode *node, Element elem)
{
    if (node == NULL) {
        return ERROR;
    }

    ListNode *next = (ListNode *) malloc(sizeof(ListNode));
    next->data = node->data;
    next->next = node->next;

    node->data = elem;
    node->next = next;

    return OK;
}

void list_print(LinkList liner)
{
    for (ListNode *next = liner->next; next != NULL; next = next->next) {
        printf("ID. %d, Name %s, Score %d\n", next->data.id, next->data.name, next->data.score);
    }
}

int list_tail_create(LinkList liner)
{
    ListNode *tail, *node = NULL;
    tail = liner; // 让尾指针指向链表头节点
    int score = 0;

    do {
        Element elem;

        printf("Enter: ");
        scanf("%s %d", elem.name, &score);
        if (score < 1) {
            break;
        }

        elem.id = tail->data.id > 0 ? (tail->data.id + 1) : 1;
        elem.score = score;

        node = (ListNode *) malloc(sizeof(ListNode));
        node->data = elem;
        node->next = NULL;

        tail->next = node;
        tail = node;

    } while (score > 0);

    return OK;
}

// O(n)
int list_delete(LinkList liner, int i)
{
    if (i < 1) {
        return ERROR;
    }

    ListNode *prev = list_get_elem(liner, i - 1);

    if (prev == NULL || prev->next == NULL) {
        return ERROR;
    }

    ListNode *deleted = prev->next;
    prev->next = deleted->next;
    free(deleted);

    return OK;
}

// 找到某节点的直接前驱
int list_get_prev_node(LinkList liner, ListNode *node, ListNode *result)
{
    if (liner == NULL || node == NULL) {
        return ERROR;
    }

    ListNode *prev = liner;

    while (prev->next != node) {

        if (prev->next == NULL) {
            return ERROR;
        }

        prev = prev->next;
    }

    result = prev;

    return OK;
}

int list_delete_node(LinkList liner, ListNode *node)
{
    if (node == NULL) {
        return ERROR;
    }

    ListNode *next = node->next;

    // if the node is last node
    if (next == NULL) {

        // find the prev node for node
        if (!list_get_prev_node(liner, node, next)) {
            return ERROR;
        }

        // set the prev node next to NULL
        next->next = NULL;

        // delete node
        free(node);
    } else {
        node->data = next->data;
        node->next = next->next;
        free(next);
    }

    return OK;
}

// 两个单链表合并
// 每个链表都是从小到大排序的
// 合并到第一个链表
// O(n*m)
void list_merge(LinkList l1, LinkList l2) {
    ListNode *l1in, *l1cur, *l2cur;
    l1in  = l1;
    l1cur = l1->next;
    l2cur = l2->next;

    while (l1cur != NULL && l2cur != NULL) {
        if (l1cur->data.score <= l2cur->data.score) {
            if (l1cur->data.score == l2cur->data.score) {
                l2cur      = l2cur->next;
            }

            l1in->next = l1cur;
            l1in       = l1in->next;
            l1cur      = l1cur->next;
        } else {
            l1in->next = l2cur;
            l1in       = l1in->next;
            l2cur      = l2cur->next;
        }
    }

    l1in->next = l1cur != NULL ? l1cur : l2cur;
}

/**
 * List data structrue practice
*/

#include "list.h"

int main()
{
    List list;
    if (OVERFLOW == list_init(&list)) {
        // 'List init fail';
        return -1;
    }

    return 0;
}

Status list_init(List *list)
{
    list->data = (List *) malloc(sizeof(ElemType) * MAX_SIZE);
    
    if (!list->data) {
        return OVERFLOW;
    }

    list->length = 0;

    return OK;
}

void list_destory(List *list)
{
    if (list->length > 0) {
        free(list->data);
    }
}

void list_clear(List *list)
{
    list->length = 0;
}

int list_length(List *list)
{
    return list->length;
}

int list_is_empty(List *list)
{
    return list->length == 0 ? 1 : 0;
}

int list_elem_get(List *list, int i, ElemType *elem)
{
    if (i < 1 || i > list->length) {
        return ERROR;
    }

    *elem = list->data[i - 1];

    return OK;
}

int list_elem_locate(List *list, ElemType *elem)
{
    ElemType *temp;
    for (int i = 0; i < list->length; i++) {
        temp = &list->data[i];
        if (temp->name == elem->name && temp->age == elem->age) {
            return i + 1;
        }
    }

    return 0;
}

int list_elem_insert(List *list, int i, ElemType elem)
{
    if (i < 1 || i > (list->length + 1) || list->length == MAX_SIZE) {
        return ERROR;
    }

    for (int j = list->length; j >= i; j--) {
        list->data[j] = list->data[j - 1];
    }

    list->data[i - 1] = elem;

    list->length++;

    return OK;
}

int list_elem_delete(List *list, int i)
{
    if (i < 1 || i > list->length) {
        return ERROR;
    }

    for (int j = i - 1; j < list->length; j++) {
        list->data[j] = list->data[j + 1];
    }

    list->length--;

    return OK;
}

int list_elem_append(List *list, ElemType elem)
{
    if (list->length == MAX_SIZE) {
        return OVERFLOW;
    }

    list->data[list->length] = elem;
    list->length++;

    return OK;
}

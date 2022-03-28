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

int list_init(List *list)
{
    list->data = (List *) malloc(sizeof(Element) * MAX_SIZE);
    
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

int list_elem_get(List *list, int i, Element *elem)
{
    if (i < 1 || i > list->length) {
        return ERROR;
    }

    *elem = list->data[i - 1];

    return OK;
}

int list_elem_locate(List *list, Element *elem)
{
    for (int i = 0; i < list->length; i++) {
        Element *temp = &list->data[i];
        if (temp->name == elem->name && temp->age == elem->age) {
            return i + 1;
        }
    }

    return 0;
}

int list_elem_search(List *list, int key) {
    int low     = 0;
    int hight   = list->length;
    int mid     = (low + hight) / 2;
    int mid_key = list->data[mid].key;

    while (low <= hight) {
        mid     = (low + hight) / 2;
        mid_key = list->data[mid].key;

        if (mid_key == key) {
            return mid;
        } else if (key > mid_key) {
            low = mid + 1;
        } else {
            hight = mid - 1;
        }
    }

    return -1;
}

// 插入排序
// 时间O(n*n)
void insert_sort(List *list) {
    int i, j;
    // 从第2个元素开始比较
    // 第2个元素和第一个元素比较
    for (i = 2; i <= list->length; i++) {
        // 如果后一个元素小于前一个元素
        // 就把前一个元素当作哨兵
        if (list->data[i].key < list->data[i-1].key) {
            // 当前 i 当为哨兵
            list->data[0] = list->data[i];
            for (j = i - 1; list->data[0].key < list->data[j].key; j--) {
                // 元素后移
                list->data[j+1] = list->data[j];
            }

            // 如果当前元素比哨兵小
            // 就把哨兵插入到当前元素之后
            list->data[j+1] = list->data[0];
        }
    }
}

// 冒泡排序
void bubble_sort(List *list) {
    int i, j, z = list->length, len = list->length;
    Element temp_elem;

    // 外层循环表示需要比较的趟数
    // 如果一共 7 个元素
    // 那么需要比较 6 趟
    for (i = 1; i < len; i++) {

        // 内层循环表示每趟需要比较的次数
        // 第 1 趟需要比较 6 次 1+6=7
        // 第 1 趟后 最后那个元素就是最大的了, 下一次就不需要比较了
        // 第 2 趟需要比较 5 次 2+5=7
        // 因此每一趟需要比较的次数就是 n(元素个数)-m(第几趟)=每趟的比较次数
        for (j = 0; j < len - i; j++) {
            if (list->data[j].key > list->data[j+1].key) {
                temp_elem = list->data[j+1];
                list->data[j+1] = list->data[j];
                list->data[j] = temp_elem;
            }
        }
    }
}

// 冒泡排序改进版
// 添加了 flag 表示某趟是否交换了元素
// 如果没有，就表示已经是排好的顺序
// 后面的趟就不用再执行了
void bubble_flag_sort(List *list) {
    int i, j, flag = 1, z = list->length, len = list->length;
    Element temp_elem;

    // 外层循环表示需要比较的趟数
    // 如果一共 7 个元素
    // 那么需要比较 6 趟
    for (i = 1; i < len && flag == 1; i++) {

        // 每趟执行时都先设为 0 表示没有交换
        flag = 0;

        // 内层循环表示每趟需要比较的次数
        // 第 1 趟需要比较 6 次 1+6=7
        // 第 1 趟后 最后那个元素就是最大的了, 下一次就不需要比较了
        // 第 2 趟需要比较 5 次 2+5=7
        // 因此每一趟需要比较的次数就是 n(元素个数)-m(第几趟)=每趟的比较次数
        for (j = 0; j < len - i; j++) {
            if (list->data[j].key > list->data[j+1].key) {
                
                // 如果发生交换了就设为 1
                flag = 1;

                temp_elem = list->data[j+1];
                list->data[j+1] = list->data[j];
                list->data[j] = temp_elem;
            }
        }
    }
}

// 简单选择排序
void select_sort(List *list) {
    int i, j;
    // 最小的位置
    int smallest_index = 0;

    // 要执行 n-1 趟
    for (i = 0; i < list->length - 1; i++) {

        smallest_index = i;

        // 第 1 趟 把第1个元素之后的元素都和第1个比较找到最小的位置
        // 第 2 趟 把第2个元素之后的元素都和第2个比较找到最小的位置
        // etc.
        for (j = i + 1; j < list->length; j++) {
            if (list->data[j].key < list->data[smallest_index].key) {
                smallest_index = j;
            }
        }

        // 如果最小的位置不是自身
        // 就交换
        if (smallest_index != i) {
            list->data[i] = list->data[smallest_index];
        }
    }
}

int list_elem_insert(List *list, int i, Element elem)
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

int list_elem_append(List *list, Element elem)
{
    if (list->length == MAX_SIZE) {
        return OVERFLOW;
    }

    list->data[list->length] = elem;
    list->length++;

    return OK;
}

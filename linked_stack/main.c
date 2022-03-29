#include "head.h"

int main(void) {
    LinkStack stack;

    stack_init(&stack);

    Element luff = {"Luff"};
    stack_push(stack, &luff);

    Element rose = {"Rose"};
    stack_push(stack, &rose);

    Element joy = {"Joy"};
    stack_push(stack, &joy);

    stack_printf(stack);

    StackNode *stack_top = stack_pop(stack);
    printf("Hi %s\n", stack_top->data.name);

    stack_printf(stack);

    return 0;
}

int stack_init(LinkStack *stack) {
    *stack = (StackNode *) malloc(sizeof(StackNode));

    if (*stack == NULL) {
        return 0;
    }

    (*stack)->next = NULL;

    return 1;
}

int stack_is_empty(LinkStack stack) {
    if (stack == NULL || stack->next == NULL) {
        return 1;
    }

    return 0;
}

// 头插法
int stack_push(LinkStack stack, Element *elem) {
    if (stack == NULL) {
        return 0;
    }

    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    node->data = *elem;
    node->next = stack->next;

    stack->next = node;

    return 1;
}

StackNode *stack_pop(LinkStack stack) {
    if (stack_is_empty(stack)) {
        return NULL;
    }

    StackNode *node = stack->next;

    stack->next = node->next;

    return node;
}

StackNode *stack_top(LinkStack stack) {
    return stack->next;
}

void stack_printf(LinkStack stack) {
    while (stack->next != NULL) {
        printf("Hi %s\n", stack->next->data.name);
        stack = stack->next;
    }
}

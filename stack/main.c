#include "head.h"

int main(void)
{
    stack_t stack;

    stack_init(&stack);

    Element luff = {"Luff"};
    stack_push(&stack, &luff);

    Element rose = {"Rose"};
    stack_push(&stack, &rose);

    stack_print(&stack);

    Element rosePop;
    stack_pop(&stack, &rosePop);
    printf("Hi %s\n", rosePop.name);
    printf("Now the top is %d\n", stack.top);

    Element luffTop;
    stack_top(&stack, &luffTop);
    printf("Hi %s\n", luffTop.name);
    printf("Now the top is %d\n", stack.top);

    return 0;
}

void stack_init(stack_t *stack)
{
    stack->top = MAX_SIZE;
}

int stack_is_empty(stack_t *stack)
{
    return stack->top == MAX_SIZE;
}

int stack_is_full(stack_t *stack)
{
    return stack->top == 0;
}

int stack_push(stack_t *stack, Element *elem)
{
    // 已经是栈底
    if (stack_is_full(stack)) {
        return -1;
    }

    stack->data[--stack->top] = *elem;

    return 0;
}

int stack_pop(stack_t *stack, Element *elem)
{
    if (stack_is_empty(stack)) {
        return 0;
    }

    *elem = stack->data[stack->top++];

    return 1;
}

int stack_top(stack_t *stack, Element *elem)
{
    if (stack_is_empty(stack)) {
        return 0;
    }

    *elem = stack->data[stack->top];

    return 1;
}

void stack_print(stack_t *stack)
{
    for (int i = stack->top; i < MAX_SIZE; i++) {
        printf("My name is %s => at index %d\n", stack->data[i].name, i);
    }

    printf("The stack top is %d\n", stack->top);
}

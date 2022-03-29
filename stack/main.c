#include "head.h"

int main(void) {
    const char *str = "class User { "
        "public function __construct() {} "
        "public function getName() {} "
    "}}";
    
    if (bracket_check(str, strlen(str))) {
        printf("Success\n");
    } else {
        printf("Fail\n");
    }

    return 0;
}

// 括号匹配检测
// 一个左括号, 紧邻它的右括号必须是和它一样类型的括号
// 如 ( 左圆括号，下一个右括号，必须是 右圆括号 )
int bracket_check(const char *str, int length) {
    printf("%s, len = %d\n", str, length);

    stack_t stack;
    stack_init(&stack);

    for (int i = 0; i < length; i++) {

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack_push_char(&stack, str[i]);
        } else {
            if (str[i] == ')' || str[i] == ']' || str[i] == '}') {

                if (stack_is_empty(&stack)) {
                    return 0;
                }

                char except = stack_pop_char(&stack);
                printf("%c = %c\n", except, str[i]);

                if (str[i] == ')' && '(' != except) {
                    return 0;
                } else if (str[i] == ']' && '[' != except) {
                    return 0;
                } else if (str[i] == '}' && '{' != except) {
                    return 0;
                }
            }
        }
    }
    
    stack_print(&stack);

    return stack_is_empty(&stack);
}

void stack_init(stack_t *stack) {
    stack->top = MAX_SIZE;
}

int stack_is_empty(stack_t *stack) {
    return stack->top == MAX_SIZE;
}

int stack_is_full(stack_t *stack) {
    return stack->top == 0;
}

int stack_push_char(stack_t *stack, char c) {
    Element elem = {c};

    return stack_push(stack, &elem);
}

int stack_push(stack_t *stack, Element *elem) {
    // 已经是栈底
    if (stack_is_full(stack)) {
        return 0;
    }

    stack->data[--stack->top] = *elem;

    return 1;
}

char stack_pop_char(stack_t *stack) {
    if (stack_is_empty(stack)) {
        return '\0';
    }

    return stack->data[stack->top++].name;
}

int stack_pop(stack_t *stack, Element *elem) {
    if (stack_is_empty(stack)) {
        return 0;
    }

    *elem = stack->data[stack->top++];

    return 1;
}

int stack_top(stack_t *stack, Element *elem) {
    if (stack_is_empty(stack)) {
        return 0;
    }

    *elem = stack->data[stack->top];

    return 1;
}

void stack_print(stack_t *stack) {
    for (int i = stack->top; i < MAX_SIZE; i++) {
        printf("My name is %c => at index %d\n", stack->data[i].name, i);
    }

    printf("The stack top is %d\n", stack->top);
}

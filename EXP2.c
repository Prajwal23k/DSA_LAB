#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

void push(struct Stack *stack, char value) {
    if (stack->top != MAX - 1){
        stack->arr[++stack->top] = value;
    }
}

char pop(struct Stack *stack) {
    if (stack->top != -1){
        return stack->arr[stack->top--];
    }
    return -1;
}

char peek(struct Stack *stack) {
    if (stack->top != -1)
        return stack->arr[stack->top];
    return -1;
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    struct Stack stack;
    stack.top=-1;
    int i;
    int k = 0;
    for (i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.top != -1 && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);
        } else if (isOperator(infix[i])) {
            while (stack.top != -1 && precedence(infix[i]) <= precedence(peek(&stack))) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    while (stack.top != -1) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int stack[MAX];
    int top;
};

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
    	s->top++;
        s->stack[s->top] = value;  
        printf("%d pushed to stack\n", value);
    }
}

void pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
    } else {
    	printf("Popped value: %d\n", s->stack[s->top]);
    	s->top--;  
    }
}




int peek(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        printf("Top value: %d\n", s->stack[s->top]);  
    }
}


void display(struct Stack* s) {
	int i;
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for ( i = s->top; i >= 0; i--) {
            printf("%d\n", s->stack[i]);  
        }
    }
}

void main() {
    struct Stack s;  
    s.top = -1;  
    int ch, val;
    
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &val);
                push(&s, val);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    
}


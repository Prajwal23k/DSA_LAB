#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
   struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = top;
   top = newNode;
}

void pop() {
	struct Node *temp = top;
   if (top == NULL) {
       printf("Stack Underflow\n");
   }
   else{
   	printf("Popped Element : %d\n",top->data);
   	top=top->next;
   	free(temp);
	}
}

void peek() {
   if (top == NULL) {
       printf("Stack is empty\n");
   }
   else{
   	printf("Top Element : %d\n",top->data);
	}
}

void display() {
   struct Node *temp = top;
   printf("Stack Data :\n");
   if(top==NULL)
   {
   	printf("Stack is Empty\n");
	}
	else{
			while (temp != NULL) {
	        printf("%d \n", temp->data);
	        temp = temp->next;
	    }
	}
   
}

int main() {
	int ch,val;
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
               push(val);
               break;
           case 2:
               pop();
               break;
           case 3:
               peek();
               break;
           case 4:
               display();
               break;
           case 5:
               exit(0);
           default:
               printf("Invalid\n");
       }
   }
}

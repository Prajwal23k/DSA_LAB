#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int queue[MAX];
    int front;
    int rear;
};

void enqueue(struct Queue *q, int val) {
    if (q->rear==MAX-1) {
        printf("Queue Overflow\n");
    } else{
    	if (q->front==-1 && q->rear==-1) {
		q->front=q->rear=0;
		q->queue[q->rear]=val;
    	} else {
    	q->rear++;
    	q->queue[q->rear]=val; 
		}
	}
}

void dequeue(struct Queue *q) {
    if (q->front==-1 && q->rear==-1) {
        printf("Queue Underflow\n");
    } else{
    	if(q->front==q->rear) {
		printf("Dequed Value : %d\n",q->queue[q->front]);
		q->front=q->rear=-1;
    	} else {
    	printf("Dequed Value : %d\n",q->queue[q->front]);
    	q->front++;
    	}
	}
}

void peek(struct Queue *q) {
    if (q->front==-1 && q->rear==-1) {
        printf("Queue is empty\n");
    } else {
        printf("Top Element : %d\n ",q->queue[q->front]);
    }
}

void display(struct Queue *q) {
	int i;
    if (q->front==-1 && q->rear==-1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        int i;
        for (i = q->front; i <= q->rear; i++) {
            printf("%d\n", q->queue[i]);
        }
    }
}
void main() {
    struct Queue q;
    int ch, val;
    q.front = -1;
    q.rear = -1;
    
    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);                
                break;
            case 4:
                display(&q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    
}


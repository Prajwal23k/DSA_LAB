#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct CQ {
    int cq[MAX];
    int front;
    int rear;
};
	

void enqueue(struct CQ *q, int val) {
    if ((q->rear+1)%MAX==q->front) {
        printf("Queue Overflow\n");
    } else {
		if(q->front==-1 && q->rear==-1){
			q->front=q->rear=0;
			q->cq[q->rear]=val;
		}
		else{
			q->rear=(q->rear+1)%MAX;
			q->cq[q->rear]=val;
		}
    }
}

void dequeue(struct CQ *q) {
    if (q->front==-1 && q->rear==-1) {
        printf("Queue Underflow\n");
    } else {
		if(q->front==q->rear){
			printf("Dequeued Element : %d\n",q->cq[q->front]);
			q->front=q->rear=-1;
		}
		else{
			printf("Dequeued Element : %d\n",q->cq[q->front]);
			q->front=(q->front+1)%MAX;
		}
    }
}

void peek(struct CQ *q) {
    if (q->front==-1 && q->rear==-1) {
        printf("Queue is empty\n");
    } else {
        printf("Front : %d" ,q->cq[q->front]);
    }
}

void display(struct CQ *q) {
	int i=q->front;
    if (q->front==-1 && q->rear==-1) {
        printf("Queue is empty\n");
    } else {
	        printf("Queue elements are:\n");
			while(i!=q->rear){
				printf("%d\n",q->cq[i]);
				i=(i+1)%MAX;
			}
			printf("%d\n",q->cq[q->rear]);
        }
}

void main() {
    struct CQ q;
    int ch, value;
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
                scanf("%d", &value);
                enqueue(&q, value);
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

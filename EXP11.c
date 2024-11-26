#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int vertices;       
    int adj[MAX][MAX];  
};

struct Queue {
    int items[MAX];
    int front, rear;
};

struct Stack {
    int items[MAX];
    int top;
};

void initializeGraph(struct Graph* g, int vertices) {
	int i,j;
    g->vertices = vertices;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1;  
}

void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;  
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) return -1;
    return q->items[q->front++];
}

void bfs(struct Graph* g, int start) {
	int i;
    int visited[MAX] = {0};
    struct Queue q;
    initializeQueue(&q);

    enqueue(&q, start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (i = 0; i < g->vertices; i++) {
            if (g->adj[current][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void initializeStack(struct Stack* s) {
    s->top = -1;
}

int isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) return;  
    s->items[++s->top] = value;
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) return -1;
    return s->items[s->top--];
}

void dfs(struct Graph* g, int start) {
	int i;
    int visited[MAX] = {0};
    struct Stack s;
    initializeStack(&s);

    push(&s, start);

    printf("DFS Traversal: ");
    while (!isStackEmpty(&s)) {
        int current = pop(&s);

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (i = g->vertices - 1; i >= 0; i--) {  
                if (g->adj[current][i] == 1 && !visited[i]) {
                    push(&s, i);
                }
            }
        }
    }
    printf("\n");
}

void main() {
    struct Graph g;
    int vertices = 6;

    initializeGraph(&g, vertices);
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 5);

    printf("Graph Traversals:\n");
    bfs(&g, 0);
    dfs(&g, 0);
}


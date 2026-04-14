/* 
 Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node *front, *rear;
};
struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}
void enqueue(struct Queue* q, int k) {
    struct Node* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }
    
    struct Node* temp = q->front;
    printf("%d\n", temp->data);
    
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;

    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);

        if (operation == 1) { 
            int value;
            scanf("%d", &value);
            enqueue(q, value);
        } else if (operation == 2) { 
            dequeue(q);
        }
    }

    return 0;
}
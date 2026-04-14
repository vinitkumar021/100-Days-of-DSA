/*
 Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->rear = NULL;
    return q;
}


void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    
    if (q->rear == NULL) {
        
        temp->next = temp;
        q->rear = temp;
    } else {
        
        temp->next = q->rear->next;
        
        q->rear->next = temp;
        q->rear = temp;
    }
}

void dequeue(struct Queue* q) {
    if (q->rear == NULL) return;

    struct Node* front = q->rear->next;
    
    if (front == q->rear) {
        free(front);
        q->rear = NULL;
    } else {
        q->rear->next = front->next;
        free(front);
    }
}
void display(struct Queue* q) {
    if (q->rear == NULL) return;

    struct Node* temp = q->rear->next; 
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != q->rear->next) printf(" ");
    } while (temp != q->rear->next);
    printf("\n");
}

int main() {
    int n, m, value;
    struct Queue* q = createQueue();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        dequeue(q);
    }
    display(q);

    return 0;
}
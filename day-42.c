/*
 Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void enqueue(struct Node** front, struct Node** rear, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) return -1;
    struct Node* temp = *front;
    int data = temp->data;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return data;
}
void push(struct Node** top, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = *top;
    *top = temp;
}

int pop(struct Node** top) {
    if (*top == NULL) return -1;
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int main() {
    int n, val;
    struct Node *qFront = NULL, *qRear = NULL;
    struct Node *stackTop = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&qFront, &qRear, val);
    }
    while (qFront != NULL) {
        push(&stackTop, dequeue(&qFront, &qRear));
    }
    while (stackTop != NULL) {
        enqueue(&qFront, &qRear, pop(&stackTop));
    }
    struct Node* curr = qFront;
    while (curr != NULL) {
        printf("%d%s", curr->data, curr->next ? " " : "");
        curr = curr->next;
    }
    printf("\n");

    return 0;
}
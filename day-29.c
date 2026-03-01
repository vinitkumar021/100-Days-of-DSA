/*
  Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || n == 0) return head;
    k = k % n;
    if (k == 0) return head;


    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head; 
    struct Node* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {
        newTail = newTail->next;
    }
    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    int n, k, val;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);
    head = rotateRight(head, k, n);

    struct Node* temp = head;
    while (temp) {
        printf("%d%s", temp->data, temp->next ? " " : "");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
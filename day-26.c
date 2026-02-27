/*
  Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) {
            printf(" ");
        }
        curr = curr->next;
    }
    printf("\n");

    curr = head;
    while (curr != NULL) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
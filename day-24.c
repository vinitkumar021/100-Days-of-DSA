/*
   Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    if (head == NULL) return NULL;

    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        if (current->next->data == key) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return head; 
        }
        current = current->next;
    }

    return head;
}

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, val, key;
    struct Node *head = NULL, *tail = NULL;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &key);
    head = deleteFirstOccurrence(head, key);
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d%c", curr->data, curr->next ? ' ' : '\n');
        curr = curr->next;
    }
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
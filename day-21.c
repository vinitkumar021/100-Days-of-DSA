/* 
 Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, value;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode; 
            temp = head;
        } else {
            temp->next = newNode; 
            temp = temp->next;    
        }
    }
    struct Node* current = head;
    while (current != NULL) {
        printf("%d%s", current->data, (current->next ? " " : ""));
        current = current->next;
    }
    printf("\n");
    while (head != NULL) {
        struct Node* nextNode = head->next;
        free(head);
        head = nextNode;
    }

    return 0;
}
/*
  Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy; 
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head1) head1 = tail1 = newNode;
        else { tail1->next = newNode; tail1 = newNode; }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head2) head2 = tail2 = newNode;
        else { tail2->next = newNode; tail2 = newNode; }
    }
    struct Node* result = mergeLists(head1, head2);
    while (result) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* buildList(int size) {
    if (size == 0) return NULL;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        scanf("%d", &(newNode->data));
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void findIntersection(Node* head1, int n, Node* head2, int m) {
    Node *ptr1 = head1, *ptr2 = head2;
    int diff = (n > m) ? (n - m) : (m - n);
    if (n > m) {
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    Node* head1 = buildList(n);
    if (scanf("%d", &m) != 1) return 0;
    Node* head2 = buildList(m);

    findIntersection(head1, n, head2, m);

    return 0;
}
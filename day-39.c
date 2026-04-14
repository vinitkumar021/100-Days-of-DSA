/*
 Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100005

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}
void heapifyDown(int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int extractMin() {
    if (size == 0) return -1;
    
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    
    if (size > 0) {
        heapifyDown(0);
    }
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "peek") == 0) {
            int result = peek();
            printf("%d\n", result);
        } else if (strcmp(op, "extractMin") == 0) {
            int result = extractMin();
            printf("%d\n", result);
        }
    }

    return 0;
}
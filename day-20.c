/*
 Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.
*/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100003

typedef struct Node {
    long long sum;
    int count;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];
int hash(long long sum) {
    int h = sum % TABLE_SIZE;
    return (h < 0) ? h + TABLE_SIZE : h;
}

void insert(long long sum) {
    int h = hash(sum);
    Node* temp = hashTable[h];
    while (temp) {
        if (temp->sum == sum) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->count = 1;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

int getCount(long long sum) {
    int h = hash(sum);
    Node* temp = hashTable[h];
    while (temp) {
        if (temp->sum == sum) return temp->count;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long current_sum = 0;
    long long zero_sum_subarrays = 0;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        current_sum += val;
        if (current_sum == 0) {
            zero_sum_subarrays++;
        }
        zero_sum_subarrays += getCount(current_sum);
        insert(current_sum);
    }

    printf("%lld\n", zero_sum_subarrays);

    return 0;
}
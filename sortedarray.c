/*
Remove Duplicates from Sorted Array

Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/
#include <stdio.h>
#include <stdlib.h>

void remove_duplicates() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    for (int k = 0; k <= i; k++) {
        printf("%d%s", arr[k], (k == i ? "" : " "));
    }
    printf("\n");

    free(arr);
}

int main() {
    remove_duplicates();
    return 0;
}
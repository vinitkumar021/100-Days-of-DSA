/*
 Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1
*/
#include <stdio.h>
#include <limits.h>

void countFrequency(int arr[], int n) {
    int visited = INT_MIN; 

    for (int i = 0; i < n; i++) {
        if (arr[i] != visited) {
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = visited; 
                }
            }
            printf("%d:%d ", arr[i], count);
        }
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countFrequency(arr, n);

    return 0;
}
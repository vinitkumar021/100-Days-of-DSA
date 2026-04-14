/*
 Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Node {
    int data;
    struct Node* next;
};


void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Error\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        
        if (exp[i] == ' ') continue;

        
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--; 
            push(&stack, num);
        } 
        
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[] = "2 3 1 * + 9 -";
    printf("Output: %d\n", evaluatePostfix(exp));
    return 0;
}
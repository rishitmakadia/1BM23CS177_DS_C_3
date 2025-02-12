#include <stdio.h>

#define MAX 10

int top1 = -1;           // Top pointer for Stack 1
int top2 = MAX;          // Top pointer for Stack 2

// Push to Stack 1
void push1(int twoStack[], int x) {
    if (top1 < top2 - 1) {
        twoStack[++top1] = x;
    } else {
        printf("Stack Overflow for Stack 1\n");
    }
}

// Push to Stack 2
void push2(int twoStack[], int x) {
    if (top1 < top2 - 1) {
        twoStack[--top2] = x;
    } else {
        printf("Stack Overflow for Stack 2\n");
    }
}

// Pop from Stack 1
int pop1(int twoStack[]) {
    if (top1 >= 0) {
        return twoStack[top1--];
    } else {
        printf("Stack Underflow for Stack 1\n");
        return -1;
    }
}

// Pop from Stack 2
int pop2(int twoStack[]) {
    if (top2 < MAX) {
        return twoStack[top2++];
    } else {
        printf("Stack Underflow for Stack 2\n");
        return -1;
    }
}

// Display Stack 1
void display1(int twoStack[]) {
    printf("Stack 1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", twoStack[i]);
    }
    printf("\n");
}

// Display Stack 2
void display2(int twoStack[]) {
    printf("Stack 2: ");
    for (int i = MAX - 1; i >= top2; i--) {
        printf("%d ", twoStack[i]);
    }
    printf("\n");
}

int main() {
    int twoStack[MAX];

    // Example operations
    push1(twoStack, 5);
    push1(twoStack, 10);
    push2(twoStack, 20);
    push2(twoStack, 30);
    
    printf("After pushes:\n");
    display1(twoStack);
    display2(twoStack);

    printf("Popped from Stack 1: %d\n", pop1(twoStack));
    printf("Popped from Stack 2: %d\n", pop2(twoStack));

    printf("After pops:\n");
    display1(twoStack);
    display2(twoStack);

    return 0;
}

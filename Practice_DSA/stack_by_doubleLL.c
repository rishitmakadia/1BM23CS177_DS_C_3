#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Push operation to insert an element at the top of the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *top;

    if (*top != NULL) {
        (*top)->prev = newNode;
    }

    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

// Pop operation to remove and return the top element of the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! Unable to pop.\n");
        return -1;
    }

    struct Node* temp = *top;
    int value = temp->data;

    *top = (*top)->next;
    if (*top != NULL) {
        (*top)->prev = NULL;
    }

    free(temp);
    printf("Popped %d from the stack.\n", value);
    return value;
}

// Display the contents of the stack from top to bottom
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (Top to Bottom):\n");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the stack operations
int main() {
    struct Node* stack = NULL;
    int choice, value;

    while (1) {
        printf("\nStack Operations using Doubly Linked List:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                display(stack);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

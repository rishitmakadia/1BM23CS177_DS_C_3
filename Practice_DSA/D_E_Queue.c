#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the deque

int deque[MAX];
int front = -1;
int rear = -1;

// Function to insert an element at the front
void insertFront(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Deque is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX; // Wrap around
    }
    deque[front] = value;
} 

// Function to insert an element at the rear
void insertRear(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Deque is full!\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX; // Wrap around
    }
    deque[rear] = value;
}

// Function to delete an element from the front
int deleteFront() {
    if (front == -1) {
        printf("Deque is empty!\n");
        return -1; // Indicates failure
    }
    int value = deque[front];
    if (front == rear) {
        // Queue is now empty after this deletion
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX; // Wrap around
    }
    return value;
}

// Function to delete an element from the rear
int deleteRear() {
    if (front == -1) {
        printf("Deque is empty!\n");
        return -1; // Indicates failure
    }
    int value = deque[rear];
    if (front == rear) {
        // Queue is now empty after this deletion
        front = -1;
        rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX; // Wrap around
    }
    return value;
}

// Function to display the deque elements
void display() {
    if (front == -1) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) 
            break;
        i = (i + 1) % MAX; // Wrap around
    }
    printf("\n");
}

// Main function to demonstrate deque operations
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display(); // Should display 5 10 20

    printf("Deleted from front: %d\n", deleteFront()); // Should delete 5
    display(); // Should display 10 20

    printf("Deleted from rear: %d\n", deleteRear()); // Should delete 20
    display(); // Should display 10

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];  // Queue to store data
int priority[MAX];  // Priority array corresponding to each data

// Function to insert an element in ascending priority order
void enqueue(int queue[], int priority[], int *rear, int data, int prio) {
    if (*rear == MAX - 1) {
        printf("Priority Queue is full!\n");
        return;
    }

    int i;
    // Find correct position for insertion based on priority
    for (i = *rear; i >= 0 && priority[i] > prio; i--) {
        queue[i + 1] = queue[i];          // Shift data
        priority[i + 1] = priority[i];    // Shift priority
    }

    queue[i + 1] = data;
    priority[i + 1] = prio;
    (*rear)++;
}

// Function to remove the element with the highest priority (smallest value)
void dequeue(int queue[], int priority[], int *rear) {
    if (*rear == -1) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Dequeued Element: Data = %d, Priority = %d\n", queue[0], priority[0]);

    // Shift all elements to the left
    for (int i = 1; i <= *rear; i++) {
        queue[i - 1] = queue[i];
        priority[i - 1] = priority[i];
    }
    (*rear)--;
}

// Function to display the priority queue
void display(int queue[], int priority[], int rear) {
    if (rear == -1) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue (Data, Priority):\n");
    for (int i = 0; i <= rear; i++) {
        printf("(%d, %d) ", queue[i], priority[i]);
    }
    printf("\n");
}

int main() {
    int rear = -1;  // Tracks the last element in the queue
    int choice, data, prio;

    while (1) {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &prio);
                enqueue(queue, priority, &rear, data, prio);
                break;
            case 2:
                dequeue(queue, priority, &rear);
                break;
            case 3:
                display(queue, priority, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

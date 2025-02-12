// Consider that you are adding a functionality used in switching between applications and programs (Alt + Tab) in the Operating system implement the same using Circular Linked List.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store application details
typedef struct App {
    char name[50];
    struct App* next;
} App;

App* head = NULL;  // Circular linked list head
App* current = NULL; // Pointer to track the current application

// Function to add a new application to the circular linked list
void addApplication(char appName[]) {
    App* newApp = (App*)malloc(sizeof(App));
    if (newApp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newApp->name, appName);
    newApp->next = NULL;

    if (head == NULL) {
        head = newApp;
        newApp->next = head;  // Point to itself (circular)
    } else {
        App* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newApp;
        newApp->next = head;
    }

    // If first app, set current pointer
    if (current == NULL) {
        current = head;
    }

    printf("Application '%s' added successfully!\n", appName);
}

// Function to switch to the next application (Alt + Tab)
void switchApplication() {
    if (current == NULL) {
        printf("No applications are open.\n");
        return;
    }

    current = current->next;  // Move to the next application
    printf("Switched to application: %s\n", current->name);
}

// Function to display the list of applications
void displayApplications() {
    if (head == NULL) {
        printf("No applications are open.\n");
        return;
    }

    printf("\nOpen Applications:\n");
    App* temp = head;

    do {
        printf("- %s\n", temp->name);
        temp = temp->next;
    } while (temp != head);

    printf("--------------------\n");
}

// Main function to simulate the Alt + Tab functionality
int main() {
    int choice;
    char appName[50];

    while (1) {
        printf("\nAlt + Tab Simulation\n");
        printf("1. Add Application\n");
        printf("2. Switch Application (Alt + Tab)\n");
        printf("3. Show Open Applications\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter Application Name: ");
                fgets(appName, sizeof(appName), stdin);
                appName[strcspn(appName, "\n")] = '\0'; // Remove trailing newline
                addApplication(appName);
                break;

            case 2:
                switchApplication();
                break;

            case 3:
                displayApplications();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

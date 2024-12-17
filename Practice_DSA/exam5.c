#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[15];
    struct Node *next;
} Node;

void insertEnd(Node **head, char n[]) {
    Node *newN = (Node *)malloc(sizeof(Node));
    strcpy(newN->name, n);
    newN->next = NULL;

    if (*head == NULL) {
        *head = newN;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newN;
}

void findWebpage(Node *head, int x) {
    Node *temp = head;

    for (int i = 1; i < x && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        printf("Webpage after %d clicks: %s\n", x, temp->name);
    } else {
        printf("Invalid number of clicks: %d\n", x);
    }
}

// Function to display the entire list (for debugging or visualization)
void display(Node *head) {
    if (head == NULL) {
        printf("No webpages visited.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int n, x;
    char webpage[50];

    printf("Enter the number of webpages: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter webpage name %d: ", i + 1);
        scanf("%s", webpage);
        insertEnd(&head, webpage);
    }

    printf("Enter the number of clicks: ");
    scanf("%d", &x);

    findWebpage(head, x);

    // Optional: Display the entire list
    printf("All visited webpages: ");
    display(head);

    return 0;
}
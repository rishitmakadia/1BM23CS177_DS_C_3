#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char name[15];
    struct Node *next;
} Node;

void insertBeg(Node **head, char n[])
{
    Node *newN = (Node *)malloc(sizeof(Node));
    strcpy(newN->name, n);
    newN->next = (*head);
    *head = newN;
}

void deleteBeg(Node **head)
{
    if (*head == NULL)
    {
        printf("Record Book is Empty");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteLast(Node **head){
    if (*head == NULL){
        printf("Empty");
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next!=NULL){
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = NULL;
    free(temp);
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Record Book is Empty\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("Name: %s\n", temp->name);
        temp = temp->next;
    }
}

// Main function
int main()
{
    Node *head = NULL; // Initialize the linked list as empty
    int choice;
    char name[15];
    printf("1. Insert\t2. Deletion\t3. Display\t4. Exit");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter name: ");
            scanf("%s", name);
            insertBeg(&head, name);
            break;
        case 2:
            deleteBeg(&head);
            break;
        case 3:
            deleteLast(&head);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
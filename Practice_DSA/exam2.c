#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[15], usn[15];
    int PNo;
    struct Node *next;
} Node;

void insertBeg(Node **head, char n[], char u[], int no)
{
    Node *newN = (Node *)malloc(sizeof(Node));
    strcpy(newN->name, n);
    strcpy(newN->usn, u);
    newN->PNo = no;
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
        printf("\n%s", temp->name);
        printf("\n%s", temp->usn);
        printf("\n%d", temp->PNo);
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    int opt, no;
    char s[15], n[15];
    printf("1. Insert\t2. Deletion\t3. Display\t4. Exit");
    while (1)
    {
        printf("\nSelect Option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Name : ");
            scanf(" %s", n);
            printf("USN : ");
            scanf(" %s", s);
            printf("Phone Number : ");
            scanf("%d", &no);
            insertBeg(&head, n, s, no);
            break;
        case 2:
            deleteBeg(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            return (0);
        default:
            printf("Error ");
            break;
        }
    }
}
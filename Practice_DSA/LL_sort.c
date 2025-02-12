// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node
// {
//     int no;
//     struct Node *next;
// } Node;

// void insertBeg(Node **head, int n)
// {
//     Node *newN = (Node *)malloc(sizeof(Node));
//     newN->no = n;
//     newN->next = (*head);
//     *head = newN;
// }

// void sort(Node **head)
// {
//     if (*head == NULL){
//         printf("Empty");
//         return;
//     }
//     Node *temp = *head;
//     if (temp1->next == NULL){
//         return head;
//     }
//     while (temp->next!=NULL){
//         if ((temp->no)<(temp->next->no)){
//             int temp1 = temp->no;
//             temp->no = temp->next->no;
//             temp->next->no = temp1;
//         }
//         else if((temp->no)<(temp->next->no)){
//             Node *del = temp->next;
//             temp->next = temp->next->next;
//             free(del);
//         }
//         temp = temp->next;
//     }
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int no;
    struct Node *next;
} Node;

// Insert a node at the beginning
void insertBeg(Node **head, int n) {
    Node *newN = (Node *)malloc(sizeof(Node));
    newN->no = n;
    newN->next = (*head);
    *head = newN;
}

// Sort the linked list
void sort(Node **head) {
    if (*head == NULL) {
        return;
    }
    Node *current, *index;
    int temp;

    for (current = *head; current != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->no > index->no) {
                temp = current->no;
                current->no = index->no;
                index->no = temp;
            }
        }
    }
}

// Remove duplicates from the sorted list
void removeDuplicates(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *current = head;

    while (current->next != NULL) {
        if (current->no == current->next->no) {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

// Display the linked list
void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->no);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    // Insert elements
    insertBeg(&head, 5);
    insertBeg(&head, 3);
    insertBeg(&head, 5);
    insertBeg(&head, 2);
    insertBeg(&head, 3);

    printf("Original List:\n");
    display(head);

    // Sort the list
    sort(&head);

    printf("Sorted List:\n");
    display(head);

    // Remove duplicates
    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    display(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to create a doubly linked list
// struct Node* createList(int data) {
//     return createNode(data);
// }
// Function to create a new list with a single node
void createList(struct Node** head, int data) {
    *head = createNode(data);
}


// Function to insert a new node to the left of a specific node
void insertLeft(struct Node** head, int target, int data) {
    if (*head==NULL){
        printf("No Linked List Exist");
        return;
    }
    struct Node* temp = *head;
    struct Node* newNode = createNode(data);
    
    while (temp!= NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp==NULL) {
        printf("Node with value %d not found.", target);
        free(newNode);
        return;
    }

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;  // Update head if the new node is inserted at the beginning
    }

    temp->prev = newNode;
}

// Function to delete a node based on a specific value
void deleteNode(struct Node** head, int target) {
    struct Node* temp = *head;
    while (temp!= NULL && temp->data != target) {
        temp = temp->next;
    }

    if (!temp) //temp==NULL
    {
        printf("Node with value %d not found.\n", target);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;  // Update head if the node to delete is the first node
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to display the contents of the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    // printf("\n");
}

int main(){
    struct Node *head = NULL;
    int choice, data, pos;
    printf("\n1. Create a new LL\t2. Insert Left to\t3. Delete by value\t4. Display\t5. Exit\t\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                createList(&head, data);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                printf("Enter to the left of value: ");
                scanf("%d", &pos);
                insertLeft(&head, pos, data);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Main function
// int main() {
//     struct Node* head = NULL;

//     // Create a doubly linked list
//     head = createList(10);
//     head->next = createNode(20);
//     head->next->prev = head;

//     head->next->next = createNode(30);
//     head->next->next->prev = head->next;

//     printf("Initial list: ");
//     displayList(head);

//     // Insert a new node to the left of a specific node
//     printf("Inserting 15 to the left of 20...\n");
//     insertLeft(&head, 20, 15);
//     displayList(head);

//     // Delete a node based on a specific value
//     printf("Deleting node with value 15...\n");
//     deleteNode(&head, 15);
//     displayList(head);

//     return 0;
// }

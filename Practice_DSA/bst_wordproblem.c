// Imagine you are developing a library catalog system where each book is represented as a node in a Binary Search Tree. Each node contains information such as the book id, book title, author, and publication year. Your task is to implement the insertion of new books into the Binary Search Tree based on book id and provide a mechanism to print the preorder traversal of the catalog.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int book_id;
    char title[100];
    char author[100];
    int publication_year;
    struct Book *left;
    struct Book *right;
} Book;

// Function to create a new book node
Book* createBook(int book_id, char *title, char *author, int publication_year) {
    Book *newBook = (Book *)malloc(sizeof(Book));
    newBook->book_id = book_id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->publication_year = publication_year;
    newBook->left = newBook->right = NULL;
    return newBook;
}

// Function to insert a book into the BST
Book* insertBook(Book *root, int book_id, char *title, char *author, int publication_year) {
    if (root == NULL) {
        return createBook(book_id, title, author, publication_year);
    }

    if (book_id < root->book_id) {
        root->left = insertBook(root->left, book_id, title, author, publication_year);
    } else if (book_id > root->book_id) {
        root->right = insertBook(root->right, book_id, title, author, publication_year);
    } else {
        printf("Book with ID %d already exists.\n", book_id);
    }

    return root;
}

// Preorder traversal (root, left, right)
void preorderTraversal(Book *root) {
    if (root != NULL) {
        printf("Book ID: %d, Title: %s, Author: %s, Year: %d\n",
               root->book_id, root->title, root->author, root->publication_year);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Inorder traversal (left, root, right)
void inorderTraversal(Book *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Book ID: %d, Title: %s, Author: %s, Year: %d\n",
               root->book_id, root->title, root->author, root->publication_year);
        inorderTraversal(root->right);
    }
}

// Postorder traversal (left, right, root)
void postorderTraversal(Book *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("Book ID: %d, Title: %s, Author: %s, Year: %d\n",
               root->book_id, root->title, root->author, root->publication_year);
    }
}

int main() {
    Book *root = NULL;
    int choice;

    do {
        printf("\nLibrary Catalog System\n");
        printf("1. Insert Book\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int book_id, publication_year;
            char title[100], author[100];

            printf("Enter Book ID: ");
            scanf("%d", &book_id);
            printf("Enter Title: ");
            scanf(" %[^\n]s", title);
            printf("Enter Author: ");
            scanf(" %[^\n]s", author);
            printf("Enter Publication Year: ");
            scanf("%d", &publication_year);

            root = insertBook(root, book_id, title, author, publication_year);
        } else if (choice == 2) {
            if (root == NULL) {
                printf("No books in the catalog.\n");
            } else {
                printf("\nPreorder Traversal of the Library Catalog:\n");
                preorderTraversal(root);
            }
        } else if (choice == 3) {
            if (root == NULL) {
                printf("No books in the catalog.\n");
            } else {
                printf("\nInorder Traversal of the Library Catalog:\n");
                inorderTraversal(root);
            }
        } else if (choice == 4) {
            if (root == NULL) {
                printf("No books in the catalog.\n");
            } else {
                printf("\nPostorder Traversal of the Library Catalog:\n");
                postorderTraversal(root);
            }
        }
    } while (choice != 5);

    printf("Exiting the system.\n");
    return 0;
}

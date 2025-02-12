// Develop a C program that employs a hash function H: K -> L, specifically defined as H(K) = K mod n where ‘n’ represents size of the hash table. The objective is to implement a hashing technique that maps a given product code K to a corresponding memory address L. In cases where collisions occur, implement a resolution strategy using linear probing.

#include <stdio.h>
#include <stdlib.h>

int *hashTable;
int tableSize;
int count = 0; // Keeps track of inserted elements

// Function to insert a key into the hash table
void insert(int key) {
    int index = key % tableSize; // Hash function: H(K) = K mod tableSize

    // Linear probing to resolve collisions
    while (hashTable[index] != -1) {
        index = (index + 1) % tableSize; // Move to the next slot cyclically
    }

    hashTable[index] = key;
    count++;
    printf("Inserted key %d at index %d\n", key, index);
}

// Function to display the hash table
void display() {
    if (count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }

    printf("\nHash Table:\n");
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] != -1) {
            printf("T[%d] = %d\n", i, hashTable[i]);
        } else {
            printf("T[%d] = EMPTY\n", i);
        }
    }
}

int main() {
    int n;

    printf("Enter the number of product keys: ");
    scanf("%d", &n);

    printf("Enter the size of the hash table: ");
    scanf("%d", &tableSize);

    // Allocate memory for the hash table and initialize all slots to -1
    hashTable = (int *)calloc(tableSize, sizeof(int));
    if (hashTable == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    printf("Enter %d product codes (integers):\n", n);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);

        if (count == tableSize) {
            printf("\nHash table is full. Cannot insert key %d\n", key);
            break;
        }
        insert(key);
    }

    display();

    // Free allocated memory for the hash table
    free(hashTable);

    return 0;
}

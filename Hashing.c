#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht;
int count = 0;

void insert(int key) {
    int index = key % m;
    while (ht[index] != -1) {
        index = (index + 1) % m;
    }
    ht[index] = key;
    count++;
}

void display() {
    int i;
    if (count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table:\n");
    for (i = 0; i < m; i++) {
        printf("T[%d] = %d\n", i, ht[i]);
    }
}

int main() {
    int i;
    printf("Enter No. of Employee: ");
    scanf("%d", &n);

    printf("Enter Size of Hash Table: ");
    scanf("%d", &m);

    ht = (int *)calloc(m, sizeof(int));
    for (i = 0; i < m; i++)
        ht[i] = -1;

    printf("Enter 4-digit key values for %d Employee Records:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key[i]);
    }

    for (i = 0; i < n; i++) {
        if (count == m) {
            printf("\nHash table is full");
            break;
        }
        insert(key[i]);
    }

    display();
    free(ht);
    return 0;
}


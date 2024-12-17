
#include <stdio.h>

#define MAX 5

// Function to sort an array
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void rearrangeStack(int stack[], int n) {
    int min = stack[0];
    int countMin = 0;
    int temp[MAX];
    int tempTop = -1;

    // Step 1: Find the minimum element and its count
    for (int i = 0; i < n; i++) {
        if (stack[i] < min) {
            min = stack[i];
            countMin = 1;
        } else if (stack[i] == min) {
            countMin++;
        }
    }

    // Step 2: Push non-minimum elements into a temporary array
    for (int i = 0; i < n; i++) {
        if (stack[i] != min) {
            temp[++tempTop] = stack[i];
        }
    }

    // Step 3: Sort the non-minimum elements in ascending order
    sortArray(temp, tempTop + 1);

    // Step 4: Rebuild the stack
    int idx = 0;

    // Push sorted non-minimum elements back to the original stack
    for (int i = 0; i <= tempTop; i++) {
        stack[idx++] = temp[i];
    }

    // Push the minimum elements to the bottom of the stack
    while (countMin--) {
        stack[idx++] = min;
    }
}

int main() {
    int stack[MAX];
    printf("Enter %d stack elements (top to bottom):\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &stack[i]);
    }

    rearrangeStack(stack, MAX);

    printf("Updated stack (top to bottom):\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}

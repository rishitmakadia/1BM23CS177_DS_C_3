#include <stdio.h>

int Fact(int n)
{
    if(n==1)
        return 1;
    else
        return (n * Fact(n-1));
}

int GCD(int x, int y)
{
    if (x < y) {
        int t = x;
        x = y;
        y = t;
    }
    int rem = x % y;
    if (rem == 0)
        return y;
    else
        return GCD(y, rem);
}


int fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacciSeries(int terms) {
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i)); // Call the recursive function for each term
    }
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{
    // Base case: only one disk to move
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    
    // Move n-1 disks from from_rod to aux_rod
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the nth disk from from_rod to to_rod
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    
    // Move the n-1 disks from aux_rod to to_rod
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() 
{
    int choice, n, x, y;

    printf("1. Factorial\t2. GCD\t3. Fibonacci Series\t4. Tower of Hanoi");
    printf("\nChoose an operation: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            printf("Enter a non-negative integer for factorial: ");
            scanf("%d", &n);
            if (n < 0) {
                printf("Factorial is not defined for negative integers.\n");
            } else {
                printf("Factorial of %d is %d\n", n, Fact(n));
            }
            break;
        case 2:
            printf("Enter two integers to find their GCD: ");
            scanf("%d%d", &x, &y);
            printf("GCD of %d and %d is %d\n", x, y, GCD(x, y));
            break;
        case 3:
            printf("Enter the number of terms for the Fibonacci series: ");
            scanf("%d", &n);
            printf("Fibonacci Series: ");
            printFibonacciSeries(n);
            break;
        case 4: // Added case for Tower of Hanoi
            printf("Enter the number of disks for Tower of Hanoi: ");
            scanf("%d", &n);
            printf("Tower of Hanoi Moves:\n");
            towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are names of rods
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}
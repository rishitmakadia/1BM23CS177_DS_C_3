#include <stdio.h>
#include <string.h>

#define MAX 1000

// Function to check if the brackets are balanced
char* isBalanced(char* s) {
    char stack[MAX];
    int top = -1;

    // Traverse the string
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        // Push opening brackets onto the stack
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } 
        // Handle closing brackets
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) {
                return "NO"; // No matching opening bracket
            }
            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return "NO"; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, it's balanced
    return (top == -1) ? "YES" : "NO";
}

int main() {
    char s[MAX];
    printf("Enter the string of brackets: ");
    scanf("%s", s);

    // Call the isBalanced function and print the result
    printf("%s\n", isBalanced(s));

    return 0;
}

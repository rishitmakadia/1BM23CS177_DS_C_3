#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int is_operator(char symbol) {
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

int evaluate(char* expression) {
    int i = 0;
    char symbol;
    int operand1, operand2, result;

    // Iterate over the expression until the null character
    while ((symbol = expression[i]) != '\0') {
        // Check if symbol is an operand (number)
        if (isdigit(symbol)) {
            int num = symbol - '0';  // Convert character to integer
            push(num);
        } 
        // If symbol is an operator, perform the corresponding operation
        else if (is_operator(symbol)) {
            operand2 = pop(); // Second operand for binary operation
            operand1 = pop(); // First operand for binary operation
            switch (symbol) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result); // Push result of operation back onto stack
        }
        i++; // Move to next symbol in expression
    }

    result = pop(); // Final result of the postfix expression
    if (top != -1) {
        printf("Error: Invalid postfix expression\n");
        exit(1);
    }
    return result;
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    fgets(expression, MAX, stdin); // Read the expression from standard input
    int result = evaluate(expression);
    printf("Result: %d\n", result);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

// Stack for holding operands
int stack[MAX];
int top = -1;

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1; // Indicating an error
    }
    return stack[top--];
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* postfix) {
    int i = 0;
    int operand1, operand2, result;
    
    while (postfix[i] != '\0') {
        char current = postfix[i];
        
        // If the current character is a number, push it onto the stack
        if (isdigit(current)) {
            push(current - '0');  // Convert char to integer and push
        }
        // If the current character is an operator, pop two operands and perform the operation
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            operand2 = pop();
            operand1 = pop();
            
            switch (current) {
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
                    result = operand1 / operand2;
                    break;
            }
            
            push(result);  // Push the result back onto the stack
        }
        
        i++;
    }
    
    return pop();  // The result will be the only element left in the stack
}

int main() {
    char postfix[MAX];
    
    // Input: Read a postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    
    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    
    // Output: Print the result of the postfix evaluation
    printf("Result of postfix expression: %d\n", result);
    
    return 0;
}

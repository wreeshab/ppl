#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100


char stack[MAX];
int top = -1; 


int isEmpty() {
    return top == -1;
}


int isFull() {
    return top == MAX - 1;
}

void push(char c) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return stack[top--];
}

char peek() {
    if (!isEmpty()) {
        return stack[top];
    }
    return -1; 
}


int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    int i = 0;
    int j= 0;
    while(infix[i] != '\0'){
        char current = infix[i];
        if(isalnum(current)){
            postfix[j++] = current;
        }else if(current == '('){
            push(current);
        }else if(current == ')'){
            while(!isEmpty() && peek() != '('){
                postfix[j++] = pop();
            }
            pop();
        }else if(isOperator(current)){
            while(!isEmpty() && precedence(peek()) >= precedence(current)){
                postfix[j++] =pop();
            }
            push(current);
        }
        i++;
    }
    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j] = '\0';
    
}

int main() {
    char infix[100], postfix[100];

    // Input: Read an infix expression using scanf and %s
    printf("Enter an infix expression: ");
    scanf("%s", infix);  // Read a string (infix expression) using scanf

    // Call the infix-to-postfix conversion function
    infixToPostfix(infix, postfix);

    // Output: Print the resulting postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
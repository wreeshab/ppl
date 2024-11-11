#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, int data) {
    if (isFull(stack)) {
        puts("Stack overflow");
        return;
    }
    stack->items[++stack->top] = data;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        puts("Stack underflow");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(struct Stack* stack) {
    return stack->items[stack->top];
}

void calculateSpan(int prices[], int n, int span[]) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; i < n; i++) {
        // Pop elements that are less than or equal to the current price
        while (!isEmpty(&stack) && prices[peek(&stack)] <= prices[i]) {
            pop(&stack);
        }
        
       
        span[i] = isEmpty(&stack) ? i + 1 : i - peek(&stack);


        push(&stack, i);
    }
}

int main() {
    int prices[] = {23, 45, 34, 654, 65, 34, 231, 453, 46, 23, 54, 6, 57, 7, 67, 34, 45, 56, 67, 87};
    int n = sizeof(prices) / sizeof(prices[0]);
    int span[n];

    calculateSpan(prices, n, span);

    printf("Stock spans for each day:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", span[i]);
    }
    printf("\n");

    return 0;
}

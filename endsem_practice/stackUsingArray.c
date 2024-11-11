#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Stack{
    int items[MAX];
    int top;
};

void initStack(struct Stack* stack){
    stack->top  =-1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}
int isFull(struct Stack* stack){
    return stack->top == MAX-1;
}

void push(struct Stack* stack, int data){
    if(isFull(stack)){
        puts("overflow");
        return;
    }
    stack->items[++stack->top] = data;
    printf("pushed %d \n", data);
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        puts("underflow");
        return;
    }
    return stack->items[stack->top--];

}

int main() {
    struct Stack stack;
    initStack(&stack);


    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);


    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));


    if (isEmpty(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    if (isFull(&stack)) {
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
    }

    return 0;
}

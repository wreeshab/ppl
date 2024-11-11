#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Define the size of the array

struct TwoStacks {
    int arr[SIZE];
    int top1;  // Pointer for the top of Stack 1
    int top2;  // Pointer for the top of Stack 2
};

// Initialize the stacks
void initializeStacks(struct TwoStacks* ts) {
    ts->top1 = -1;
    ts->top2 = SIZE;
}

// Push into Stack 1
void push1(struct TwoStacks* ts, int data) {
    if (ts->top1 < ts->top2 - 1) {  // Ensure there's space for Stack 1
        ts->top1++;
        ts->arr[ts->top1] = data;
    } else {
        printf("Stack 1 Overflow\n");
    }
}

// Push into Stack 2
void push2(struct TwoStacks* ts, int data) {
    if (ts->top1 < ts->top2 - 1) {  // Ensure there's space for Stack 2
        ts->top2--;
        ts->arr[ts->top2] = data;
    } else {
        printf("Stack 2 Overflow\n");
    }
}

// Pop from Stack 1
int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        int popped = ts->arr[ts->top1];
        ts->top1--;
        return popped;
    } else {
        printf("Stack 1 Underflow\n");
        return -1;  // Indicate an error condition
    }
}

// Pop from Stack 2
int pop2(struct TwoStacks* ts) {
    if (ts->top2 < SIZE) {
        int popped = ts->arr[ts->top2];
        ts->top2++;
        return popped;
    } else {
        printf("Stack 2 Underflow\n");
        return -1;  // Indicate an error condition
    }
}

// Main function to test the two stacks
int main() {
    struct TwoStacks ts;
    initializeStacks(&ts);

    push1(&ts, 10);
    push2(&ts, 20);
    push1(&ts, 30);
    push2(&ts, 40);

    printf("Popped from Stack 1: %d\n", pop1(&ts));
    printf("Popped from Stack 2: %d\n", pop2(&ts));

    return 0;
}

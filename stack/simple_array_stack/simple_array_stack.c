#include "simple_array_stack.h"


simple_array_stack* create_stack() {
    simple_array_stack *stack;
    stack = (simple_array_stack *) malloc(sizeof(simple_array_stack));
    stack->top = -1;
    stack->capacity = 1;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
    return stack;
}

bool is_stack_full(simple_array_stack* stack) {
    if(stack->top == stack->capacity-1) {
        return true;
    } else {
        return false;
    }
}


bool is_stack_empty(simple_array_stack* stack) {
    if(stack->top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(simple_array_stack* stack, int data) {
    if(is_stack_full(stack) == true) {
        printf("Stack is overflowed! but we will make room for ya!\n");
        stack->capacity++;
        stack->array = (int *)realloc((int *)stack->array, stack->capacity * sizeof(int));
        stack->top++;
        stack->array[stack->top] = data;
    } else {
        stack->top++;
        stack->array[stack->top] = data;
    }
}

int pop(simple_array_stack* stack) {
    if(is_stack_empty(stack) == true) {
        printf("The stack has underflowed!\n");
        return -1;
    } else {
        return (stack->array[stack->top--]);
    }
}

void display_stack(simple_array_stack* stack) {
    printf("The capacity of the stack: %d\n", stack->capacity);
    int i;
    printf("Stack:\n");
    for(i=stack->top;i>=0;i--) {
        printf("%d\n", stack->array[i]);
    }
}
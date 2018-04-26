#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct simple_array_stack {
    int top;
    int capacity;
    int *array;
} simple_array_stack;

simple_array_stack* create_stack();
void push(simple_array_stack* stack, int data);
int pop(simple_array_stack* stack);
void display_stack(simple_array_stack* stack);
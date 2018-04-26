#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct dynamic_array_stack {
    int top;
    int capacity;
    int *array;
} dynamic_array_stack;

dynamic_array_stack* create_stack();
void push(dynamic_array_stack* stack, int data);
int pop(dynamic_array_stack* stack);
void display_stack(dynamic_array_stack* stack);
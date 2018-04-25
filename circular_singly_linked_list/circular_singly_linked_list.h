#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* insert_at_begin(node* head, int val);
node* insert_at_end(node* head, int val);
node* insert_at_pos(node* head, int val, int pos_val);
void display(node *head);
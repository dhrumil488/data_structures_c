#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node* insert_at_begin(node* head, int data);
node* insert_at_end(node* head, int value);
node* insert_at_pos(node* head, int value, int pos_data);
node* delete_at_begin(node* head);
node* delete_at_end(node* head);
node* delete_at_pos(node* head, int pos_data);
node* delete_list(node* head);
node* reverse_list(node *prev, node *cur, node *next);
node* find_middle_node(node* head);
int get_length(node *head);
int is_length_even(node *head);
void display(node *head);
void display_reverse(node *head);
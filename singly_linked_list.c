#include "singly_linked_list.h"

node* insert_at_begin(node* head, int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if(head){
        new_node->next = head;
        head = new_node;
    } else {
        head = new_node;
    }
    return head;
}

node* insert_at_end(node* head, int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if(head) {
        node* temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    } else {
        head = new_node;
    }
    return head;
}

node* insert_at_pos(node* head, int value, int pos_data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL;
    if(head) {
        node* temp = head;
        while(temp && temp->data != pos_data){
            temp = temp->next;
        }
        if(temp) {
            new_node->next = temp->next;
            temp->next = new_node;
        } else {
            free(new_node);
            printf("Node not found!\n");
        }

    } else {
        free(new_node);
        printf("Linked list is empty!\n");
    }
    return head;
}

node* delete_list(node* head) {
    node* temp = head;
    while(temp){
        free(temp);
        temp = temp->next;
    }
    return temp;
}

void display(node* head){
    node* temp = head;
    while(temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}




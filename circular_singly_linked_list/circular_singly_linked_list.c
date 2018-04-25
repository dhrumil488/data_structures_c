#include "circular_singly_linked_list.h"


node* create_new_node(int val) {
    node* newnode;
    newnode = (node *)malloc(sizeof(node));
    if(newnode) {
        newnode->data = val;
        newnode->next = NULL;
    }
    return newnode;
}

node* get_last_node(node* head) {
    node *temp = head;
    while(temp->next!=head) {
        temp = temp->next;
    }
    return temp;
}

node* insert_at_begin(node* head, int val) {
    node* newnode = create_new_node(val);
    if(head) {
        //make last node point to new head
        node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;

    } else {
        head = newnode;
        head->next = head;
    }
    return head;
}

node* insert_at_end(node* head, int val) {
    node* newnode = create_new_node(val);
    if(head) {
        //make last node point to new head
        node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;

    } else {
        head = newnode;
        head->next = head;
    }
    return head;
}

node* insert_at_pos(node* head, int val, int pos_val) {
    node* newnode;
    newnode = create_new_node(val);
    node *lastnode = get_last_node(head);
    if(head) {
        node *temp = head;
        int flag = 0;
        while(temp->next != head) {
            if(temp->data == pos_val) {
                flag = 1;
                newnode->next = temp->next;
                temp->next = newnode;
            }
            temp = temp->next;
        }
        if(!flag) {
            if(temp->data == pos_val) {
                temp->next = newnode;
                newnode->next = head;
            } else {
                printf("Could not find the pos of given value!\n");
            }
        }
        
    } else {
        printf("Can node add at specific pos as list is empty!\n");
    }
    return head;
}

void display(node* head) {
    printf("Circular Linked List:\n");
    node *temp = head;
    while(temp->next != head) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("%d --> %d\n", temp->data, temp->next->data);
}
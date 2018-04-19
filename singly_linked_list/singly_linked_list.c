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

node* delete_at_begin(node* head) {
    if(head) {
        node* temp = head;
        head = head->next;
        free(temp);
    } else {
        printf("List is empty!\n");
    }
    return head;
}

node* delete_at_end(node* head) {
    if(head) {
        node* temp = head;
        while(temp->next->next){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    } else {
        printf("List is empty!\n");
    }
    return head;
}

node* delete_at_pos(node* head, int pos_data) {
    if(head) {
        node* temp = head;
        while(temp && temp->next->data == pos_data) {
            temp = temp->next;
        }
        if(temp) {
            temp->next = temp->next->next;
            free(temp->next);
        } else {
            printf("Node not found!\n");
        }
    } else {
        printf("List is empty!\n");
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

node* reverse_list(node* prev, node* cur, node* next) {
    if(next) {
        node* temp;
        temp = reverse_list(cur, next, next->next);
        cur->next = prev;
        return temp;
    } else {
        printf("In else consition!\n");
        printf("cur data::::%d", cur->data);
        cur->next = prev;
        return cur;
    }
}

node* find_middle_node(node *head) {
    if(head) {
        node* ptr1 = head;
        node* ptr2 = head;
        int flag = 0;
        while(ptr2->next!=NULL) {
            if(flag==0) {
                ptr2 = ptr2->next;
                flag = 1;
            } else {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                flag = 0;
            }
        }
        return ptr1;
    } else {
        printf("The list is empty!\n");
        return NULL;
    }
    
}

int get_length(node *head) {
    node* temp = head;
    int counter = 0;
    while(temp) {
        temp=temp->next;
        counter++;
    }
    return counter;
}

int is_length_even(node* head) {
    node* ptr = head;
    while(ptr && ptr->next) {
        ptr = ptr->next->next;
    }
    if(ptr)
        return 0;
    else
        return 1;
}

void display(node* head){
    node* temp = head;
    while(temp){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_reverse(node *head) {
    if(!head)
        return;
    display_reverse(head->next);
    printf("%d --> ", head->data);
}




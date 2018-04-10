#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int *arr;
    struct node *next;
} node;

int *arr;
int len;
node *head = NULL;

node* create_new_node() {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->arr = (int *)malloc(len * sizeof(int));
    int i;
    for(i=0;i<len;i++) {
        newnode->arr[i] = arr[i];
    }
    newnode->next = NULL;
    return newnode;
}

void add_at_end(node *newnode) {
    if(head) {
        node *temp;
        temp = head;
        while(head->next) {
            temp = temp->next;
        }
        temp->next = newnode;
    } else {
        head = newnode;
    }
    
}

void display(int *arr){
    int i;
    for(i=len-1;i>=0;i--) {
        printf("%d",arr[i]);
    }
    printf("\n");
}

void binary(int n) {
    if(n<1) {
        node *newnode = create_new_node();
        add_at_end(newnode);
        return;
    }
    arr[n-1] = 0;
    binary(n-1);
    arr[n-1] = 1;
    binary(n-1);
} 

void print_list() {
    node *temp = head;
    while(temp) {
        int i;
        for(i=len-1;i>=0;i--) {
            printf("%d",temp->arr[i]);
        }
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    int n;
    printf("Enter the length of binary strings:");
    scanf("%d", &n);
    len = n;
    arr = (int *)malloc(n * sizeof(int));
    binary(n);
    print_list();
}
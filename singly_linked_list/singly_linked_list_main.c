#include "singly_linked_list.h"

int main() {
    int choise, data, pos_data;
    node* head = NULL;
    node* temp = NULL;
    printf("-----------Singly Linked List---------------\n");
    while(1) {
        printf("\n Main Menu\n");
        printf("1. Insert node at begin.\n");
        printf("2. Insert node at end.\n");
        printf("3. Insert node at specific position after which node will be inserted.\n");
        printf("4. Delete node at begin.\n");
        printf("5. Delete node at end.\n");
        printf("6. Delete node at specific position after which node will be inserted.\n");
        printf("7. Delete whole linked list\n");
        printf("8. Sort the linked list\n");
        printf("9. Reverse the linked list\n");
        printf("10. Find middle node's pointer and value of linked list.\n");
        printf("11. Get the length of linked list.\n");
        printf("12. Find the length of the linked list is even or odd.\n");
        printf("13. Display the linked list\n");
        printf("14. Display the linked list in reverse order\n");
        printf("15. Exit\n");
        printf("Enter the choise:");
        scanf("%d", &choise);

        switch(choise){
            case 1:
                printf("Please enter the data value of node:");
                scanf("%d", &data);
                head = insert_at_begin(head, data);
                break;
            case 2:
                printf("Please enter the data value of node:");
                scanf("%d", &data);
                head = insert_at_end(head, data);
                break;
            case 3:
                printf("Please enter the data value of node:");
                scanf("%d", &data);
                printf("Enter the pos data after which you want to add node:");
                scanf("%d", &pos_data);
                head = insert_at_pos(head, data, pos_data);
                break;
            case 4:
                head = delete_at_begin(head);
                break;
            case 5:
                head = delete_at_end(head);
                break;
            case 6:
                printf("Enter the data of node which is to be deleted:");
                scanf("%d", &pos_data);
                head = delete_at_pos(head, pos_data);
                break;
            case 7:
                head = delete_list(head);
                break;
            case 8:
                break;
            case 9:
                if(head) {
                    head = reverse_list(NULL, head, head->next);
                } else {
                    printf("List is empty!\n");
                }
                break;
            case 10:
                temp = find_middle_node(head);
                if(temp) {
                    printf("Middle Node Address: %p\n", temp);
                    printf("Middle Node value: %d\n", temp->data);
                } else {
                    printf("Can not find the middle element!\n");
                }
                break;
            case 11:
                printf("The length of the linked list is: %d\n", get_length(head));
                break;
            case 12:
                if(is_length_even(head)){
                    printf("The length of the linked list is EVEN.\n");
                } else {
                    printf("The length of the linked list is ODD.\n");
                }
                break;
            case 13:
                display(head);
                break;
            case 14:
                display_reverse(head);
                printf("NULL\n");
                break;
            case 15:
                exit(0);
                break;
        }

    }
    

    return 0;
}
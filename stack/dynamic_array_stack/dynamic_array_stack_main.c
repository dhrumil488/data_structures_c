#include "dynamic_array_stack.h"


int main() {
    int choise;
    dynamic_array_stack* stack;
    int data;
    printf("\nSimple Array Implementation of Stack\n");
    while(1) {
        printf("Main Menu\n");
        printf("1. Create a new stack\n");
        printf("2. Push data\n");
        printf("3. Pop data\n");
        printf("4. Top data\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");

        printf("Please enter your choise:");
        scanf("%d", &choise);

        switch(choise) {
            case 1:
                stack = create_stack();
                break;
            case 2:
                printf("Please enter data:");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 3:
                printf("The data poped: %d", pop(stack));
                break;
            case 4:
                break;
            case 5:
                display_stack(stack);
                break;
            case 6:
                //sys.exit(0)
                break;
                break;
            default:
                break;
        }
    }
    return 0;
}
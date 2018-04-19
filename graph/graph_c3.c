#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct adjlist_node {
    char dest;
    struct adjlist_node *next;
} adjlist_node;

typedef struct adjlist {
    char label;
    adjlist_node *head;
    struct adjlist *next;
} adjlist;

typedef struct graph {
    int no_v;
    adjlist *adjlist_p;
} graph;

// allocate memory to new node and return the address of it 
adjlist_node* create_new_adjnode(char dest) {
    adjlist_node *newnode;
    newnode = (adjlist_node *)malloc(sizeof(adjlist_node));
    if(newnode) {
        newnode->dest = dest;
        newnode->next = NULL;
    } else {
        printf("Can not create a new node!\n");
    }
    return newnode;
}

adjlist* create_new_adjlist(char label) {
    adjlist *newlist;
    newlist = (adjlist *)malloc(sizeof(adjlist));
    if(newlist) {
        newlist->label = label;
        newlist->head = NULL;
        newlist->next = NULL;
    } else {
        printf("Can not create a list for node in graph!\n");
    }
    return newlist;
}

//initalize the null graph with no nodes
graph* create_graph() {
    graph *graph_p;
    graph_p = (graph *)malloc(sizeof(graph));
    graph_p->no_v = 0;
    graph_p->adjlist_p = NULL;
}

// just check whether a node is exist in graph or not
bool is_valid(graph *graph_p, char label) {
    bool valid = false;
    adjlist *temp = graph_p->adjlist_p;
    while(temp){
        if(temp->label == label) {
            valid = true;
        }
        temp = temp->next;
    }
    return valid;
}

void add_edge(graph *graph_p, char src, char des) {
    if((is_valid(graph_p, src) == true) && (is_valid(graph_p, des) == true)) {
        adjlist_node *newnode;
        newnode = create_new_adjnode(des);
        if(newnode) {
            adjlist *temp = graph_p->adjlist_p;
            while(temp) {
                if(temp->label == src){
                    if(temp->head) {
                        newnode->next = temp->head;
                        temp->head = newnode;
                    } else {
                        temp->head = newnode;
                    }
                }
                temp = temp->next;
            }
        } else {
            printf("Can not create a node to add an edge in graph!\n");
        }
    } else {
        printf("SRC or DES not found!\n");
    }
}




//add node to the graph 
void add_node(graph *graph_p, char label) {
    adjlist *newlist;
    newlist = create_new_adjlist(label);
    if(newlist) {
        //increment a vertices counter
        (graph_p->no_v)++;
        // add new list of new node to begin to list of adgecency
        if(graph_p->adjlist_p) {
            newlist->next = graph_p->adjlist_p;
            graph_p->adjlist_p = newlist;
        } else {
            graph_p->adjlist_p = newlist;
        }

    } else {
        printf("Can not create a new list in graph!\n");
    }
}

void display(graph *graph_p) {
    adjlist *temp = graph_p->adjlist_p;
    while(temp) {
        printf("For node %c::\n", temp->label);
        adjlist_node *temp_node = temp->head;
        while(temp_node) {
            printf("%c --> ", temp_node->dest);
            temp_node = temp_node->next;
        }
        temp = temp->next;
        printf("\n");
    }
    printf("\n");
}


int main() {
    printf("Graph operation:\n");
    graph *graph_p;
    graph_p = create_graph();
    int choise;
    char label;
    char src, dest;
    while(1) {
        printf("Main Menu:\n");
        printf("1. add node\n");
        printf("2. add edge\n");
        printf("3. display\n");
        printf("4. exit\n");

        printf("Please enter choise:");
        scanf("%d", &choise);

        switch(choise) {
            case 1: 
                printf("Please enter the label:");
                scanf(" %c", &label);
                add_node(graph_p, label);
                break;
            
            case 2:
                printf("Please enter src and des sparated by new line:");
                scanf(" %c", &src);
                printf("Please enter src and des sparated by new line:");
                scanf(" %c", &dest);
                add_edge(graph_p, src, dest);
                break;
            
            case 3:
                display(graph_p);
                break;

            case 4:
                exit(0);
                break;
            
            default:
                printf("Please enter valid choise!\n");
                break;
        }
    }
    return 0;
}
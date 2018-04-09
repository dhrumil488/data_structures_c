#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct adj_list_node {
    int label;
    struct adj_list_node *next;
} adj_list_node;

typedef struct adj_list {
    adj_list_node *head;
} adj_list;

typedef struct graph {
    int no_vert;
    adj_list *adjlist;
} graph;


adj_list_node* new_adj_list_node(int val) {
    adj_list_node *newnode;
    newnode = (adj_list_node *)malloc(sizeof(adj_list_node));
    newnode->label = val;
    newnode->next = NULL;
    return newnode;
}

graph* create_graph(int no_vertices) {
    graph *graph_obj;
    graph_obj = (graph *)malloc(sizeof(graph));
    graph_obj->no_vert = no_vertices;

    graph_obj->adjlist = (adj_list *)malloc(no_vertices * sizeof(adj_list));

    int i;
    for(i=0;i<no_vertices;i++) {
        graph_obj->adjlist[i].head = NULL;
    }
    return graph_obj;
}

bool dest_valid(graph *graph_obj, int dest) {
    int i;
    bool dest_valid = false;
    for(i=0;i<graph_obj->no_vert;i++) {
        if(i==dest) {
            dest_valid = true;
        }
    }
    return dest_valid;
}

bool src_valid(graph *graph_obj, int src) {
    int i;
    bool src_valid = false;
    for(i=0;i<graph_obj->no_vert;i++) {
        if(i == src) {
            src_valid = true;
        }
    }
    return src_valid;
}

void add_edge(graph *graph_obj, int src, int dest) {
    
    if(dest_valid(graph_obj, dest) && src_valid(graph_obj, src)) {
        adj_list_node *newnode1 = new_adj_list_node(dest);
        newnode1->next = graph_obj->adjlist[src].head;
        graph_obj->adjlist[src].head = newnode1;

        // adj_list_node *newnode2 = new_adj_list_node(src);
        // newnode2->next = graph_obj->adjlist[dest].head;
        // graph_obj->adjlist[dest].head = newnode2;

    } else {
        printf("Dest. or  Src. node is not exist!\n");
    }
    
}

void display(graph *graph_obj) {
    int i;
    for(i=0;i<graph_obj->no_vert;i++) {
        printf("adj list of node %d\n", i);
        adj_list_node *temp = graph_obj->adjlist[i].head;
        while(temp) {
            printf("%d -> ", temp->label);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    printf("Enter no of vertices:");
    scanf("%d", &n);
    graph *graph_obj = create_graph(n);
    add_edge(graph_obj, 0, 1);
    add_edge(graph_obj, 0, 4);
    add_edge(graph_obj, 1, 0);
    add_edge(graph_obj, 1, 2);
    add_edge(graph_obj, 1, 3);
    add_edge(graph_obj, 1, 4);
    add_edge(graph_obj, 2, 1);
    add_edge(graph_obj, 2, 3);
    add_edge(graph_obj, 3, 2);
    add_edge(graph_obj, 3, 1);
    add_edge(graph_obj, 3, 4);
    add_edge(graph_obj, 4, 0);
    add_edge(graph_obj, 4, 1);
    add_edge(graph_obj, 4, 3);

    display(graph_obj);

    return 0;
}
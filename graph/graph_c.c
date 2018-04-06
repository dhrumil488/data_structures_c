#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int val;
    struct AdjListNode *next;
}AdjListNode;

typedef struct AdjList {
    AdjListNode *head;
}AdjList;

typedef struct Graph {
    int V;
    AdjList *adj_list;
}Graph;

Graph* createGraph(int n) {
    //declaring the graph
    Graph *graph;
    //allocate the memory to graph variable
    graph = (Graph *)malloc(sizeof(Graph));
    if(graph) {
        graph->V = n;
        //create a array for the V number of Adjecency Lists
        graph->adj_list = (AdjList *)malloc(graph->V * sizeof(AdjList));
        //initialize all list's head variable with NULL
        int i;
        for(i=0;i<graph->V;i++){
            graph->adj_list[i].head = NULL;
        }
        //return graph address
        return graph;
    } else {
        printf("Graph can not be created!\n");
        return NULL;
    }
    
}

//create a node in list
AdjListNode * newAdjListNode(int val) {
    AdjListNode *newNode;
    newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

//add an edge in undirected graph
void addEdge(Graph *graph, int src, int dest) {
    int i;
    for(i=0;i<graph->V;i++) {
        if(i==src){
            AdjListNode *newNode = newAdjListNode(dest);
            if(graph->adj_list[i].head == NULL) {
                graph->adj_list[i].head = newNode;
            } else {
                AdjListNode *temp = graph->adj_list[i].head;
                while(temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            return;
        }
    }

    //graph is undirected, so add to dest vertices list also
    for(i=0;i<graph->V;i++) {
        if(i==dest){
            AdjListNode *newNode = newAdjListNode(src);
            if(graph->adj_list[i].head == NULL) {
                graph->adj_list[i].head = newNode;
            } else {
                AdjListNode *temp = graph->adj_list[i].head;
                while(temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            return;
        }
    }
    printf("Vertices does not exist!\n");
}

void display(Graph *graph) {
    int i, n;
    n = graph->V;
    for(i=0;i<n;i++) {
        printf("Adj list of vertice %d:\n", i);
        AdjListNode *temp = graph->adj_list[i].head;
        while(temp) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    printf("Please enter number of vertices in graph:");
    scanf("%d", &n);
    Graph *graph;
    graph = createGraph(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 3);

    display(graph);

    return 0;
}
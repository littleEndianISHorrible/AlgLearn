#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
// „T„x„u„| „t„|„‘ „ƒ„„y„ƒ„{„p „ƒ„}„u„w„~„€„ƒ„„„y
struct AdjListNode {
    int dest;
    int weight; // „t„|„‘ „r„x„r„u„Š„u„~„~„„‡ „s„‚„p„†„€„r
    struct AdjListNode* next;
};

// „R„„y„ƒ„€„{ „ƒ„}„u„w„~„€„ƒ„„„y ? „}„p„ƒ„ƒ„y„r „y„x „…„{„p„x„p„„„u„|„u„z „~„p „…„x„|„
struct AdjList {
    struct AdjListNode* head;
};

// „C„‚„p„† ? „}„p„ƒ„ƒ„y„r „ƒ„„y„ƒ„{„€„r „ƒ„}„u„w„~„€„ƒ„„„y
struct Graph {
    int V; // „{„€„|„y„‰„u„ƒ„„„r„€ „r„u„‚„Š„y„~
    struct AdjList* array;
};

// „R„€„x„t„p„~„y„u „~„€„r„€„s„€ „…„x„|„p
struct AdjListNode* newAdjListNode(int dest, int weight) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// „R„€„x„t„p„~„y„u „s„‚„p„†„p „ƒ V „r„u„‚„Š„y„~„p„}„y
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) calloc(V, sizeof(struct AdjList));
	int i;
    for (i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// „D„€„q„p„r„|„u„~„y„u „‚„u„q„‚„p (u <-> v) ? „~„u„€„‚„y„u„~„„„y„‚„€„r„p„~„~„„z „s„‚„p„†
void addEdge(struct Graph* graph, int u, int v, int weight) {
    // „D„€„q„p„r„|„‘„u„} v „r „ƒ„„y„ƒ„€„{ u
    struct AdjListNode* node = newAdjListNode(v, weight);
    node->next = graph->array[u].head;
    graph->array[u].head = node;

    // „D„€„q„p„r„|„‘„u„} u „r „ƒ„„y„ƒ„€„{ v („u„ƒ„|„y „~„p„Š „s„‚„p„† „~„u„€„‚„y„u„~„„„y„‚„€„r„p„~„~„„z)
    node = newAdjListNode(u, weight);
    node->next = graph->array[v].head;
    graph->array[v].head = node;
}



void BFS(struct Graph* graph, int start) {
    bool* visited = (bool*) calloc(graph->V, sizeof(bool));
    int* queue = (int*) malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        struct AdjListNode* temp = graph->array[u].head;
        while (temp != NULL) {
            int v = temp->dest;
            if (!visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(queue);
}

void DFSUtil(struct Graph* graph, int u, bool* visited) {
    visited[u] = true;
    printf("%d ", u);

    struct AdjListNode* temp = graph->array[u].head;
    while (temp != NULL) {
        int v = temp->dest;
        if (!visited[v]) {
            DFSUtil(graph, v, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int start) {
    bool* visited = (bool*) calloc(graph->V, sizeof(bool));
    printf("DFS: ");
    DFSUtil(graph, start, visited);
    printf("\n");
    free(visited);
}

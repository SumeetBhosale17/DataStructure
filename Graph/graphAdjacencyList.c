#include <stdio.h>
#include <stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int numVertices;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest)
{
    struct AdjListNode *newNode = malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->array = malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        struct AdjListNode *crawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (crawl)
        {
            printf("-> %d", crawl->dest);
            crawl = crawl->next;
        }
        printf("\n");
    }
}

void freeGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        struct AdjListNode *crawl = graph->array[v].head;
        while (crawl)
        {
            struct AdjListNode *temp = crawl;
            crawl = crawl->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}

int main()
{
    int V, E, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph* graph = createGraph(V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for(int i = 0; i < E; i++) {
        printf("Enter edge %d (source destination): ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    freeGraph(graph);

    return 0;
}
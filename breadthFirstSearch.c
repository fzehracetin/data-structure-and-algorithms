#include <stdio.h>
#define N 11

typedef struct 
{
    int u, v;
}GRAPH;

typedef struct 
{
    int queue[N];
    int rear;
    int front;
}QUEUE;

void initiliazeQueue(QUEUE *q) 
{
    q->rear = 0;
    q->front = 0;
}

void enqueue(QUEUE *q, int x) 
{
    q->queue[q->rear++] = x;
}

int dequeue(QUEUE *q)
{
    return q->queue[q->front++];
}

void adjacencyBuilder(GRAPH graph[], int adjacency[][7], int edges, int vertices) 
{
    int i, j;
    for (i = 0; i < vertices; i++) //initialize the matrix
        for (j = 0;  j < vertices; j++)
            adjacency[i][j] = 0;
    
    for (i = 0; i < edges; i++) 
    {
        adjacency[graph[i].u][graph[i].v] = 1;
        adjacency[graph[i].v][graph[i].u ] = 1;
    }
    
    for (i = 0; i < vertices; i++) 
    { //print the matrix
        for (j = 0;  j < vertices; j++) 
            printf("%d ", adjacency[i][j]);
        printf("\n");
    }
}

void bfsIterative(QUEUE *q, int v, int adjacency[][7], int *visited, int vertices, int *parent)
{
    int i;
    parent[i] = -1;
    visited[v] = 1;
    enqueue(q, v);
    while (q->front < q->rear) 
    {
        v = dequeue(q);
        for (i = 0; i < vertices; i++) 
	{
             if ((adjacency[v][i] == 1) && (visited[i] == 0)) {
                parent[i] = v;
                visited[i] = 1;
                enqueue(q, i);
             }
        }
    }
}

int main(int argc, char **argv)
{
    GRAPH graph[11];
    QUEUE q;
    int adjacency[7][7], visited[7], parent[7], vertices = 7, edges = 11, i;
    for (i = 0; i < vertices; i++) 
    { //initialize visited array
        visited[i] = 0;
    }
    for (i = 0; i < vertices; i++) 
    { //initialize parent array
        parent[i] = 0;
    }
    initiliazeQueue(&q);
    graph[0].u = 0;
    graph[0].v = 3;
    
    graph[1].u = 2;
    graph[1].v = 4;
    
    graph[2].u = 3;
    graph[2].v = 5;
    
    graph[3].u = 0;
    graph[3].v = 1;
    
    graph[4].u = 1;
    graph[4].v = 4;
    
    graph[5].u = 1;
    graph[5].v = 2;
    
    graph[6].u = 4;
    graph[6].v = 5;
    
    graph[7].u = 4;
    graph[7].v = 6;
    
    graph[8].u = 1;
    graph[8].v = 3;
    
    graph[9].u = 5;
    graph[9].v = 6;
    
    graph[10].u = 3;
    graph[10].v = 4;
    
    adjacencyBuilder(graph, adjacency, edges, vertices);
    bfsIterative(&q, 0,adjacency, visited, vertices, parent);
    for (i = 0; i < vertices; i++) {
        printf("visited[%d] = %d\n", i, visited[i]);
    }
    for (i = 0; i < vertices; i++) {
        printf("parent[%d] = %d\n", i, parent[i]);
    }
	return 0;
}

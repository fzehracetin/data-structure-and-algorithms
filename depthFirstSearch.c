#include <stdio.h>
#define N 11

typedef struct 
{
    int u, v;
}GRAPH;

typedef struct 
{
    int stack[N];
    int top;
}STACK;

void initiliazeStack(STACK *s) 
{
    s->top = 0;
}

void push (STACK *s, int x) 
{
    s->stack[s->top++] = x;
}

int pop (STACK *s) 
{
    return s->stack[--s->top];
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

void dfsRecursive(int adjacency[][7], int v, int *visited, int* parent, int vertices) 
{
    int i;
    visited[v] = 1;
    for (i = 0; i < vertices; i++) 
    {
        if ((adjacency[v][i] == 1) && (visited[i] == 0)) 
	{
            parent[i] = v;
            dfsRecursive(adjacency, i, visited, parent, vertices);
        }
    }
    
}

void dfsIterative(int adjacency[][7], STACK *s, int v, int *visited, int *parent, int vertices) 
{
    int i;
    push(s, v);
    parent[v] = -1;
    visited[v] = 1;
    while (s->top > 0) 
    {
        v = pop(s);
        for (i = 0; i < vertices; i++) 
	{
            if ((adjacency[v][i] == 1) && (visited[i] == 0)) 
	    {
                parent[i] = v;
                push(s, i);
                visited[i] = 1;
            }
        }
    }
}

int main(int argc, char **argv)
{
    GRAPH graph[11];
    STACK s;
    int adjacency[7][7], visited[7], parent[7], vertices = 7, edges = 11, i;
    for (i = 0; i < vertices; i++) 
    { //initialize visited array
        visited[i] = 0;
    }
    for (i = 0; i < vertices; i++) 
    { //initialize parent array
        parent[i] = 0;
    }
    initiliazeStack(&s);
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
    //dfsRecursive(adjacency, 0, visited, parent, vertices);
    dfsIterative(adjacency, &s, 0, visited, parent, vertices);
    for (i = 0; i < vertices; i++) 
    {
        printf("visited[%d] = %d\n", i, visited[i]);
    }
    for (i = 0; i < vertices; i++) 
    {
        printf("parent[%d] = %d\n", i, parent[i]);
    }
    
	return 0;
}

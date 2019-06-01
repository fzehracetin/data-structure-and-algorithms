#include <stdio.h>

typedef struct 
{
    int u, w, v;
}GRAPH;

typedef struct 
{
    int u, v;
}MST;

void kruskal(GRAPH graph[], int *label, MST mst[], int totalWeight, int vertices, int edges) 
{
    int i = 0, j = 0, k, u, v, labelNo = 0, oldLabel;
    while ((i < vertices) && (j < edges)) 
    {
        u = graph[j].u;
        v = graph[j].v;
        
        if (label[u] + label[v] == 0) 
	{ // they did not labeled before
            labelNo++;
            label[u] = label[v] = labelNo;
            mst[i].u = u;
            mst[i].v = v; //add them to minimum spanning tree
            totalWeight += graph[j].w;
            i++;
        }
        else if ( label[u] != label[v] ) 
	{
            if (label[u] == 0) 
	    { // u did not labeled but v labeled
                label[u] = label[v]; //give v's label to u
                mst[i].u = u;
                mst[i].v = v; //add them to minimum spanning tree
                totalWeight += graph[j].w;
                i++;
            }
            else if (label[v] == 0) 
	    { // v did not labeled but u labeled
                label[v] = label[u]; // give u's label to v
                mst[i].u = u;
                mst[i].v = v; //add them to minimum spanning tree
                totalWeight += graph[j].w;
                i++;
            }
            else 
	    { // they both labeled, they are in different connected component
                oldLabel = label[u];
                for (k = 0; k < vertices; k++) 
		{
                    if (label[k] == oldLabel) 
                        label[k] = label[v];
                } //we combined to different connected component
                mst[i].u = u;
                mst[i].v = v; //add them to minimum spanning tree
                totalWeight += graph[j].w;
                i++;
            }
            // if they have same label do nothing because they are in mst already
        }
        j++;
    }
}

int main(int argc, char **argv)
{
    GRAPH graph[11]; //length of graph is #of edges
    MST mst[6]; //length of mst is #of vertices-1
    int label[8], i, totalWeight = 0, vertices = 7, edges = 11;
    for(i = 0; i < 7; i++) { //initiliaze label array
        label[i] = 0; //lenght of a label array is #of vertices
    }
    // the graph array must be in ascending order by their weights
    graph[0].u = 1;
    graph[0].w = 5;
    graph[0].v = 4;
    
    graph[1].u = 3;
    graph[1].w = 5;
    graph[1].v = 5;
    
    graph[2].u = 4;
    graph[2].w = 6;
    graph[2].v = 6;
    
    graph[3].u = 1;
    graph[3].w = 7;
    graph[3].v = 2;
    
    graph[4].u = 2;
    graph[4].w = 7;
    graph[4].v = 5;
    
    graph[5].u = 2;
    graph[5].w = 8;
    graph[5].v = 3;
    
    graph[6].u = 5;
    graph[6].w = 8;
    graph[6].v = 6;
    
    graph[7].u = 5;
    graph[7].w = 9;
    graph[7].v = 7;
    
    graph[8].u = 2;
    graph[8].w = 9;
    graph[8].v = 4;
    
    graph[9].u = 6;
    graph[9].w = 11;
    graph[9].v = 7;
    
    graph[10].u = 4;
    graph[10].w = 15;
    graph[10].v = 5;
    
    kruskal(graph, label, mst, totalWeight, vertices, edges);
    
    for (i = 0; i < vertices; i++) {
        printf("mst[%d] -> ", i);
        printf("u = %d v = %d \n", mst[i].u, mst[i].v);
    }
    for (i = 1; i < vertices + 1; i++) {
        printf("label[%d] = %d \n", i , label[i]);
    }
	return 0;
}

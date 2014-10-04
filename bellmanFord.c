#include<stdio.h>
#include<stdlib.h>
#define INF 123456789
/* Input Format: Graph is directed and weighted. First two integers must be number of vertces and edges 
   which must be followed by pairs of vertices which has an edge between them. 
 */
void bellmanFord(int graph[][100], int cost[][100], int size[], int source, int vertices)	{
        int distance[vertices];
        int i, j, from, to;
        for(i = 0; i < vertices; i++)	{ 
                distance[i] = INF;
        }
        distance[source] = 0;
        /* We have to repeatedly update the distance |V|-1 times where |V| represents
           number of vertices */
        for(i = 0; i < vertices - 1; i++)	{
                for(from = 0; from < vertices; from++)	{
                        for(j = 0; j < size[from]; j++)	{
                                to = graph[from][j];
                                if((distance[from] + cost[from][j]) < distance[to])	{
                                        distance[to] = distance[from] + cost[from][j];
                                }
                        }
                }
        }
        for(i = 0; i < vertices; i++)	{
                printf("The shortest distance to %d is %d\n", i, distance[i]);
        }
}
int main(int argc, char **argv)	{
        int graph[100][100], size[100] = {0};

        int cost[100][100];
        int vertices, edges, i;
        /* vertices represent number of vertices and edges represent number of edges in the graph. */
        printf("Enter Number of vertices and Edges:\n");
		scanf("%d%d", &vertices, &edges);

        int vertex1, vertex2, weight;

        /* Here graph[i][j] represent the weight of edge joining i and j */
        
		for(i = 0; i < edges; i++)	{
				printf("Enter the vertices of edge %d and its weight:\n", i + 1);
                scanf("%d%d%d", &vertex1, &vertex2, &weight);
                
				if(vertex1 > vertices || vertex1 < 0 || vertex2 < 0 || vertex2 > vertices) {
					printf("Invalid Vertex");
					exit(1);
				}

                graph[vertex1][size[vertex1]] = vertex2;			//cost of edge from vertex1-vertex2
                cost[vertex1][size[vertex1]] = weight;				//cost of going from vertex1-vertex2
                size[vertex1]++;									//the number of edges corresponding to each vertex
        }
        int source;
		printf("Enter the source:\n");
        scanf("%d", &source);
        bellmanFord(graph, cost, size, source, vertices);
        return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 9999
typedef struct {
	int u,v, cost;
} Edge;

int find(int parent[], int i) {
// Write your code here...
	while(parent[i] != i) 
	i = parent[i];
	return i;

}


void union_set(int parent[], int x, int y) {
	int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
	
}
int compare(const void *a, const void *b){
	Edge *e1 = (Edge *)a;
	Edge *e2 = (Edge *)b;
	if (e1->cost != e2->cost)
		return e1->cost - e2->cost;
	if(e1->u != e2->u)
		return e1->u - e2->u;
	return e1->v - e2->v;
}

void kruskalMST(int **cost, int V) {
	Edge *edges = (Edge *)malloc(V*V * sizeof(Edge));
	int edgeCount = 0;
	for(int i = 0; i < V; i++){
		for(int j = i+1; j < V; j++){
			if(cost[i][j] != INF){
				edges[edgeCount].u = i;
				edges[edgeCount].v = j;
				edges[edgeCount].cost = cost[i][j];
				edgeCount++;
			}
		}
	}
	qsort(edges, edgeCount, sizeof(Edge), compare);
	int *parent = (int *)malloc(V * sizeof(int));
	for (int i = 0; i < V; i++) parent[i] = i;
	int minCost = 0, count = 0;
	for ( int i = 0; i < edgeCount && count < V - 1; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int set_u = find(parent, u);
		int set_v = find(parent, v);
		if(set_u != set_v){
			printf("Edge %d:(%d, %d) cost:%d\n", count, u, v, edges[i].cost);
			minCost += edges[i].cost;
			union_set(parent, set_u, set_v);
			count++;
		}
	}
	printf("Minimum cost= %d\n", minCost);
	free(edges);

	free(parent);
	
	
	
	
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}

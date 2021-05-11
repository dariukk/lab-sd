#include "graph.h"

void dfs(w_graph *graph, int *visited, int node)
{
    visited[node] = 1;

    for (int i = 0; i < graph->num_nodes; ++i)
        if (graph->adj_mat[node][i] == 1 && visited[i] == 0)
            dfs(graph, visited, i);

    printf("%d ", node);
}

void topologicalSort(w_graph *graph, int *visited, int node)
{
    for (int i = 0; i < graph->num_nodes; ++i)
        if (visited[i] == 0)
            dfs(graph, visited, i);
}

void dijkstra(w_graph *graph, int source)
{
    int *visited = (int *)calloc(graph->num_nodes, sizeof(int));
    int *dist = (int *)malloc(graph->num_nodes * sizeof(int));

    // initializari
    for (int i = 0; i < graph->num_nodes; ++i)
    {
        dist[i] = inf;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int i = 0; i < graph->num_nodes - 1; ++i)
    {
        // aflu distanta minima de la un nod nevizitat la source
        int node, min = inf;
        for (int j = 0; j < graph->num_nodes; ++j)
            if (visited[j] == 0 && min > dist[j])
            {
                min = dist[j];
                node = j;
            }

        visited[node] = 1;

        if (dist[node] != inf)
            for (int j = 0; j < graph->num_nodes; ++j)
                if (visited[j] == 0 && graph->adj_mat[node][j] &&
                    dist[node] + graph->adj_mat[node][j] < dist[j])
                    dist[j] = dist[node] + graph->adj_mat[node][j];
    }

    for (int i = 0; i < graph->num_nodes; ++i)
        printf("Distanta minima de la %d la %d : %d\n", source, i, dist[i]);

    free(dist);
    free(visited);
}

void bellman_ford(w_graph *graph, int source)
{
    int *visited = (int *)calloc(graph->num_nodes, sizeof(int));
    int *dist = (int *)malloc(graph->num_nodes * sizeof(int));

    // initializari
    for (int i = 0; i < graph->num_nodes; ++i)
    {
        dist[i] = inf;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int i = 0; i < graph->num_nodes - 1; ++i)
        for (int j = 0; j < graph->num_nodes; ++j)
            for (int k = 0; k < graph->num_nodes; ++k)
                if (graph->adj_mat[j][k] != 0)
                    if (dist[k] > dist[j] + graph->adj_mat[j][k])
                        dist[k] = dist[j] + graph->adj_mat[j][k];

    for (int i = 0; i < graph->num_nodes; ++i)
        for (int j = 0; j < graph->num_nodes; ++j)
            if (dist[j] > dist[i] + graph->adj_mat[i][j] &&
                graph->adj_mat[i][j] != 0)
            {
                printf("Negative Cycle\n");
                return;
            }

    for (int i = 0; i < graph->num_nodes; ++i)
        printf("Distanta minima de la %d la %d : %d\n", source, i, dist[i]);

    free(dist);
    free(visited);
}
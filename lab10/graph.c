#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

w_graph *init_graph(int n)
{
    w_graph *graph = (w_graph *)malloc(sizeof(w_graph));
    graph->num_nodes = n;

    graph->adj_mat = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; ++i)
        graph->adj_mat[i] = (int *)calloc(n, sizeof(int));

    return graph;
}

void insert_edge(w_graph *graph, int from, int to, int weight)
{
    graph->adj_mat[from][to] = weight;
}

void remove_edge(w_graph *graph, int from, int to)
{
    graph->adj_mat[from][to] = 0;
}

void destroy_graph(w_graph *graph)
{
    for (int i = 0; i < graph->num_nodes; ++i)
        free(graph->adj_mat[i]);

    free(graph->adj_mat);
    free(graph);
}

void print_adj_matrix(w_graph *g)
{
    for (int i = 0; i < g->num_nodes; i++)
    {
        for (int j = 0; j < g->num_nodes; j++)
        {
            printf("%d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}
#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

weighted_graph_t *init_graph(int n)
{
    weighted_graph_t *graph = (weighted_graph_t *)malloc(sizeof(weighted_graph_t));
    graph->num_nodes = n;
    graph->num_edges = 0;

    graph->adj_mat = (double **)malloc(sizeof(double *) * n);

    for (int i = 0; i < n; ++i)
    {
        graph->adj_mat[i] = (double *)calloc(n, sizeof(double));

        for (int j = 0; j < n; ++j)
            graph->adj_mat[i][j] = inf;
    }

    return graph;
}

void insert_edge(weighted_graph_t *graph, int from, int to, int weight)
{
    graph->adj_mat[from][to] = weight;
}

void insert_edge_undirected(weighted_graph_t *graph, int from, int to, int weight)
{
    graph->adj_mat[from][to] = weight;
    graph->adj_mat[to][from] = weight;
}
void destroy_graph(weighted_graph_t *graph)
{
    for (int i = 0; i < graph->num_nodes; ++i)
        free(graph->adj_mat[i]);

    free(graph->adj_mat);
    free(graph);
}

void print_adj_matrix(weighted_graph_t *g)
{
    for (int i = 0; i < g->num_nodes; i++)
    {
        for (int j = 0; j < g->num_nodes; j++)
        {
            printf("%lf ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}
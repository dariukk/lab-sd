#include "graph.h"
#include "dequeue.h"

#include <stdio.h>
#include <stdlib.h>

u_graph *init_graph(int n)
{
    u_graph *graph = (u_graph *)malloc(sizeof(u_graph));
    graph->num_nodes = n;

    graph->adj_mat = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i)
        graph->adj_mat[i] = (int *)calloc(n, sizeof(int));

    return graph;
}

void insert_edge(u_graph *graph, int from, int to)
{
    graph->adj_mat[from][to] = 1;
    graph->adj_mat[to][from] = 1;
}

void remove_edge(u_graph *graph, int from, int to)
{
    graph->adj_mat[from][to] = 0;
    graph->adj_mat[to][from] = 0;
}

void destroy_graph(u_graph *graph)
{
    for (int i = 0; i < graph->num_nodes; ++i)
        free(graph->adj_mat[i]);

    free(graph->adj_mat);
    free(graph);
}

void dfs_recursive(u_graph *graph, int source, int *visited)
{
    visited[source] = 1;
    printf("%d ", source);

    for (int node = 0; node < graph->num_nodes; ++node)
        if (graph->adj_mat[node][source] && !visited[node])
            dfs_recursive(graph, node, visited);
}

void dfs_iterative(u_graph *graph, int source)
{
    dequeue_t *stack = alloc_deq();
    int *visited = calloc(graph->num_nodes, sizeof(int));
    push_back(stack, source);

    while (size(stack))
    {
        int now;

        back(stack, &now);
        pop_back(stack);

        if (!visited[now])
        {
            printf("%d ", now);
            visited[now] = 1;
        }

        for (int node = graph->num_nodes - 1; node >= 0; --node)
            if (graph->adj_mat[node][now] && !visited[node])
                push_back(stack, node);
    }
}

// Parcurge graful pe nivel folosind apeluri recursive.
void bfs_recursive(u_graph *graph, dequeue_t *queue, int *visited)
{
    if (!size(queue))
        return;

    int node;
    front(queue, &node);

    printf("%d ", node);

    for (int i = 0; i < graph->num_nodes; ++i)
        if (graph->adj_mat[i][node] && !visited[i])
        {
            visited[i] = 1;
            push_back(queue, i);
        }

    pop_front(queue);

    bfs_recursive(graph, queue, visited);
}

void bfs_iterative(u_graph *graph, int source)
{
    dequeue_t *queue = alloc_deq();
    int *visited = calloc(graph->num_nodes, sizeof(int));

    visited[source] = 1;
    push_back(queue, source);

    while (size(queue))
    {
        int node;
        front(queue, &node);

        printf("%d ", node);

        for (int i = 0; i < graph->num_nodes; ++i)
            if (graph->adj_mat[i][node] && !visited[i])
            {
                visited[i] = 1;
                push_back(queue, i);
            }

        pop_front(queue);
    }
}

int num_connected_components(u_graph *graph)
{
    int *visited = calloc(graph->num_nodes, sizeof(int));
    int numComp = 0;

    for (int i = 0; i < graph->num_nodes; ++i)
        if (!visited[i])
        {
            numComp++;
            dfs_recursive(graph, i, visited);
        }

    return numComp;
}

void print_adj_matrix(u_graph *g)
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

#include "graph.h"

int comp(const void *a, const void *b)
{
    weighted_edge_t *c = (weighted_edge_t *)a;
    weighted_edge_t *d = (weighted_edge_t *)b;

    return c->weight > d->weight;
}

int group_id(int parent[], int x)
{
    if (parent[x] != x)
        parent[x] = group_id(parent, parent[x]);

    return parent[x];
}

void merge(int parent[], int x, int y)
{
    x = group_id(parent, x);
    y = group_id(parent, y);
    parent[x] = y;
}

double minimum_spanning_tree(weighted_graph_t *graph)
{
    weighted_edge_t *edges = ugraph_get_all_edges(graph);
    double answer = 0;

    // sortez vectorul de muchii
    qsort(edges, graph->num_edges, sizeof(edges[0]), comp);

    // parent [i] = parintele lui i in arborele minim de acoperire
    int *parent = (int *)malloc(graph->num_nodes * sizeof(int));

    // initial parent[i] = i, i = 0 : num_node -1
    for (int i = 0; i < graph->num_nodes; ++i)
        parent[i] = i;

    int num_edges_ama = 0, i = 0;

    while (num_edges_ama < graph->num_nodes - 1 && i < graph->num_edges)
    {
        weighted_edge_t current_edge = edges[i++];

        int from = group_id(parent, current_edge.from);
        int to = group_id(parent, current_edge.to);

        if (to != from)
        {
            answer += graph->adj_mat[current_edge.from][current_edge.to];
            merge(parent, from, to);
            num_edges_ama++;
        }
    }

    return answer;
}
#include "graph.h"

weighted_edge_t *graph_get_all_edges(weighted_graph_t *graph)
{
    weighted_edge_t *answer = (weighted_edge_t *)malloc(1000 * sizeof(weighted_edge_t));
    int num_edges = 0;

    for (int i = 0; i < graph->num_nodes; ++i)
        for (int j = 0; j < graph->num_nodes; ++j)
            if (graph->adj_mat[i][j] != inf)
            {
                answer[num_edges].from = i;
                answer[num_edges].to = j;
                answer[num_edges].weight = graph->adj_mat[i][j];
                ++num_edges;

                // ma aflu la finalul vectorului
                answer[num_edges].from = -1;
            }

    graph->num_edges = num_edges;
    return answer;
}

weighted_edge_t *ugraph_get_all_edges(weighted_graph_t *graph)
{
    weighted_edge_t *answer = (weighted_edge_t *)malloc(1000 * sizeof(weighted_edge_t));
    int num_edges = 0;

    for (int i = 0; i < graph->num_nodes; ++i)
        for (int j = i + 1; j < graph->num_nodes; ++j)
            if (graph->adj_mat[i][j] != inf)
            {
                answer[num_edges].from = i;
                answer[num_edges].to = j;
                answer[num_edges].weight = graph->adj_mat[i][j];
                ++num_edges;

                // ma aflu la finalul vectorului
                answer[num_edges].from = -1;
            }

    graph->num_edges = num_edges;
    return answer;
}

void print_edges_vector(weighted_edge_t *vect)
{
    for (int i = 0; vect[i].from != -1; ++i)
        printf("Muchie de la %ld la %ld de cost %.2lf\n",
               vect[i].from, vect[i].to, vect[i].weight);
}
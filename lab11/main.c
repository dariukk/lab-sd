#include "graph.h"

int main()
{
    // test exercitiul 1
    weighted_graph_t *graph = init_graph(5);

    printf("----------exercitiul 1------------\n");
    insert_edge(graph, 0, 1, 4);
    insert_edge(graph, 0, 2, 2);
    insert_edge(graph, 1, 2, 3);
    insert_edge(graph, 2, 1, 1);
    insert_edge(graph, 1, 3, 2);
    insert_edge(graph, 1, 4, 3);
    insert_edge(graph, 2, 3, 4);
    insert_edge(graph, 4, 3, 1);

    printf("\n");

    weighted_edge_t *vect = graph_get_all_edges(graph);
    print_edges_vector(vect);

    destroy_graph(graph);
    free(vect);
    printf("\n");

    // test exercitiul 2
    graph = init_graph(4);

    printf("----------exercitiul 2------------\n");
    insert_edge_undirected(graph, 0, 1, 10);
    insert_edge_undirected(graph, 0, 2, 6);
    insert_edge_undirected(graph, 0, 3, 5);
    insert_edge_undirected(graph, 1, 3, 15);
    insert_edge_undirected(graph, 2, 3, 4);

    printf("\n");

    printf("Arborele de acoperire minim are ponderea %.2lf",
           minimum_spanning_tree(graph));

    destroy_graph(graph);
    printf("\n");
}
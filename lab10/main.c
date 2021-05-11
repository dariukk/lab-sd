#include "graph.h"

int main()
{
    // test exercitiul 1
    w_graph *graph = init_graph(5);

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
    print_adj_matrix(graph);
    destroy_graph(graph);
    printf("\n");

    printf("----------exercitiul 2------------\n");
    printf("-------sortare topologica---------\n");
    graph = init_graph(6);

    insert_edge(graph, 2, 3, 1);
    insert_edge(graph, 3, 1, 1);
    insert_edge(graph, 4, 1, 1);
    insert_edge(graph, 4, 0, 1);
    insert_edge(graph, 5, 0, 1);
    insert_edge(graph, 5, 2, 1);

    printf("\n");
    print_adj_matrix(graph);
    printf("\n");

    int *visited = (int *)calloc(6, sizeof(int));
    topologicalSort(graph, visited, 0);
    printf("\n\n");

    destroy_graph(graph);
    free(visited);

    printf("----------exercitiul 3------------\n");
    printf("------------dijkstra--------------\n");
    graph = init_graph(5);

    insert_edge(graph, 0, 1, 4);
    insert_edge(graph, 0, 2, 2);
    insert_edge(graph, 1, 2, 3);
    insert_edge(graph, 2, 1, 1);
    insert_edge(graph, 1, 3, 2);
    insert_edge(graph, 1, 4, 3);
    insert_edge(graph, 2, 3, 4);
    insert_edge(graph, 4, 3, 1);

    printf("\n");
    dijkstra(graph, 0);
    destroy_graph(graph);
    printf("\n");

    printf("----------exercitiul 4------------\n");
    printf("----------Bellman Ford------------\n");
    graph = init_graph(5);

    insert_edge(graph, 0, 1, 1);
    insert_edge(graph, 1, 3, 2);
    insert_edge(graph, 3, 4, 3);
    insert_edge(graph, 0, 2, 10);
    insert_edge(graph, 2, 3, -10);

    printf("\n");
    print_adj_matrix(graph);
    printf("\n");
    bellman_ford(graph, 0);
    destroy_graph(graph);
    printf("\n");
}
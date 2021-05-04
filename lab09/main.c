#include "dequeue.h"
#include "graph.h"

#include <assert.h>
#include <stdio.h>

int main()
{
    ///////////////////// INIT_GRAPH //////////////////////////
    u_graph *g = init_graph(8);

    ///////////////////// INSERT_EDGE //////////////////////////
    printf("----------INSERT_EDGE----------\n");
    insert_edge(g, 0, 2);
    insert_edge(g, 1, 2);
    insert_edge(g, 1, 6);
    insert_edge(g, 2, 4);
    insert_edge(g, 3, 7);
    insert_edge(g, 4, 6);
    insert_edge(g, 4, 7);
    insert_edge(g, 5, 7);
    insert_edge(g, 6, 7);
    insert_edge(g, 7, 2);

    assert(g->adj_mat[7][2] == 1);
    assert(g->adj_mat[2][7] == 1);
    print_adj_matrix(g);

    // ///////////////////// REMOVE_EDGE //////////////////////////
    printf("----------REMOVE_EDGE----------\n");
    remove_edge(g, 7, 2);
    assert(g->adj_mat[7][2] == 0);
    assert(g->adj_mat[2][7] == 0);
    print_adj_matrix(g);

    // //////////////////// DFS_RECURSIVE //////////////////////////
    printf("----------DFS_RECURSIVE----------\n");
    int *dfs_visited = calloc(g->num_nodes, sizeof(int));
    dfs_recursive(g, 1, dfs_visited);
    free(dfs_visited);
    printf("\n");

    // //////////////////// DFS_ITERATIVE //////////////////////////
    printf("----------DFS_ITERATIVE----------\n");
    dfs_iterative(g, 1);
    printf("\n");

    // //////////////////// BFS_RECURSIVE //////////////////////////
    printf("----------BFS_RECURSIVE----------\n");
    dequeue_t *q = alloc_deq();
    int *bfs_visited = calloc(g->num_nodes, sizeof(int));

    push_front(q, 1);
    bfs_visited[1] = 1;

    bfs_recursive(g, q, bfs_visited);
    printf("\n");

    // //////////////////// BFS_ITERATIVE //////////////////////////
    printf("----------BFS_ITERATIVE----------\n");
    bfs_iterative(g, 1);
    printf("\n");

    free(bfs_visited);

    // //////////////////// DESTROY_GRAPH //////////////////////////
    printf("----------DESTROY_GRAPH----------\n");
    destroy_graph(g);

    // //////////////////// NUM_CONNECTED_COMPONENTS //////////////////////////
    printf("----------NUM_CONNECTED_COMPONENTS----------\n");
    u_graph *g2 = init_graph(6);
    print_adj_matrix(g2);
    insert_edge(g2, 1, 5);
    insert_edge(g2, 0, 2);
    insert_edge(g2, 2, 4);

    print_adj_matrix(g2);
    printf("\n");

    printf("Number of connected components:%d\n", num_connected_components(g2));
    destroy_graph(g2);
    return 0;
}

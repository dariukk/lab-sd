#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#define inf 100000

typedef struct directedGraph
{
    int num_nodes;
    int **adj_mat;
} w_graph;

// Initializeaza un graf cu n noduri. (0.5 puncte)
w_graph *init_graph(int n);

// Insereaza o noua muchie in graf, de la nodul `from` la nodul `to` (0.5 puncte)
void insert_edge(w_graph *graph, int from, int to, int weight);

// Sterge o muchie din graf (0.5 puncte)
void remove_edge(w_graph *graph, int from, int to);

// Sterge si elibereaza memoria alocata grafului. (0.5 puncte)
void destroy_graph(w_graph *graph);

// Afiseaza matricea de adiacenta
void print_adj_matrix(w_graph *g);

// Sortare topologica
void topologicalSort(w_graph *graph, int *visited, int node);

// algoritmul dijkstra
void dijkstra(w_graph *graph, int source);

// algoritmul bellman-ford
void bellman_ford(w_graph *graph, int source);

#endif
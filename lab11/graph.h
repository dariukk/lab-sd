#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#define inf 10000000

typedef struct directedGraph
{
    size_t num_nodes;
    size_t num_edges;
    double **adj_mat;
} weighted_graph_t;

typedef struct
{
    size_t from;
    size_t to;
    double weight;
} weighted_edge_t;

// Initializeaza un graf cu n noduri.
weighted_graph_t *init_graph(int n);

// Insereaza o noua muchie in graf (pt graful orientat)
void insert_edge(weighted_graph_t *graph, int from, int to, int weight);

// Insereaza o noua muchie (pt graful neorientat)
void insert_edge_undirected(weighted_graph_t *graph, int from, int to, int weight);

// Sterge si elibereaza memoria alocata grafului.
void destroy_graph(weighted_graph_t *graph);

// Afiseaza matricea de adiacenta
void print_adj_matrix(weighted_graph_t *g);

// Returneaza vectorul muchiilor
weighted_edge_t *graph_get_all_edges(weighted_graph_t *graph);

// Returneaza vectorul muchiilor (pt graful neorietat)
weighted_edge_t *ugraph_get_all_edges(weighted_graph_t *graph);

// Afiseaza vectorul muchiilor
void print_edges_vector(weighted_edge_t *vect);

// Arbore minim de acoperire
double minimum_spanning_tree(weighted_graph_t *graph);

#endif
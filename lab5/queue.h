#ifndef QUEUE_H_
#define QUEUE_H_

#ifndef NODE
#define NODE

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

#endif

typedef struct
{
    int size;
    Node *front, *back;
} Queue;

// Initializeaza o coada. (0.5 p)
Queue *init_queue();

// Returneaza 1 daca coada este goala si 0 in caz contrar. (0.5 puncte)
int is_empty_queue(Queue *q);

// Returneaza numarul de elemente din coada. (0.5 puncte).
int queue_size(Queue *q);

// Adauga un element in coada. (0.5 puncte)
void enqueue(Queue *q, int x);

// Sterge si dezaloca ultimul element din coada. (Intoarce 1 daca operatia a reusit si 0 in caz contrar) (0.5 puncte)
int dequeue(Queue *q);

// Returneaza elementul din varful cozii. (0.5 puncte)
int front(Queue *q);

// Afiseaza elementele din coada.
void print_queue(Queue *q);

#endif
#ifndef STACK_H_
#define STACK_H_

#ifndef NODE
#define NODE

typedef struct Node {
    double value;
    struct Node *next;
} Node;

#endif

typedef struct {
    int size;
    Node *top;
} Stack;

// Initializeaza o stiva. (0.5 p)
Stack* init_stack();

// Returneaza 1 daca stiva este goala si 0 in caz contrar. (0.5 puncte)
int is_empty_stack(Stack *s);

// Returneaza numarul de elemente din stiva. (0.5 puncte).
int stack_size(Stack *s);

// Returneaza elementul din varful stivei. (0.5 puncte)
double top(Stack *s);

// Adauga un element in stiva. (0.5 p)
void push(Stack *s, double x);

// Sterge (si dezaloca) elementul din varful stivei. (Intoarce 1 daca operatia a reusit si 0 in caz contrar) (0.5 p)
int pop(Stack *s);

// Afiseaza elementele din stiva.
void print_stack(Stack *s);

#endif
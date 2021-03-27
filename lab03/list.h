#ifndef __LIST_H__
#define __LIST_H__

typedef struct List {
    int value;
    struct List *next;
} List;

//TODO: Sa se implementeze urmatoarele functii:

// Returneaza 1 daca lista este goala, 0 in caz contrar. (1 punct)
int is_empty(List *list);

// Insereaza un nou element in lista. (2 puncte)
void insert(List **list, int value);

// Sterge prima aparitie a unui element din lista. (2 puncte)
void delete(List **list, int value);

// Returneaza lungimea listei. (1 punct)
int get_length(List *list);

// Sterge toate elementele din lista. (1 punct)
void delete_all(List **list);

// Returneaza 1 daca elementul se afla in lista, sau 0 in caz contrar. (1 punct)
int contains(List *list, int value);

// Sa se determine al K-lea element de la final. (Returneaza -1 daca k > lungimea listei) (2 puncte)
int get_kth_last_elem(List *list, int k);

// Afiseaza elementele din lista.
void print_list(List *list);

#endif
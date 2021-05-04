#ifndef _HEAP_H
#define _HEAP_H

typedef struct heap {
    int *arr;  
    int size; 
    int capacity; 
} heap;

/* Initializeaza coada de prioritati. */
heap *init_heap(int capacity);

/* Insereaza un nou element in heap. (Cand se va atinge capacitatea maxima a
heap-ului nu se vor mai putea insera elemente) */
void insert(heap *h, int value);

/* Sterge elementul maxim si reface proprietatea cozii de prioritati. */
int delete_max(heap *h);

/* Propaga in jos in heap valoarea nodului de pe pozitia i astfel incat sa se 
refaca propietatea heap-ului. */
void heapify(heap *h, int i);

/* Afiseaza elementele din heap. */
void print_heap(heap *h);

#endif

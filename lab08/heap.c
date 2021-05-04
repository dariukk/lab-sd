#include "heap.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Returneaza indexul parintelui nodului n. */
static int get_parent(int n)
{
    if (n == 0)
        return -1;

    return (n - 1) / 2;
}

/* Returneaza indexul copilului stang al nodului n. */
static int get_left_child(int n)
{
    return 2 * n + 1;
}

/* Returneaza indexul copilului drept al nodului n. */
static int get_right_child(int n)
{
    return 2 * n + 2;
}

/* Initializeaza coada de prioritati. */
heap *init_heap(int capacity)
{
    heap *h = (heap *)malloc(sizeof(heap));

    h->arr = malloc((capacity + 1) * sizeof(int));
    h->size = 0;
    h->capacity = capacity;

    return h;
}

void swap(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/* Insereaza un nou element in heap. (Cand se va atinge capacitatea maxima a
heap-ului nu se vor mai putea insera elemente) */
void insert(heap *h, int value)
{
    // TODO 5 (2 puncte)

    // Verificam daca mai este suficient spatiu pentru a insera un nou element.
    if (h->size == h->capacity)
        return;

    // Adaugam elementul in heap
    h->arr[h->size] = value;
    h->size++;

    // Filtram in sus nodul pana cand ajunge sa aiba un parinte cu o valoare mai mare (max heap)
    int pos = h->size - 1;
    int parent = get_parent(pos);

    while (h->arr[pos] > h->arr[parent] && pos > 0)
    {
        swap(&h->arr[pos], &h->arr[parent]);

        pos = parent;
        parent = get_parent(pos);
    }
}

/* Propaga in jos in heap valoarea nodului de pe pozitia i astfel incat sa se 
refaca propietatea heap-ului. */
void heapify(heap *h, int i)
{
    int left = get_left_child(i);
    int right = get_right_child(i);

    if (right >= h->size)
        return;

    if (h->arr[left] < h->arr[right])
    {
        if (h->arr[right] > h->arr[i])
        {
            swap(&h->arr[i], &h->arr[right]);
            heapify(h, right);
        }
    }
    else
    {
        if (h->arr[left] > h->arr[i])
        {
            swap(&h->arr[i], &h->arr[left]);
            heapify(h, left);
        }
    }
}

/* Sterge elementul maxim si reface proprietatea cozii de prioritati. */
int delete_max(heap *h)
{
    int value = h->arr[0];

    swap(&h->arr[0], &h->arr[h->size - 1]);
    h->size--;

    heapify(h, 0);

    return value;
}

void print_heap(heap *h)
{
    printf("[");
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("]\n");
}

/* Sorteaza un vector v cu n elemente, folosind heap-ul implementat anterior.
 Functia va returna vectorul sortat crescator. */
static int *heap_sort(int *v, int n)
{
    heap *h = init_heap(n);

    // construiesc heap-ul
    for (int i = 0; i < n; ++i)
        insert(h, v[i]);

    while (h->size)
        delete_max(h);

    return h->arr;
}

int main()
{
    heap *h = init_heap(10);

    /////////////////////// INIT_HEAP ///////////////////////
    assert(h != NULL && h->arr != NULL && h->size == 0 && h->capacity == 10);

    /////////////////////// INSERT ///////////////////////
    int v[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int v_size = sizeof(v) / sizeof(v[0]);

    for (int i = 0; i < v_size; i++)
    {
        insert(h, v[i]);
    }

    insert(h, 0); // This value should not be inserted (the heap is already full)

    printf("Test insert: ");
    print_heap(h); // Should print [44 42 35 33 31 19 27 10 26 14]
    assert(h->size == v_size);
    assert(get_parent(0) < 0);
    assert(h->arr[get_parent(2)] == 44);
    assert(h->arr[get_left_child(2)] == 19);
    assert(h->arr[get_right_child(1)] == 31);

    /////////////////////// DELETE & HEAPIFY ///////////////////////
    assert(delete_max(h) == 44);
    printf("Test delete: ");
    print_heap(h);
    assert(delete_max(h) == 42);
    printf("Test delete: ");
    print_heap(h);

    /////////////////////// HEAPSORT ///////////////////////
    int arr[] = {9, 6, 8, 3, 1, 7, 8, 4, 12};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int *sorted_arr = heap_sort(arr, arr_size);
    printf("Sorted array: [");

    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", sorted_arr[i]);
    }
    printf("]\n");
    return 0;
}

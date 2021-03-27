#include "list.h"
#include <stdlib.h>
#include <stdio.h>

//TODO: Sa se implementeze urmatoarele functii:

int is_empty(List *list)
{
    if (list == NULL)
        return 1;
    return 0;
}

void print_list(List *list)
{
    List *it = list;
    while (it != NULL)
    {
        printf("%d->", it->value);
        it = it->next;
    }
    printf("NULL\n");
}

void insert(List **list, int value)
{
    struct List *new_elem;
    new_elem = (struct List *)malloc(sizeof(struct List *));

    new_elem->value = value;
    new_elem->next = NULL;

    if (is_empty(*list))
    {
        *list = new_elem;
        return;
    }

    struct List *it = *list;
    while (it->next != NULL)
        it = it->next;

    it->next = new_elem;
}

void delete (List **list, int value)
{
    struct List *it = *list, *prev = *list;
    int ok = 0;

    while (it != NULL)
    {
        if (it->value == value)
        {
            ok = 1;
            break;
        }
        prev = it;
        it = it->next;
    }

    if (ok)
    {
        if (it == prev)
            *list = it->next;
        else
            prev->next = it->next;
    }

    free(it);
}

void reverse(List **list)
{
    int nr = 0, aux;
    for (List *it = *list; it != NULL; it = it->next)
        nr++;

    List *it = *list;
    for (int i = 1; i <= nr / 2; ++i)
    {
        List *it2 = *list;
        for (int j = 1; j < nr - i + 1; ++j)
            it2 = it2->next;

        aux = it->value;
        it->value = it2->value;
        it2->value = aux;

        it = it->next;
    }
}

void delete_all(List **list)
{
    struct List *it = *list, *next;

    while (it != NULL)
    {
        next = it->next;
        free(it);
        it = next;
    }

    *list = NULL;
}

int get_length(List *list)
{
    struct List *it = list;
    int length = 0;

    while (it != NULL)
    {
        ++length;
        it = it->next;
    }

    return length;
}

int contains(List *list, int value)
{
    int ok = 0;
    struct List *it = list;

    while (it->next != NULL)
    {
        if (it->value == value)
        {
            ok = 1;
            break;
        }
        it = it->next;
    }

    return ok;
}

int get_kth_last_elem(List *list, int k)
{
    struct List *it = list;
    int n = get_length(list);

    if (n < k)
        return -1;

    k = n - k;

    while (it != NULL && k)
    {
        --k;
        it = it->next;
    }

    return it->value;
}

int main()
{
    List *list = NULL;

    ///////////////////////// IS_EMPTY ////////////////////////////
    printf("Test 1 is_empty: %d\n", is_empty(list)); // is_empty -> 1

    insert(&list, 7);
    printf("Test 2 is_empty: %d\n\n", is_empty(list)); // is_empty -> 0

    // ///////////////////////// INSERT & PRINT_LIST ////////////////////////////
    insert(&list, 10);
    insert(&list, 30);
    insert(&list, 3);
    insert(&list, 12);
    insert(&list, 30);
    printf("Test insert & print_list: ");
    print_list(list); // Should print 7->10->30->3->12-30->NULL
    printf("\n");
    reverse(&list);
    print_list(list);

    // ///////////////////////// CONTAINS ////////////////////////////
    printf("Test 1 contains(list, 12): %d\n", contains(list, 12)); // contains(list,12) -> 1
    printf("Test 2 contains(list, 5): %d\n\n", contains(list, 5)); // contains(list,5) -> 0

    // ///////////////////////// DELETE ////////////////////////////
    delete (&list, 30);
    delete (&list, 30);
    printf("Test delete(list, 30) (twice): ");
    print_list(list); // Should print 7->10->3->12->NULL

    delete (&list, 7);
    printf("Test delete(list, 7): ");
    print_list(list); // Should print 10->3->12->NULL
    printf("\n");

    // ///////////////////////// GET_LENGTH ////////////////////////////
    printf("Test get_length: %d\n", get_length(list)); // 3
    printf("\n");

    // ///////////////////////// DELETE_ALL ////////////////////////////
    delete_all(&list);
    printf("Test delete_all: ");
    print_list(list); // Should print NULL
    printf("\n");

    // ///////////////////////// GET_KTH_LAST_ELEM ////////////////////////////
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    insert(&list, 9);
    insert(&list, 7);
    print_list(list);                                                            // Should print 10->20->30->1->2->3->9->7->NULL
    printf("Test get_kth_last_elem(list, 9): %d\n", get_kth_last_elem(list, 9)); // Should print -1
    printf("Test get_kth_last_elem(list, 5): %d\n", get_kth_last_elem(list, 5)); // Should print 1

    return 0;
}
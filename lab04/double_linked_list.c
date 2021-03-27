#include "double_linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// Initializeaza o lista dublu inlantuita. (0.5 puncte)
List *init_list()
{
    List *list;
    list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Returneaza 1 daca lista este goala, 0 in caz contrar. (0.5 puncte)
int is_empty(List *list)
{
    if (list->head == NULL && list->tail == NULL)
        return 1;
    return 0;
}

// Returneaza 1 daca elementul se afla in lista, sau 0 in caz contrar. (1 punct)
int contains(List *list, T value)
{
    for (ListNode *node = list->head; node != NULL; node = node->next)
        if (node->value == value)
            return 1;

    return 0;
}

// Returneaza lungimea listei (1 punct)
int get_length(List *list)
{
    int num = 0;

    for (ListNode *node = list->head; node != NULL; node = node->next)
        num++;

    return num;
}

// Insereaza un nou element la finalul listei. (1 punct)
void insert(List *list, T value)
{
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->value = value;

    if (list->tail == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
        return;
    }

    list->tail->next = new_node;
    new_node->prev = list->tail;
    new_node->next = NULL;
    list->tail = new_node;

}

// Insereaza un nou element astfel incat lista sa ramana in continuare sortata. (2 puncte)
void insert_in_order(List *list, T value)
{
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->value = value;

    if (list->tail == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
        return;
    }

    if (value <= list->head->value)
    {
        new_node->prev = NULL;
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
        return;
    }

    if (value >= list->tail->value)
    {
        new_node->next = NULL;
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
        return;
    }

    for (ListNode *node = list->head; node != NULL; node = node->next)
        if (node->value <= value && value <= node->next->value)
        {
            ListNode *next = node->next;
            node->next = new_node;
            next->prev = new_node;
            new_node->prev = node;
            new_node->next = next;
            return;
        }
}

// Sterge si dezaloca din memorie prima aparitie a unui element din lista. (1 punct)
void delete (List *list, T value)
{
    if (list->head->value == value)
    {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
        return;
    }

    if (list->tail->value == value)
    {
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
        return;
    }

    for (ListNode *node = list->head; node != NULL; node = node->next)
        if (node->value == value)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            free(node);
            return;
        }
}

// Sterge si dezaloca din memorie toate elementele din lista. (1 punct)
void destroy_list(List *list)
{
    ListNode *node = list->head->next;
    list->head = NULL;
    free(list->head);

    while (node != list->tail)
    {
        ListNode *next = node->next;
        node = NULL;
        free(node);
        node = next;
    }

    list->tail = NULL;
    free(list->tail);
}

// Primeste o lista sortata si afiseaza toate perechile de numere a caror suma
// este egala cu valoare data. Lista va avea toate elementele distincte. (2 puncte)
void find_pairs_given_sum(List *list, T x)
{
    // TODO

    ListNode *head = list->head, *tail = list->tail;
    int sum;

    while (head->value < tail->value)
    {
        sum = head->value + tail->value;

        if (sum == x)
        {
            printf("(%d %d)\n", head->value, tail->value);
            head = head->next;
            tail = tail->prev;
        }
        else if (sum < x)
            head = head->next;
        else
            tail = tail->prev;
    }
}

void print_list(List *list)
{
    for (ListNode *it = list->head; it != NULL; it = it->next)
    {
        printf("%d->", it->value);
    }
    printf("NULL\n");
}

void print_list_reversed(List *list)
{
    for (ListNode *it = list->tail; it != NULL; it = it->prev)
    {
        printf("%d->", it->value);
    }
    printf("NULL\n");
}

int main()
{
    List *list = init_list();

    ///////////////// IS_EMPTY /////////////////
    printf("Test 1 (is_empty): %d\n", is_empty(list)); // Should be 1

    // ///////////////// INSERT /////////////////
    insert(list, 1);
    insert(list, 20);
    insert(list, 2);
    insert(list, 10);
    insert(list, 5);
    printf("Test 2 (is_empty): %d\n\n", is_empty(list)); // Should be 0

    printf("Test 3 (insert):");
    print_list(list); // 1->20->2->10->5->NULL

    printf("Test 4 (insert):");
    print_list_reversed(list); // 5->10->2->20->1->NULL
    printf("\n");

    // ///////////////// CONTAINS /////////////////
    printf("Test 5 contains(list, 2): %d\n", contains(list, 2));     // Should be 1
    printf("Test 6 contains(list, 22): %d\n\n", contains(list, 22)); // Should be 0

    // ///////////////// GET_LENGTH /////////////////
    printf("Test 7 get_length(list): %d\n\n", get_length(list)); // Should be 5

    // ///////////////// DELETE /////////////////
    printf("Test 8 delete(list, 1):");
    delete (list, 1);
    print_list(list); // 20->2->10->5->NULL
    printf("Test 9 delete(list, 2): ");
    delete (list, 2);
    print_list(list); // 20->10->5->NULL
    printf("Test 10 delete(list, 5):");
    delete (list, 5);
    print_list(list);          // 20->10->NULL
    print_list_reversed(list); // 10->20->NULL
    printf("\n");

    // ///////////////// DELETE_ALL /////////////////
    printf("Test 11 destroy_list(list):");
    insert(list, 1);
    insert(list, 20);
    insert(list, 2);
    insert(list, 10);
    insert(list, 5);
    destroy_list(list);
    print_list(list);          // NULL
    print_list_reversed(list); // NULL
    printf("\n");

    // ///////////////// INSERT_IN_ORDER /////////////////
    List *sorted_list = init_list();
    insert_in_order(sorted_list, 9);
    insert_in_order(sorted_list, 7);
    insert_in_order(sorted_list, 6);
    insert_in_order(sorted_list, 4);
    insert_in_order(sorted_list, 1);
    insert_in_order(sorted_list, 5);
    insert_in_order(sorted_list, 11);
    insert_in_order(sorted_list, 2);
    insert_in_order(sorted_list, 3);

    printf("Test 12 insert_in_order:");
    print_list(sorted_list);          // 1->2->3->4->5->6->7->9->11->NULL
    print_list_reversed(sorted_list); // 11->9->7->6->5->4->3->2->1->NULL

    // ///////////////// FIND_PAIRS_GIVEN_SUM /////////////////
    printf("Test 13 find_pairs_given_sum(list, 14): ");
    find_pairs_given_sum(sorted_list, 14); // (3, 11), (5, 9)

    return 0;
}

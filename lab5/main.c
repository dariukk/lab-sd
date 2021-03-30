#include "queue.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

// TODO 1: Implementati functiile din fisierul stack.c (3 puncte)

// TODO 2: Implementati functiile din fisierul queue.c (3 puncte)

// TODO 3: Folosind o stiva, sa se verifice daca o expresie este bine parantezata. (1.5 puncte)
int is_balanced(char *expr, int n)
{
    Stack *s;
    s = init_stack();

    for (int i = 0; i < n; ++i)
        if (expr[i] == '(')
            push(s, 1);
        else
        {
            int ok = pop(s);
            if (ok == 0)
                return 0;
        }

    if (s->top == NULL)
        return 1;

    return 0;
}

int getMax(int *arr, int n)
{
    int ans = arr[0];

    for (int i = 1; i < n; ++i)
        if (arr[i] > ans)
            ans = arr[i];

    return ans;
}

// TODO 4: Sa se sorteze un vector folosing radix sort. (n - lungimea vectorului) (2.5 puncte)
void radix_sort(int *arr, int n)
{
    int max = getMax(arr, n);

    Queue **q = malloc(10 * sizeof(Queue));
    for (int i = 0; i < 10; ++i)
        q[i] = init_queue();

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        for (int i = 0; i < n; ++i)
            enqueue(q[arr[i] / exp % 10], arr[i]);

        int num = 0;
        for (int i = 0; i < 10; ++i)
            while (!is_empty_queue(q[i]))
            {
                arr[num++] = front(q[i]);
                dequeue(q[i]);
            }
    }
}

int main()
{
    /***************************** STACK ****************************/
    Stack *s = init_stack();

    printf("\n****************** STACK TESTS ***********************\n");

    /////////////// IS_EMPTY_STACK ///////////////
    printf("Test 1 - is_empty_stack: %d (Should be 1)\n", is_empty_stack(s));
    push(s, 5);
    printf("Test 2 - is_empty_stack: %d (Should be 0)\n\n", is_empty_stack(s));

    /////////////// STACK_SIZE & PUSH ///////////////
    push(s, 7);
    push(s, 30);
    push(s, 4);
    push(s, 16);
    printf("Test 3 - stack_size: %d (Should be 5)\n", stack_size(s));
    printf("Test 4 - push:");
    print_stack(s);
    printf(". Should be: [16, 4, 30, 7, 5] \n\n");

    /////////////// TOP & POP///////////////
    printf("Test 5 - top: %f (Should be 16)\n\n", top(s));
    pop(s);
    printf("Test 6 - top: %f (Should be 4)\n\n", top(s));

    pop(s);
    pop(s);
    pop(s);

    printf("Test 7 - pop: %d (Should be 1)\n", pop(s));
    printf("Test 8 - pop: %d (Should be 0)\n\n", pop(s));

    printf("****************** QUEUE TESTS ***********************\n");
    Queue *q = init_queue();

    /////////////// IS_EMPTY_STACK ///////////////
    printf("Test 1 - is_empty_queue: %d (Should be 1)\n", is_empty_queue(q));
    enqueue(q, 5);
    printf("Test 2 - is_empty_queue: %d (Should be 0)\n\n", is_empty_queue(q));

    /////////////// QUEUE_SIZE & ENQUEUE ///////////////
    enqueue(q, 70);
    enqueue(q, 33);
    enqueue(q, 12);
    enqueue(q, 80);
    enqueue(q, 32);
    printf("Test 3 - queue_size: %d (Should be 6)\n", queue_size(q));
    printf("Test 4 - enqueue:");
    print_queue(q);
    printf(". Should be: [5, 70, 33, 12, 80, 32] \n\n");

    /////////////// TOP & DEQUEUE///////////////
    printf("Test 5 - front: %d (Should be 5)\n\n", front(q));
    dequeue(q);
    printf("Test 6 - front: %d (Should be 70)\n\n", front(q));

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("Test 7 - pop: %d (Should be 1)\n", dequeue(q));
    printf("Test 8 - pop: %d (Should be 0)\n\n", dequeue(q));

    /////////////// BALANCED BRACKETS ///////////////
    printf("****************** BALANCED BRACKETS ***********************\n");
    printf("Test 1 is_balanced(\"(((()))()(()))()\", 16): %d. (Should be 1) \n", is_balanced("(((()))()(()))()", 16));
    printf("Test 2 is_balanced(\"(((()\", 4): %d. (Should be 0) \n", is_balanced("(((()", 5));
    printf("Test 3 is_balanced(\"(()))\", 5): %d. (Should be 0) \n\n", is_balanced("(()))", 5));

    /////////////// RADIX SORT ///////////////
    printf("****************** RADIX SORT***********************\n");
    int arr[] = {20, 11, 34, 67, 0, 3, 2, 1, 789, 9999, 567, 123};
    int len = sizeof(arr) / sizeof(*arr);
    radix_sort(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
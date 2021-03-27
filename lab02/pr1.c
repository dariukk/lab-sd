#include <stdio.h>
#include <stdlib.h>

int is_sorted(int v[], int left, int right)
{
    if (left >= right)
        return 1;

    if (left + 1 == right)
    {
        if (v[left] <= v[right])
            return 1;
        return 0;
    }

    int mid = (left + right) / 2, ok;

    ok = is_sorted(v, left, mid);
    ok &= is_sorted(v, mid, right);

    return ok;
}

int main()
{
    int n, *array;
    scanf("%d", &n);

    array = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    int ans = is_sorted(array, 0, n - 1);

    if (ans)
        printf("Yey! Ai un vector sortat :)");
    else
        printf("Nu ai un vector sortat :(");
}
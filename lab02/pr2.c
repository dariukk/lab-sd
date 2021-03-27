#include <stdio.h>
#include <stdlib.h>

int sum(int v[], int left, int right)
{
    if (left > right)
        return 0;

    if (left == right)
        return v[left];

    int mid = (left + right) / 2;
    return sum(v, left, mid) + sum(v, mid + 1, right);
}

int main()
{
    int n, *array;
    scanf("%d", &n);

    array = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    int ans = sum(array, 0, n - 1);

    printf("%d", ans);
}
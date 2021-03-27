#include <stdio.h>
#include <stdlib.h>

int where(int v[], int left, int right, int x)
{
    int mid = (left + right) / 2;

    if (left == right)
        return left;

    if (v[mid] > x)
        return where(v, left, mid - 1, x);
    else
        return where(v, mid, right, x);
}

int main()
{
    int n, *array, x;
    scanf("%d%d", &n, &x);

    array = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    int ans = where(array, 0, n - 1, x);
    printf("%d", ans);
}
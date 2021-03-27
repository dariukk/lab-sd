#include <stdio.h>

int sum(int v[], int n)
{
    if (n - 1 == 0)
        return v[0];
    if ((n - 1) % 2 == 0)
        return v[n - 1] + sum(v, n - 1);
    return -v[n - 1] + sum(v, n - 1);
}

int main()
{
    int v[100], n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    printf("%d", sum(v, n));
}
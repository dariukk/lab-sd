#include <stdio.h>

int putere(int n, int m)
{
    if (m == 0)
        return 1;
    return n * putere(n, m - 1);
}

int main()
{
    printf("%d", putere(2, 3));
}
#include <stdio.h>
#include <string.h>

int palindrom(char s[], int lower, int upper)
{
    if (lower > upper)
        return 1;
    if (s[lower] != s[upper])
        return 0;

    return palindrom(s, lower + 1, upper - 1);
}

int main()
{
    char s[100];
    scanf("%s", s);

    if (palindrom(s, 0, strlen(s) - 1))
        printf("Este palindrom :)");
    else
        printf("Nu este palindrom :(");
}
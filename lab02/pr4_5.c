#include <stdio.h>
#include <stdlib.h>

// algoritmul Merge Sort (problema 5)

// functia de interclasare (problema 4)
void merge(int v[], int left, int mid, int right)
{
    int size_l, size_r;

    size_l = mid - left + 1;
    size_r = right - mid;

    int leftarr[size_l], rightarr[size_r];
    for (int i = 0; i < size_l; ++i)
        leftarr[i] = v[left + i];

    for (int i = 0; i < size_r; ++i)
        rightarr[i] = v[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < size_l && j < size_r)
        if (leftarr[i] < rightarr[j])
            v[k++] = leftarr[i++];
        else
            v[k++] = rightarr[j++];

    while (i < size_l)
        v[k++] = leftarr[i++];

    while (j < size_r)
        v[k++] = rightarr[j++];
}

void mergeSort(int v[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);
    merge(v, left, mid, right);
}

int main()
{
    int n, *array;
    scanf("%d", &n);

    array = (int *)malloc(100 * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", &array[i]);

    mergeSort(array, 0, n - 1);

    printf("Vectorul sortat este\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
}
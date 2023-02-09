#include <stdio.h>

void insersion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i], j;

        for (j = i - 1; j >= 0 && a[j] > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = key;
    }
}

int main()
{
    int n = 6, a[] = {5, 4, 6, 3, 2, 1};
    insersion_sort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]); // 1 2 3 4 5 6
}
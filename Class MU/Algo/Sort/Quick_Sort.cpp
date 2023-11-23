#include <bits/stdc++.h>
using namespace std;

int partition(int l, int r, int *a)
{
    int index = l - 1;
    for (int i = l; i < r; i++)  //took a fix value value to right side
    {
        if (a[i] < a[r])
            swap(a[++index], a[i]); // all of its less value put left side
    }
    swap(a[++index], a[r]);  // than took fix value on middle
    return index;
}

void quickSort(int l, int r, int *a)
{
    if (l < r)
    {
        int m = partition(l, r, a);  // than took fix value on middle
        quickSort(l, m - 1, a);
        quickSort(m + 1, r, a);
    }
}

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(0, n - 1, a);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
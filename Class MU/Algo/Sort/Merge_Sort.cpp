#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void merge(int l, int m, int r, int *a)
{

    int n1 = m - l + 1, n2 = r - m;
    int ll[n1], rr[n2];

    for (int i = 0; i < n1; i++)
    {
        ll[i] = a[l + i]; // at first took value to temporary array l to m
    }

    for (int i = 0; i < n2; i++)
    {
        rr[i] = a[m + i + 1]; // at first took value to temporary array m+1 to r
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) //compare this two temporary array and put value on main array
    {
        if (ll[i] <= rr[j])
        {
            a[k++] = ll[i++];
        }
        else
        {
            a[k++] = rr[j++];
        }
    }

    while (i < n1)         //if any remaining value exist
    {
        a[k++] = ll[i++];
    }

    while (j < n2)
    {
        a[k++] = rr[j++];
    }
}

void mergeSort(int l, int r, int *a)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m, a);
        mergeSort(m + 1, r, a);
        merge(l, m, r, a);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int a[] = {5, 4, 3, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(0, n - 1, a);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
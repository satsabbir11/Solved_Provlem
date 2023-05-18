#include <stdio.h>

void swap(int *a, int *b)
{
  int tem = *a;
  *a = *b;
  *b = tem;
}

int partition(int a[], int l, int h)
{
  int pivot = a[h];
  int i = l - 1;
  for (int j = l; j < h; j++)
  {
    if (a[j] <= pivot)
    {
      i++;
      swap(&a[i], &a[j]);
    }
  }
  swap(&a[i + 1], &a[h]);
  return (i + 1);
}

void quickSort(int a[], int l, int h)
{
  if (l < h)
  {
    int partisoningPosition = partition(a, l, h);
    quickSort(a, l, partisoningPosition - 1);
    quickSort(a, partisoningPosition + 1, h);
  }
}

int main()
{
  int a[] = {8, 7, 6, 5, 4, 3, 2, 1};

  int n = sizeof(a) / sizeof(a[0]);
  quickSort(a, 0, n - 1);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
}
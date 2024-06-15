#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // 1. find the leftmost and the right most diffent number from a[] & b[]
        // 2. then make it longer
        int n, l = -1, r;
        cin >> n;
        int a[n + 2], b[n + 2];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] != b[i])
            {
                if (l == -1)
                    l = i;
                r = i;
            }
        }
        while(l>0 && b[l-1]<=b[l]) l--;
        while(r<n-1 && b[r+1]>=b[r]) r++;
        cout<<l+1<<" "<<r+1<<endl;
    }
}
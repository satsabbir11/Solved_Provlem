#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n + 2], mxInd = 0, mx = -30, mn = 30, mnInd = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (mx < a[i])
            {
                mxInd = i;
                mx = a[i];
            }

            if (mn > a[i])
            {
                mnInd = i;
                mn = a[i];
            }
        }
        // cout<<mx<<endl;

        pair<int, int> p[50];

        int k = 0;

        if (isSorted(a, n))
        {
            cout << 0 << endl;
            continue;
        }

        if (mn <= 0 && mx <= 0)
        {
            for (int i = 2; i <= n; i++)
            {
                while (a[i] < a[i - 1])
                {
                    p[k].first = i-1;
                    p[k++].second = mnInd;
                    a[i-1] += mn;
                }
            }
        }

        for (int i = 2; i <= n; i++)
        {
            while (a[i] < a[i - 1])
            {
                p[k].first = i;
                p[k++].second = mxInd;
                a[i] += mx;
                if (a[i] > mx)
                {
                    mx = a[i];
                    mxInd = i;
                }
            }
        }

        cout << k << endl;
        for (int i = 0; i < k; i++)
        {
            cout << p[i].first << " " << p[i].second << endl;
        }
    }
}
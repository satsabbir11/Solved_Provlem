#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if (!m)
        {
            cout << n << endl;
            continue;
        }

        int a[n + 3];

        for (int i = 0; i <= n+1; i++)
        {
            a[i] = i;
        }

        while (m--)
        {
            a[0]|=a[1];

            for (int i = 1; i <= n; i++)
            {
                a[i] |= a[i - 1] | a[i + 1];
            }
        }

        for (int i = 0; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        //cout<<a[n]<<endl;
    }
}
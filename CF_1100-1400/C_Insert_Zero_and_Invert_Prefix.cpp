#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1] = {};
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        if (a[n] == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        else
            cout << "YES" << endl;

        int one = 0;

        for (int i = n; i >= 1; i--)
        {
            if (a[i] == 0)
            {
                cout<<0<<" ";
                one = 0;
            }
            else
            {
                one++;
                if(a[i-1]) cout << 0 << " ";
                else cout << one << " ";
            }
        }
        cout << endl;
    }
}

/*
the idea is u insert 0 on index-0 and count one when one is end , insert zero right of number of one
*/
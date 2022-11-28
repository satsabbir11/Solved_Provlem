#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool f = false;
        vector<long long> v, vv;
        long long n;

        cin >> n;
        int a[n + 2];

        for (long long i = 1; i <= n; i++) cin >> a[i];

        sort(a + 1, a + 1 + n);

        for (long long i = 1; i <= n; i++)
        {
            if (a[i] % a[1] == 0) v.push_back(a[i]);
            if (i != 1 && a[i] % a[2] == 0) vv.push_back(a[i]);
        }

        if (v.size() >= n - 1 || vv.size() >= n - 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
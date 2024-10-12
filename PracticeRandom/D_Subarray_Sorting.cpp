#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n + 2], b[n + 2];
        map<long long, long long> mp, mp1;

        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (long long i = 1; i <= n; i++)
        {
            cin >> b[i];
            mp1[b[i]]++;
        }

        bool f = true;

        for (const auto &x : mp)
        {
            if (mp1[x.first] != x.second)
            {
                f = false;
                break;
            }
        }

        if (!f)
        {
            cout << "NO" << endl;
            continue;
        }

        set<long long> s;
        set<long long> s1;

        long long sum = 0;

        for (long long i = 1; i < n; i++)
        {
            if (a[i] == b[i])
                continue;
            if (b[i] <= b[i + 1])
            {
                s.insert(b[i]);
                s1.insert(a[i]);
                sum += (a[i] - b[i]);
            }
            else
            {
                //cout << i << endl;

                s.insert(b[i]);
                s1.insert(a[i]);
                sum += (a[i] - b[i]);
                if (s.size() != s1.size() || sum)
                {
                    f = false;
                    break;
                }
                s.clear();
                s1.clear();
            }
        }

        if (s.size() != s1.size() || sum)
            f = false;

        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
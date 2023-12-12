#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<long long> v, g;
        for (long long i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        long long mn = v[0];

        for (long long j = 0; j < n-1; j++)
        {
            for (long long i = j+1; i < n; i++)
            {
                g.push_back(v[i] - v[j]);
                mn = min(mn , (v[i] - v[j]));
            }
        }

        sort(g.begin(), g.end());

        if (k == 1)
            cout << mn << endl;
        else if (k >= 3)
            cout << 0 << endl;
        else
        {
            for (long long x : g)
            {
                long long prev = lower_bound(v.begin(), v.end(), x) - v.begin();
                long long next = prev;
                prev--;

                //cout<<prev<<" "<<v[prev]<<" "<<next<<" "<<v[next]<<" "<<x<<endl;

               if(next!=n) mn = min(mn, v[next]-x);
               if(prev!=-1) mn = min(mn, x-v[prev]);
            }
            cout << mn << endl;
        }
    }
}
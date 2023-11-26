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
        long long n;
        cin >> n;

        long long a[n + 2];
        for (long long i = 1; i <= n; i++)
            cin >> a[i];

        vector<bool> vis(n+1);
        vector<int>ans(n+1);

        for (long long i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                vector<int>v;
                while (!vis[i])
                {
                    vis[i] = true;
                    v.push_back(i);
                    i = a[i];
                }
                for(int x: v) ans[x] = v.size();
            }
        }
        for (long long i = 1; i <= n; i++) cout<<ans[i]<<" "; 
        cout<<endl;
    }
}

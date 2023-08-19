#include <bits/stdc++.h>

using namespace std;

int solves(int d, vector<int> x)
{
    int ans = 0;
    for (int i = 1; i < x.size(); i++)
    {
        ans += (x[i] - x[i - 1]-1) / d;
        ans++;
    }
    return ans-1;
}

void solve()
{
    #define tests

    int n, m, d;
    cin >> n >> m >> d;
    vector<int> r(m);
    for (int i = 0; i < m; i++) cin >> r[i];
    r.insert(r.begin(), 1 - d);
    r.push_back(n + 1);

    int ans = 2e9, num =0;
    for (int i = 1; i <=m; i++)
    {
        int A = r[i] - r[i - 1] - 1;
        int B = r[i + 1] - r[i] - 1;
        int C = r[i + 1] - r[i - 1] - 1;
        int D = C / d - (A / d + B / d);
        if (D < ans)
        {
            ans = D;
            num = 0;
        }
        if (D == ans) num++;
    }
    cout << ans + solves(d, r) -1 << ' ' << num << endl;
}

int main()
{
    int t = 1;
    #ifdef tests
    cin >> t;
    #endif
    while (t--)
    {
        solve();
    }
}
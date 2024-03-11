#include <bits/stdc++.h>
using namespace std;

set<int> st;
int n, m;

int dp[1005][1005];

void dfs(int val, int index, char *opdir, int *op)
{
    if (index > m)
    {
        st.insert(val);
        dp[val][index] = 1;
        return;
    }
    if (dp[val][index] != -1) return;

    if (opdir[index] == '0')
    {
        int nn = (val + op[index]) % n;
        if (nn == 0)
            nn = n;
        dfs(nn, index + 1, opdir, op);
    }
    else if (opdir[index] == '1')
    {
        int nn = val - (op[index] % n);
        if (nn <= 0)
            nn = n + nn;
        dfs(nn, index + 1, opdir, op);
    }
    else
    {
        int nn = (val + op[index]) % n;
        if (nn == 0)
            nn = n;
        dfs(nn, index + 1, opdir, op);
        nn = val - (op[index] % n);
        if (nn <= 0)
            nn = n + nn;
        dfs(nn, index + 1, opdir, op);
    }
    dp[val][index] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        st.clear();
        int k;
        cin >> n >> m >> k;

        int op[m + 2];
        char opdir[m + 2];

        for (int i = 1; i <= m; i++)
            cin >> op[i] >> opdir[i];

        queue<pair<int, int>> q;
        q.push({k, 1});

        dfs(k, 1, opdir, op);

        cout << st.size() << endl;
        for (auto &x : st)
            cout << x << " ";
        cout << endl;
    }
}
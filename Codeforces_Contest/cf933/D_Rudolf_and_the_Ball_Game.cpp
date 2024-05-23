#include <bits/stdc++.h>
using namespace std;

set<int> st;
int n, m;

int vis[1005][1005];

long long doRepeat(int cur, int extra, int mod, bool dir=true){
    long long num;
    if(dir) num =  (cur+extra)%mod;
    else num = (cur-extra+mod)%mod;
    return num?num:n;
}

void dfs(int val, int index, char *opdir, int *op)
{
    if (index > m)
    {
        st.insert(val);
        vis[val][index] = 1;
        return;
    }
    if (vis[val][index] != -1) return;

    if (opdir[index] == '0')  dfs(doRepeat(val, op[index], n), index + 1, opdir, op);
    else if (opdir[index] == '1')  dfs( doRepeat(val, op[index], n, false), index + 1, opdir, op);
    else
    {
       
        dfs(doRepeat(val, op[index], n), index + 1, opdir, op);
        dfs( doRepeat(val, op[index], n, false), index + 1, opdir, op);
    }
    vis[val][index] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, -1, sizeof(vis));
        st.clear();
        int k;
        cin >> n >> m >> k;

        int op[m + 2];
        char opdir[m + 2];

        for (int i = 1; i <= m; i++)
            cin >> op[i] >> opdir[i];


        dfs(k, 1, opdir, op);

        cout << st.size() << endl;
        for (auto &x : st)
            cout << x << " ";
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

long long cnt = 0;

long long calc(long long n)
{
    if (n % 2)
        return n * ((n - 1) / 2);
    return (n / 2) * (n - 1);
}

long long find(long long a, vector<long long> &par)
{
    if (par[a] == a)
        return a;
    return par[a] = find(par[a], par);
}

void merge(long long a, long long b, vector<long long> &par, vector<long long> &rk)
{
    a = find(a, par);
    b = find(b, par);

    if (rk[a] < rk[b])
        swap(a, b);

    cnt = cnt - calc(rk[a]) - calc(rk[b]);

    rk[a] += rk[b];
    par[b] = a;

    cnt +=calc(rk[a]);
}

struct Tree
{
    long long w, x, y;  //we have a tree where W is its weight, x and y are it's connected nodes
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n, m;
    cin >> n >> m;
    vector<long long> par(n), rk(n, 1); //initialy alls node's is 1 thats why rk =1
    iota(par.begin(), par.end(), 0);    // all guyes are parent for it's self

    Tree v[n];
    for (long long i = 0; i < n - 1; i++)
    {
        cin >> v[i].x >> v[i].y >> v[i].w;
        v[i].x--;
        v[i].y--;
    }

    sort(v, v + n - 1, [](Tree a, Tree b) 
         { return a.w < b.w; });         //sort all nodes assending order depends on their w as we can take maximum number of pair

    pair<long long, long long> p[m];
    for (long long i = 0; i < m; i++)
    {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p, p + m);                  //sort the query because ultimately all are included it's previous

    vector<long long> ans(m);

    long long j = 0;
    for (long long i = 0; i < m; i++)
    {
        while (j < n - 1 && v[j].w <= p[i].first)
        {
            merge(v[j].x, v[j].y, par, rk);
            j++;
        }
        ans[p[i].second] = cnt;
    }

    for (long long i = 0; i < m; i++)
        cout << ans[i] << " ";
}
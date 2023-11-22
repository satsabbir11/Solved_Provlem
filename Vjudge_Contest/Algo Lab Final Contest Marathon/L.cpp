#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    bool f = true;
    int n, in;
    cin >> in >> n;

    pair<int, int> p[n + 2];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(p + 1, p + 1 + n);

    for (int i = 1; i <= n; i++)
    {
        if (p[i].first < in)
            in += p[i].second;
        else
            f = false;
    }

    cout << con << endl;
}
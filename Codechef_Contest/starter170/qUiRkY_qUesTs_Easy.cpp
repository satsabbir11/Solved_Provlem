#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j
#define all(s) s.begin(), s.end()
#define bug(a) cout << #a << " : " << a << endl;
#define int long long

int findMEX(const vector<int> &vec)
{
    unordered_set<int> elements(vec.begin(), vec.end());
    int mex = 0;
    while (elements.count(mex)) mex++;
    return mex;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        sort(all(a));

        int mx = sum, prefixSum = 0, mex = findMEX(a);

        for (int i = 1; i <= n; i++)
        {
            prefixSum += mex;
            sum -= a[i - 1];
            mx = max({mx, prefixSum + sum, i * i + sum});
        }

        cout << mx << endl;
    }
}
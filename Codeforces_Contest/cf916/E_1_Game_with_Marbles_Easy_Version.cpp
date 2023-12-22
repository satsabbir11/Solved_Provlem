#include <bits/stdc++.h>
using namespace std;

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, ans = 0;
        cin >> n;

        vector<pair<int, int>> p(n);

        for (int i = 0; i < n; i++)
            cin >> p[i].first;
        for (int i = 0; i < n; i++)
            cin >> p[i].second;

        sort(p.begin(), p.end(), [&](pair<int, int> x, pair<int, int> y) {
            return x.first + x.second > y.first + y.second;
        }); // main logic

        int g = 0;

        for (auto x : p)
        {
            if (g & 1)
                ans -= x.second - 1;
            else
                ans += x.first - 1;
            g++;
        }

        cout << ans << endl;
    }

    return 0;
}

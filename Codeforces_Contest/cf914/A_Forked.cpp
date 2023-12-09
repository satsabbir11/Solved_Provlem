#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int dx[] = {-1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        if (c == e && d == f)
        {
            cout << 8 << endl;
            continue;
        }

        set<pair<int, int>> pos, pos1;

        pos.insert({c - b, d + a});
        pos.insert({c - b, d - a});
        pos.insert({c - a, d + b});
        pos.insert({c - a, d - b});

        pos.insert({c + b, d + a});
        pos.insert({c + b, d - a});
        pos.insert({c + a, d + b});
        pos.insert({c + a, d - b});

        pos1.insert({e - b, f + a});
        pos1.insert({e - b, f - a});
        pos1.insert({e - a, f + b});
        pos1.insert({e - a, f - b});

        pos1.insert({e + b, f + a});
        pos1.insert({e + b, f - a});
        pos1.insert({e + a, f + b});
        pos1.insert({e + a, f - b});

        int ans = 0;
        for (const auto &pair : pos)
        {
            // cout << pair.first << " " << pair.second << endl;
            if(pos1.find(pair) !=pos1.end()) ans++;
        }

        cout << ans << endl;
    }
}
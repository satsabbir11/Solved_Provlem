#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        int a[n + 2];
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        vector<tuple<int, int, int>> s;
        map<tuple<int, int, int>, int> mp;

        for (int i = 1; i <= n - 2; i++)
        {
            int g[3];
            g[0] = a[i];
            g[1] = a[i + 1];
            g[2] = a[i + 2];

            if (!mp[make_tuple(g[0], g[1], g[2])])
                s.push_back(make_tuple(g[0], g[1], g[2]));
            mp[make_tuple(g[0], g[1], g[2])]++;
        }

        int i = 0;
        long long cnt1 = 0;

        vector<vector<int>> v;

        for (const auto &item : s)
        {
            vector<int> vv(3);
            vv[0] = get<0>(item);
            vv[1] = get<1>(item);
            vv[2] = get<2>(item);
            v.push_back(vv);
        }

        for (int i = 0; i < v.size(); i++)
        {
            int aa = v[i][0], bb = v[i][1], cc = v[i][2];
            bool f = false;

            for (int j = i + 1; j < v.size(); j++)
            {
                int cnt = (v[j][0] == aa) + (v[j][1] == bb) + (v[j][2] == cc);
                if (cnt == 2)
                {
                    cnt1 += (long long)(mp[make_tuple(aa, bb, cc)]) * (long long)(mp[make_tuple(v[j][0], v[j][1], v[j][2])]);
                }
            }
        }

        printf("%lld\n", cnt1);
    }
}

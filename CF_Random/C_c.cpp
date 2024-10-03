#include <bits/stdc++.h>
using namespace std;

pair<int, int> pairF(set<int> &L, map<int, int> &mp, int& two)
{
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for (auto x : L)
    {
        if (mp[x] == 1)
            cnt1++;
        if (mp[x] == 2)
            cnt2++;
    }

    cnt2 = two - cnt2;

    return {cnt1, cnt2};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t, mm = 1;
    cin >> t;
    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;

        set<int> L, R, S;

        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            L.insert(x);
        }
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            R.insert(x);
        }
        for (int i = 1; i <= l; i++)
        {
            int x;
            cin >> x;
            S.insert(x);
        }

        map<int, int> mp;
        int two = 0;
        
        for (auto x : L) mp[x]++;
        for (auto x : R) mp[x]++;
        for (auto x : S) mp[x]++;

        for(auto &[x, y]:mp){
            if(y==2) two++;
        }

        cout << "Case #" << mm << ":" << endl;

        auto p = pairF(L, mp, two);
        cout << p.first << " " << p.second << endl;

        p = pairF(R, mp, two);
        cout << p.first << " " << p.second << endl;

        p = pairF(S, mp, two);
        if (t)
            cout << p.first << " " << p.second << endl;
        else
            cout << p.first << " " << p.second;
        mm++;
    }
}

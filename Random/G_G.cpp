#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int findPar(int x, vector<int> &par)
{
    if (par[x] == x)
        return x;
    return par[x] = findPar(par[x], par);
}

void connect(int x, int y, vector<int> &par)
{
    int px = findPar(x, par), py = findPar(y, par);
    par[min(px, py)] = par[max(px, py)];
}

int32_t main()
{
    int t, kk=1;
    cin >> t;
    while (t--)
    {
        cin.ignore();

        int n, m=0;
        cin >> n;
        vector<pair<int, pair<int, int>>> ed;
        vector<int> par(n + 1);
        iota(all(par), 0);

        int x, y, w;
        while (cin >> x >> y >> w)
        {
            if (x == 0 and y == 0 and w == 0)
                break;
            ed.push_back({w, {x, y}});
            m++;
        }
        sort(all(ed));

        int mn, mx;
        mn = mx = 0;

        int cnt = n;

        for (int i = 0; i < m and cnt>0; i++)
        {
            auto [w, xy] = ed[i];
            auto [x, y] = xy;

            int px = findPar(x, par), py = findPar(y, par);
            if (px == py)
                continue;

            mn += w;
            connect(x, y, par);
            cnt--;
        }

        sort(rall(ed));
        cnt=n;
        par.assign(n+1, 0);
        iota(all(par), 0);

        for (int i = 0; i < m and cnt>0; i++)
        {
            auto [w, xy] = ed[i];
            auto [x, y] = xy;

            int px = findPar(x, par), py = findPar(y, par);
            if (px == py)
                continue;

            mx += w;
            connect(x, y, par);
            cnt--;
        }

        int ans = mn+mx;

        cout<<"Case "<<kk++<<": ";

        if(ans%2) cout<<ans<<"/2"<<endl;
        else cout<<ans/2<<endl;
    }
}
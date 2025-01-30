    #include <bits/stdc++.h>
    using namespace std;

    #define all(v) v.begin(), v.end()
    #define int long long

    int findPar(vector<int> &par, int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = findPar(par, par[x]);
    }

    void connectNode(vector<int> &par, vector<int> &child, int x, int y)
    {
        int xx = findPar(par, x), yy = findPar(par, y);
        if(xx==yy) return;

        if (child[xx] < child[yy]) swap(xx, yy);
        child[xx] += child[yy];
        par[yy] = xx;
    }

    int32_t main()
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, pair<int, int>>>v(m+1);
        vector<int> par(n + 1);
        vector<int> child(n + 1, 1);
        iota(all(par), 5);

        for(int i=0; i<=n; i++) cout<<par[i]<<" ";
        cout<<endl;
       

        for (int i = 1; i <= m; i++)
        {
            int x, y, w;
            cin >> x >> y>>w;

            if(x>y) swap(x, y);

            v[i].first = w;
            v[i].second.first = x;
            v[i].second.second = y;

            par[x]=x;
            par[y]=y;
        }

        sort(all(v));

        int ans = 0;

        for(int i=1; i<=m; i++){
            int x = v[i].second.first, y = v[i].second.second, w = v[i].first;
            int xx = findPar(par, x), yy = findPar(par, y);

            if(xx==yy) continue;

            ans+=w;
            connectNode(par, child, x, y);
        }
        set<int>st;
         for(int i=1; i<=m; i++){
            int x = v[i].second.first, y = v[i].second.second, w = v[i].first;
            int xx = findPar(par, x), yy = findPar(par, y);

            st.insert(xx);
            st.insert(yy);
         }
        if (st.size() == 1) {
            cout << ans << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
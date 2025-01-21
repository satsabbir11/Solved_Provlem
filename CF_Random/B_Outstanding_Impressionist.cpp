#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int aa[n], bb[n];
        map<int, int>mp;
        vector<int>v;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            aa[i] = x;
            bb[i] = y;
            if (x == y){
                mp[x]++;
                if(mp[x]==1) v.push_back(x);
            }
        }

        sort(all(v));

        for (int i = 0; i < n; i++)
        {
            int x = aa[i], y = bb[i];
            if(x==y){
                if(mp[x]>=2) cout<<0;
                else cout<<1;
            }else{
                auto ix = lower_bound(all(v), x), iy = lower_bound(all(v), y);
                if(ix!=v.end() and iy!=v.end() and (iy-ix)==(y-x) and *ix==x and *iy==y) cout<<0;
                else cout<<1;
            }
        }
        cout << endl;
    }
}

/*

Summary:  

*/
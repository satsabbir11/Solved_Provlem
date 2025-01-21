#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    
    int n, d, r;
    while(1){
        cin >> n >> d >> r;
        if (!n && !d && !r) break;

        vector<int> m(n), e(n), rem1, rem2;

        for (int &x: m) cin >> x;
        for (int &x: e) cin >> x;

        sort(all(m));
        sort(allr(e));

        int ans = 0;


        for (int i=0; i<n; i++){
           ans+=((m[i]+e[i]-d)*r);
        }

        cout << ans << endl;
    }
}

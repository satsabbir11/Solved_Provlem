#include<bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()

#define auto(x,a) for (auto& x : a)

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        long long mn1 = INT_MAX, ans = 0, mn2 = mn1;
        while(n--){
            long long m;
            cin>>m;

            vector<long long>v(m);
            auto(x, v) cin>>x;

            long long mn = *min_element(all(v));
            v.erase(find(all(v), mn));
            mn1 = min(mn, mn1);
            mn = *min_element(all(v));
            ans+=mn;
            mn2 = min(mn, mn2);
        }
        cout<<ans+mn1-mn2<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()

#define auto(x,a) for (auto& x : a)
#define sortv(s) sort(s.begin(), s.end())


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
            sortv(v);
            ans+=v[1];
            mn1=min(mn1, v[0]);
            mn2=min(mn2, v[1]);
        }
        cout<<ans+mn1-mn2<<endl;
    }
}
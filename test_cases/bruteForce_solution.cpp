#include <bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long

int main(){
    opt();
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<ll> a(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<ll, ll> mp; 
        vector<ll> res;
        for (int i = 0; i < n; ++i) {
            ll x = a[i];
            while (mp[x] > 0) {
                mp[x]--;
                if (mp[x] == 0) {
                    cnt--;
                }
                x *= 2;
            }
            mp[x]++;
            if (mp[x] == 1) {
                cnt++;
            }
            res.push_back(cnt);
        }
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
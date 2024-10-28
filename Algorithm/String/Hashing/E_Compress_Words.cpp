#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
pair<int, int> pw[N], ipw[N];
int ip1, ip2;

int power(long long n, long long k, int mod)
{
    int ans = 1 % mod;
    n %= mod;
    if (n < 0)
        n + mod;
    while (k)
    {
        if (k & 1)
            ans = (long long)ans * n % mod;
        n = (long long)n * n % mod;
        k >>= 1;
    }
    return ans;
}

void prec()
{
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }
}

struct Hashing
{
    int n;
    string s;
    vector<pair<int, int>> hs;
    Hashing() {}
    Hashing(string _s)
    {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;
            p.first = (hs[i].first + 1ll * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1ll * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }

    pair<int, int> get_hash(int l, int r)
    {
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    prec();

    int n;
    cin>>n;
    string s[n];
    
    for(int i=0; i<n; i++) cin>>s[i];

    string final=s[0];

    for(int i=0; i<n-1; i++){
        int l1 = s[i].size(), l2 = s[i+1].size();
        int l = min(l1,l2);
        Hashing hs1(s[i+1]), hs2(s[i]);

        int ans = 0;

        for(int j=0; j<l; j++){
            auto p1 = hs1.get_hash(1, j+1), p2 = hs2.get_hash(l1-j, l1);
            if(p1==p2) ans = j+1;
        }

        final+=s[i+1].substr(ans, l2-ans);
    }
    cout<<final<<endl;
}
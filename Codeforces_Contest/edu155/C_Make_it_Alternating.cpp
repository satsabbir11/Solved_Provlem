#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

#define MOD 998244353

long long fact[200005];

void factorial()
{
    fact[0] = 1;
    for (long long i = 1; i < 200005; i++)
        fact[i] = (((i % MOD) * (fact[i - 1] % MOD)) % MOD);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    factorial();

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;

        string s;
        cin >> s;

        n = s.size();

        long long cnt = 0, ans1 = 0, ans2 = 1;

        char flag = s[0];

        for (int i = 0; i < n; i++)
        {
            if (s[i] == flag)
                cnt++;
            else
            {

                flag = s[i];
                ans1 += (cnt - 1);
                ans2 = (ans2 * cnt % MOD) % MOD;
                cnt = 1;
            }
        }

        if (cnt)
        {
            ans1 += (cnt - 1);
            ans2 = (ans2 * cnt % MOD) % MOD;
        }

        cout << ans1 << " " << (ans2 % MOD * fact[ans1] % MOD) % MOD << endl;
    }
}
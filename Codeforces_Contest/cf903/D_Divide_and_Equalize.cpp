#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

void primeFactors(int n, map<int, int> &mp, vector<int> &v)
{
    while (n % 2 == 0)
    {
        if (!mp[2])
            v.push_back(2);
        mp[2]++;
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            if (!mp[i])
                v.push_back(i);
            mp[i]++;
            n /= i;
        }
    }

    if (n > 1)
    {
        if (!mp[n])
            v.push_back(n);
        mp[n]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        map<int, int> mp;
        vector<int> v;

        for (long long i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            primeFactors(x, mp, v);
        }


        bool f=true;

        for(int x: v){
            if(mp[x]%n!=0){
                f=false;
                break;
            }
        }

        cout<<con<<endl;
    }
}

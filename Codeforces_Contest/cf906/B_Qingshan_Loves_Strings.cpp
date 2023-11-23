#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

bool isGood(string s, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n>> m;

        string s, t;
        cin >> s >> t;

        if (isGood(s, n) || n==1)
        {
            cout << "YES" << endl;
            continue;
        }

        if (!isGood(t, m))
        {
            cout << "NO" << endl;
            continue;
        }

        if (t[0] != t[m - 1])
        {
            cout << "NO" << endl;
            continue;
        }

        bool f=true;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1] && s[i] == t[0])
            {
                f=false;
                break;
            }
        }

        cout<<con<<endl;
    }
}
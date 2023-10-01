#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

vector<int> lcs(string pattern)
{
    int n = pattern.size();
    vector<int> v(n);
    int index = 0;

    for (int i = 1; i < n;)
    {
        if (pattern[i] == pattern[index])
        {
            v[i] = index + 1;
            i++;
            index++;
        }
        else
        {
            if (index)
                index = v[index - 1];
            else
            {
                v[i] = 0;
                i++;
            }
        }
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t = 1;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        int n = s.size(), m = t.size(), t0 = 0, s0 = 0, t1, s1;

        for (int i = 0; i < m; i++)
        {
            if (t[i] == '0')
                t0++;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                s0++;
        }
        t1 = m - t0;
        s1 = n - s0;
 
        if (s == t)
        {
            cout << t << endl;
            continue;
        }
        else if (n == m)
        {
            if (s0 == t0)
                cout << t << endl;
            else
                cout << s << endl;
            continue;
        }

        s0 -= t0;
        s1 -= t1;

        if (s0 < 0 || s1 < 0)
        {
            cout << s << endl;
            continue;
        }
        vector<int> v = lcs(t);

        int l = v[m - 1];

        while (1)
        {
            t += t[l];
            if (t[l] == '0')
                s0--;
            else
                s1--;
            if (s0 <= 0 || s1 <= 0)
                break;
            l++;
        }

        while (s0--)
        {
            t += '0';
        }
        while (s1--)
        {
            t += '1';
        }
        cout << t << endl;
    }
}
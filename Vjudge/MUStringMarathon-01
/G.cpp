#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

vector<int> lps(string pattern)
{
    int n = pattern.size();
    vector<int> v(n);
    int index = 0, mx = 0;

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

    long long t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string t = s;
        reverse(t.begin(), t.end());
        s += '#' + t;

        vector<int> v = lps(s);

        int mx = 0, n = s.size();

        // first one is valid for abcabc

        for (int i = n / 2; i < n; i++)
        {
            mx = max(mx, v[i]);
        }
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, v[i]);
        }

        t = s.substr(0, mx);

        reverse(t.begin(), t.end());
        cout << t << endl;
    }
}
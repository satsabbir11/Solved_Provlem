#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; string s;
    cin >> n>>s;

    set<char> st;

    int k = n;
    n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '?' or s[n - i - 1] != '?')
        {
            if (s[i] != '?')
            {
                s[n - i - 1] == s[i];
            }
            else
                s[i] = s[n - 1 - i];
        }
        if (s[i] != '?' and s[n - i - 1] != '?' and s[i] != s[n - i - 1])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    map<int, bool> mp;

    for (char x : s)
    {
        if (x != '?')
        {
            if (!mp[x])
            {
                k--;
                mp[x] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < (n + 1) / 2; i++)
        if (s[i] == '?')
            cnt++;
    // cout<<s<<endl;

    cnt -= k;

   // cout << cnt << endl;

    for (int i = 0; i < (n + 1) / 2; i++)
    {
        if (s[i] == '?')
        {
            char mn = 'a';
            if (cnt > 0)
            {
                mn = 'a';
                cnt--;
            }
            else if (k)
            {
                for (char j = 'a'; j <= 'z'; j++)
                {
                    if (!mp[j])
                    {
                        // cout<<mn<<endl;
                        mn = j;
                        mp[mn] = true;
                        break;
                    }
                }
                k--;
            }
            s[i] = s[n - i - 1] = mn;
        }
    }
    if (k)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << s << endl;
}
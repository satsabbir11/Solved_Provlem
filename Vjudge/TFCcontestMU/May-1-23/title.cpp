#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned long long
#define con (f ? "YES" : "NO")

#define Dpos(n) fixed << setprecision(n)

#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))

#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
#define max5(a, b, c, d, e) max(max4(a, b, c, d), e)
#define min5(a, b, c, d, e) min(min4(a, b, c, d), e)

#define sortn(a, x, y) sort(a + x, a + x + y)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define reversesortv(s) \
    sortv(s);           \
    reversev(s)

#define lowerbound(v, x) lower_bound(v.begin(), v.end(), x) - v.begin() + 1
#define upperbound(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()

#define pb push_back
#define loj(i, j) "Case " << i << ": " << j
#define gap " "

#define auto(x, a) for (auto &x : a)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    string s, t;
    cin >> n >> s;

    int l = s.size(), fnt = 0;

    for (int i = 0; i < l; i++)
    {
        if (s[i] != '?')
        {
            t.push_back(s[i]);
        }
        else if (i < l / 2 && (s[i] == s[l - i - 1] && s[i] != '?'))
        {
            fnt++;
        }
    }

    int cnt = 0;
    map<char, int> mp;

    for (int i = 0; i < t.size(); i++)
    {
        if (mp[t[i]] == 0)
        {
            cnt++;
        }
        mp[t[i]]++;
    }

    if (cnt > n)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cnt = n - cnt;
    // cout << cnt << endl;

    sortv(t);

    int ll = t.size();

    char minChar;

    if (ll == 0)
    {
        minChar = 'a';
        minChar--;
    }
    else
    {
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (mp[i] == 0)
            {
                minChar = i;
                minChar--;
                break;
            }
        }
    }

    for (int i = 0; i < l / 2; i++)
    {
        if (s[i] != s[l - i - 1] && s[i] != '?' && s[l - i - 1] != '?')
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i = 0; i < l / 2; i++)
    {

        // cout<<i<<" "<<s[i]<<endl<<n-i-1<<" "<<s[l-i-1]<<endl;
        if (s[i] == s[l - i - 1] && s[i] == '?')
        {
            if (cnt)
            {

                minChar = 'a';
                int g=0;
                while (minChar != 'z' && mp[minChar] != 0 && fnt == cnt)
                {
                    minChar++;
                    g++;
                }
                mp[minChar]++;
                if(g) cnt--;
            }
            else
                minChar = 'a';

            s[i] = minChar;
            s[l - i - 1] = minChar;
        }

        else if (s[i] == '?')
        {
            minChar = 'a';
            s[i] = s[l - i - 1];
        }

        else if (s[l - i - 1] == '?')
        {
            minChar = 'a';
            s[l - i - 1] = s[i];
        }
    }

    if (s[l / 2] == '?')
    {
        if (cnt)
        {
            minChar = 'a';
            int g=0;
            while (minChar != 'z' && mp[minChar] != 0 && fnt == cnt)
            {
                minChar++;
                g++;
            }
            mp[minChar]++;
            s[l / 2] = minChar;
            if(g) cnt--;
        }
        else
        {
            s[l / 2] = 'a';
        }
    }

    // cout<<cnt<<endl;

    if (cnt == 0)
    {
        cout << s << endl;
    }

    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}
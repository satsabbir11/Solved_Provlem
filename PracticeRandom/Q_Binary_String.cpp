#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

string decimalToBinary(unsigned long long n)
{
    string s = "";
    while (n > 0)
    {
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

unsigned long long binaryToDecimal(string s)
{
    unsigned long long n = s.size();
    reverse(s.begin(), s.end());
    unsigned long long st = 1;
    unsigned long long ans = 0;
    for (unsigned long long i = 0; i < n; i++)
    {
        if (i)
            st *= 2;
        if (s[i] == '1')
            ans += st;
    }

    return ans;
}

bool exist(string s, string t)
{
    unsigned long long n = s.size(), m = t.size();
    unsigned long long j = 0;
    for (unsigned long long i = 0; i < n && j < m; i++)
    {
        if (s[i] == t[j])
            j++;
    }
    return j == m;
}

pair<unsigned long long, unsigned long long> czo(string s)
{

    unsigned long long z, o;
    z = o = 0;
    unsigned long long n = s.size();

    for (unsigned long long i = 0; i < n; i++)
    {
        if (s[i] == '1')
            o++;
        else
            z++;
    }

    return {z, o};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    unsigned long long n;
    cin >> n;

    string s;
    cin >> s;

    unsigned long long l = s.size(), cnt = 0;

    unsigned long long m = n;

    while (n)
    {
        n /= 2;
        cnt++;
    }

    unsigned long long haveto = l - cnt;

    if (m >= binaryToDecimal(s))
    {
        cout << 0 << endl;
        return 0;
    }

    string t = decimalToBinary(m);

    if (exist(s, t))
        cout << max(0ull, haveto) << endl;
    else
    {
        // pair<unsigned long long, unsigned long long>given1 = czo(s);
        // pair<unsigned long long, unsigned long long>given2 = czo(t);

        unsigned long long x = s.size(), y = t.size();
        unsigned long long i, j;
        i = j = 0;
        i=1;

        bool f = false;

        while (i < x)
        {
            unsigned long long rem1 = x - i, rem2 = y - j - 1;
            if (rem1 <= rem2)
                break;
            if (s[i] == '0' and t[j] == '1')
            {
                // cout<<i<<" "<<j<<endl;
                f = true;
                break;
            }
            i++;
        }

        if (f)
            cout << max(0ull, haveto) << endl;
        else
            cout << max(0ull, haveto + 1) << endl;
    }
}
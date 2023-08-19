#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

bool check(string s)
{
    int n = s.size();
    for (int i = 0; i <=0; i ++)
    {
        if (n==2 && s[i] == '(' && s[i + 1] == ')')
        {
        }
        else
            return true;
    }
    return false;
}

bool type1(string s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i ++)
    {
        if (s[i] == '(' && s[i + 1] == '(')
            return true;
    }
    return false;
}

bool type2(string s)
{
    int n = s.size();
    for (int i = 0; i < n - 1; i ++)
    {
        //cout<<s[i]<<s[i+1]<<endl;
        if (s[i] == ')' && s[i + 1] == ')')
            return true;
    }
    return false;
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
        int n = s.size();

        bool f = check(s);
        cout << con << endl;
        if (!f)
            continue;

        string ans;

        if (type1(s) || type2(s))
        {

            for (int i = 0; i < n; i++)
            {
                ans += "()";
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans += "(";
            }
            for (int i = 0; i < n; i++)
            {
                ans += ")";
            }
        }
        cout << ans << endl;
    }
}
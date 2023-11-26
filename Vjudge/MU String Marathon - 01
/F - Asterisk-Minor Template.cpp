#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

string LCSubStr(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    int result = 0;

    int end;

    int len[2][n + 1];

    int currRow = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                len[currRow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                if (len[currRow][j] > result)
                {
                    result = len[currRow][j];
                    end = i - 1;
                }
            }
            else
            {
                len[currRow][j] = 0;
            }
        }
        currRow = 1 - currRow;
    }

    if (result == 0)
    {
        return "1";
    }
    return X.substr(end - result + 1, result);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;

        string ss = LCSubStr(s, t);
        if (ss == "1")
        {
            cout << "NO" << endl;
            continue;
        }

        if (ss.size() == 1)
        {
            int f1 = s.find(ss);
            int f2 = t.find(ss);
            if ((f1 == 0 || f1 == (s.size() - 1)) && (f1 == f2) && (f2 == 0 || f2 == (t.size() - 1)))
            {
                cout << "YES" << endl;

                if (f1)
                    cout << "*" << ss << endl;
                else
                    cout << ss << "*" << endl;

                continue;
            }
            reverse(s.begin(), s.end());
            reverse(t.begin(), t.end());

            ss = LCSubStr(s, t);

            f1 = s.find(ss);
            f2 = t.find(ss);

            if ((f1 == 0 || f1 == (s.size() - 1)) && (f1 == f2) && (f2 == 0 || f2 == (t.size() - 1)))
            {
                cout << "YES" << endl;

                if (f1 == 0)
                    cout << "*" << ss << endl;
                else
                    cout << ss << "*" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "YES" << endl;
            cout << "*" << ss << "*" << endl;
        }
    }
}
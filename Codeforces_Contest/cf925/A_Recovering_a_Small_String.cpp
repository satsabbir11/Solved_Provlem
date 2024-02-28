#include <bits/stdc++.h>
using namespace std;

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

        for (long long i = 1; i <= 26; i++)
        {
            for (long long j = 1; j <= 26; j++)
            {
                if (n - i - j <= 26)
                {
                    string s = "";
                    s += char('a' + i - 1);
                    s += char('a' + j - 1);
                    s += char('a' + (n - i - j) - 1);
                    cout << s << endl;
                    i = j = 27;
                }
            }
        }
    }
    return 0;
}

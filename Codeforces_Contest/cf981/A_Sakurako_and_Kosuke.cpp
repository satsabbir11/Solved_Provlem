#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

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

        long long st = 0;
        bool f = true, g=false;
        for (long long i = 1; i <= n; i++)
        {
            if (!f)
            {
                st += (2 * i - 1);
                if (abs(st) > n)
                {
                    break;
                }
                f=true;
            }
            else
            {
                st -= (2 * i - 1);
                if (abs(st) > n)
                {
                    break;
                }
                f=false;
            }
        }
       if(!f) cout << "Kosuke" << endl;
       else  cout << "Sakurako" << endl;
    }
}
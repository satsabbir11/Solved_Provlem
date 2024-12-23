#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Musta                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl '\n'
#define yes cout << "Yes" << '\n';
#define no cout << "No" << '\n';

int main()
{
    Musta int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int x = INT_MIN, y = INT_MIN, yy = INT_MIN, alice_ind = -1;

        for (int i = 0; i < n; i++)
        {
            y = x;
            x = max(x, max(a[i], b[i]));
            if (y != x)
            {
                alice_ind = i;
            }
        }

        int q = INT_MIN, bob_ind = -1;
        for (int i = 0; i < n; i++)
        {
            if (i == alice_ind)
                continue;
            else
            {

                q = yy;
                yy = max(yy, a[i]);
                if (q != yy)
                {
                    bob_ind = i;
                }
            }
        }
        int bob_val = max(a[bob_ind], b[bob_ind]);
        // cout << x << " " << bob_val << endl;

        if (x > bob_val)
        {
            yes;
        }
        else
        {
            no;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k, ans;
        map<int, bool> mp;
        cin >> x >> y >> k;
        while (k >= 1)
        {
            int rem = ((x / y) + 1) * y;
            // cout<<rem<<" "<<x<<endl;
            if (rem - x <= k)
                k -= (rem - x);
            else
            {
                ans = x + k;
                break;
            }
            x = rem;
            while (x % y == 0)
            {
                x /= y;
            }
            ans = x;
            if (mp[x])
            {
                k %= (y - 1);
                ans = x + k;
                break;
            }
            mp[x] = true;
        }

        cout << ans << endl;
    }
}
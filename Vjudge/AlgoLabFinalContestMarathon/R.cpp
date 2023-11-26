#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    map<int, bool> mp;

    for (int &x : v)
        cin >> x;

    int st = 0, cnt = 0;

    bool f = false;

    while (1)
    {
        // cout<<st<<" ";
        int x= v[st];
        if (x< 0)
        {
            x = abs(x);
            x = x % n;
            x = n - x;
        }
        st = (st + x) % n;
        if (mp[st] && cnt != n)
            break;
        if (!mp[st])
        {
            mp[st] = true;
            cnt++;
        }
        if (st == 0 and cnt == n)
        {
            f = true;
            break;
        }
    }

    cout << con << endl;
}
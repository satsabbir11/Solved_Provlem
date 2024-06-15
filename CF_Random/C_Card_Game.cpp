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
        deque<int> s;
        while (n--)
        {
            int x;
            cin >> x;
            s.push_back(x);
        }

        int ans = 0;

        for (auto it = s.begin(); it < s.end(); it += 2)
        {
            cout<<*it<<endl;
            if (*it > 0)
            {
                cout<<*it<<endl;
                ans+=*it;
                it = s.erase(it);
                --it;
            }
        }
        cout<<ans<<endl;
    }
}
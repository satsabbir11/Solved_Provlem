#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i]--;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int st = i, c = 0;
                while (!visited[st])
                {
                    visited[st] = true;
                    st = v[st];
                    c++;
                }

                if (c >= 3)
                {
                    cnt += (c / 2);
                    if (c % 2 == 0)
                        cnt--;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

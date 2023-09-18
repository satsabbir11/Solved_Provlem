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
        int x, y, z;
        cin >> x >> y >> z;
        char c[z + 5];
        int cnt = 0;
        for (int i = 0; i < z; i++)
        {
            cin >> c[i];
            if (c[i] == '+')
                cnt++;
        }

        //cout<<cnt<<endl;

        if (y == x)
        {
            cout << "YES" << endl;
            continue;
        }
        else
        {
            int tem = 0;
            bool f = false;
            for (int i = 0; i < z; i++)
            {
                if (c[i] == '+')
                    tem++;
                else
                    tem--;
                if ((tem + y) == x)
                {
                    cout << "YES" << endl;
                    f = true;
                    break;
                }
            }
            if (!f)
            {
                if ((cnt + y) >= x)
                    cout << "MAYBE" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
}
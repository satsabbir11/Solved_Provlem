#include <bits/stdc++.h>
using namespace std;

int calculate(int x, int y, int z)
{
    int ans = 0;
    if ((x <= y && x >= z) || (x <= z && x >= y))
        ans = ans;
    else
        ans += min(abs(x - y), abs(x - z));

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[3][2];
        for (int i = 0; i < 3; i++)
            cin >> a[i][0] >> a[i][1];

        int x, y, z, ans = 1;
        x = a[0][0];
        y = a[1][0];
        z = a[2][0];

        ans += calculate(x, y, z);

        x = a[0][1];
        y = a[1][1];
        z = a[2][1];

        ans += calculate(x, y, z);

        cout << ans << endl;
    }
}

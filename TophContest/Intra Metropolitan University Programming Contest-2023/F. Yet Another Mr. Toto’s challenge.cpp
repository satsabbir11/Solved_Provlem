#include <bits/stdc++.h>
using namespace std;

#define Dpos(n) fixed << setprecision(n)

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int l;
        double ans, angle;
        cin >> l >> angle;
        angle *= ( 3.1416 / 180);
        ans = sqrt(2 * 9.8 * l * (1 - cos(angle)));
        cout << "Case " << i << ": " << Dpos(6) << ans << endl;
    }
}
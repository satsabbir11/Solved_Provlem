#include <bits/stdc++.h>
using namespace std;

int getRes(int n)
{
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int x = 1 << i;     // 2^i ---> 2 to the power i
        if (n & x) ans |= x;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int x = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            x &= y;
        }
        cout << getRes(x) << endl;
    }
}

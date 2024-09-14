#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int cum[N + 5];

int main()
{
    for (int i = 1; i <= N; i++)
    {
        int num = i;
        int cnt = 0;
        while (num)
        {
            num /= 3;
            cnt++;
        }
        cum[i] = cnt + cum[i - 1];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        cout << (cum[l] - cum[l - 1]) * 2 + (cum[r] - cum[l]) << endl;
    }

    return 0;
}

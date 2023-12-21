#include <bits/stdc++.h>
using namespace std;

struct arr
{
    long long x, y;
};

bool compareArr(const arr &a, const arr &b)
{
    return a.x > b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, mx = 0;
        cin >> n;

        arr a[n + 2], b[n + 2], c[n + 2];
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i].x;
            a[i].y = i;
        }
        sort(a + 1, a + n + 1, compareArr);
        for (long long i = 1; i <= n; i++)
        {
            cin >> b[i].x;
            b[i].y = i;
        }
        sort(b + 1, b + n + 1, compareArr);
        for (long long i = 1; i <= n; i++)
        {
            cin >> c[i].x;
            c[i].y = i;
        }
        sort(c + 1, c + n + 1, compareArr);

        for (long long i = 1; i <= 3; i++)
        {
            for (long long j = 1; j <= 3; j++)
            {
                for (long long k = 1; k <= 3; k++)
                {
                    long long in1, in2, in3;
                    long long val1, val2, val3;
                    in1 = a[i].y;
                    in2 = b[j].y;
                    in3 = c[k].y;

                    val1 = a[i].x;
                    val2 = b[j].x;
                    val3 = c[k].x;

                    if (in1 != in2 && in2 != in3 && in1 != in3)
                        mx = max(mx, val1 + val2 + val3);
                }
            }
        }

        cout << mx << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

double calculate(double px, double py, double fx, double fy)
{
    double x = (px - fx) * (px - fx), y = (py - fy) * (py - fy);
    return sqrt(x + y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        double px, py, fx, fy, sx, sy;
        cin >> px >> py >> fx >> fy >> sx >> sy;

        double forFirstP = calculate(px, py, fx, fy), forFirst0 = calculate(0, 0, fx, fy);
        double forSecondP = calculate(px, py, sx, sy), forSecond0 = calculate(0, 0, sx, sy);

        // cout<<forFirstP<<" "<<forFirst0<<endl;
        // cout<<forSecondP<<" "<<forSecond0<<endl;

        double ans = min(max(forFirstP, forFirst0), max(forSecondP, forSecond0));
        double ans1 = min(calculate(sx, sy, fx, fy) / 2.0, min(min(forFirstP, forSecond0), min(forSecondP, forFirst0)));
        cout << fixed << setprecision(10) << max(ans, ans1) << endl;
    }
}
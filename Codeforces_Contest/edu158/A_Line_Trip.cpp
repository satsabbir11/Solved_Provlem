#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        a[n]= a[n-1] + 2*(m-a[n-1]);

        int mx = a[0];
        for (int i = 1; i <= n; i++) mx = max(mx, a[i]-a[i-1]);
        cout << mx << endl;
    }
}
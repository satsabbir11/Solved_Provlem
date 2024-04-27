#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define resizeWihtUnique(a) a.resize(unique(a.begin(), a.end()) - a.begin());

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 1; i <= n; i++)
            cin >> a[i - 1];
        sort(all(a));
        resizeWihtUnique(a);
        int cnt = 1, j = 0, nn = a.size();

        for (int i = 1; i < nn; i++)
        {
            while (a[i] - a[j] >= n)
                j++;
            cnt = max(cnt, i-j+1);
        }
        cout << cnt << endl;
    }
}
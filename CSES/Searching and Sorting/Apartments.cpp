#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n), b(m);
    for (int &x : v)
        cin >> x;
    for (int &x : b)
        cin >> x;

    sort(v.begin(), v.end());
    sort(b.begin(), b.end());

    int cnt = 0;
    int i, j;
    i = j = 0;

    while (i < n and j < m)
    {
        if (abs(v[i] - b[j]) <= k)
        {
            i++;
            j++;
            cnt++;
        }
        else
        {
            if (v[i] > b[j])
                j++;
            else
                i++;
        }
    }
    cout << cnt << endl;
}

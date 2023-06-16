#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> &a, pair<long long, long long> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        long long n, ans = 0;
        cin >> n;
        pair<long long, long long> a[n];

        for (long long i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n, cmp);
        map<long long, long long> cnt;

        for (long long i = 0; i < n; i++)
        {
            if (cnt[a[i].first] < a[i].first)
            {
                ans += a[i].second;
                cnt[a[i].first]++;
            }
        }
        cout << ans << endl;
    }
}

/*
Okey firstly the please understand the problem statement properly.

Key point is choose some bulb in such way as if to earn more point by breaking minimum bulb.

so sort in such way that a[i] is minimum and b[i] is maximum
by that way it cant give impact on bigger than a[i], so u only can choose a[i] bulb from a[i].

such that,

1 5 yes
1 4 no
1 4 no
1 3 no
2 4 Yes
2 3 Yes
2 3 no
2 1 no
3 3 yes
3 3 yes
5 4 yes
5 2 yes
5 1 yes
5 1 yes
5 1 yes
5 1 no

*/
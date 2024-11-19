#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (long long &x : v) cin >> x;
    sort(all(v));

    long long i, j, cnt=0;
    i = 0;
    j = n - 1;

    while (i < j)
    {
        if(v[i]+v[j]>m) j--;
        else{
            i++; j--;
        }
        cnt++;
    }

    if(i==j) cnt++;

    cout << cnt << endl;
}
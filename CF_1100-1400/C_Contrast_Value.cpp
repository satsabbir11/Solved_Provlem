#include <bits/stdc++.h>
using namespace std;

#define unik(a) unique(a.begin(), a.end()) - a.begin()

int unique_zigzag(vector<int> a)
{
    int n, ans;
    ans = n = unique(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n - 2; i++) ans -= ((a[i] < a[i + 1] && a[i + 1] < a[i + 2]) + (a[i] > a[i + 1] && a[i + 1] > a[i + 2]));
    return ans;
}

































































int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

       cout<<unique_zigzag(a)<<endl;
    }
}
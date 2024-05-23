#include <bits/stdc++.h>
using namespace std;

void keepBit(vector<int> &b, int n, int h = 1)
{
    int i = 25;
    for (i = 25; i >= 0; i--)
    {
        if (n >= (2 << i))
        {
            n -= (2 << i);
            b[i + 1] = b[i + 1] + h;
        }
    }
    if (n)
        b[i + 1] = b[i + 1] + h;
}

int number(vector<int> &b)
{
    int ans = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i])
        {
            ans += pow(2, i);
        }
    }
    return ans;
}

bool check(vector<int> &a, int k, int n)
{
    vector<int> b(32);
    for (int i = 1; i <= k; i++)
    {
        keepBit(b, a[i]); // first we keep 1 to k
    }

    int ans = number(b);

    for (int i = k + 1; i <= n; i++)
    {
        keepBit(b, a[i]);
        keepBit(b, a[i - k], -1); // slideing window

        if (ans != number(b)) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 2);
        for (int i = 0; i < n; i++)
            cin >> a[i + 1];

        int c = n;

        int l=1, r=n;
        while(l<r){
            int mid = l + (r-l)/2;
            if(check(a, mid, n)) r=mid;
            else l=mid+1;
        }

        cout <<l<< endl;
    }
}
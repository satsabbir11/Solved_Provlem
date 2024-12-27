#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> pre(n);
        int a[n + 2];

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i == 1)
                pre[i - 1] = a[i];
            else
                pre[i - 1] = pre[i - 2] + a[i];
        }

        //for(int i=0; i<n; i++) cout<<pre[i]<<" ";
        //cout<<endl;

        int sum = 0, ans = 0;
        for (int i = n; i >= 1; i--)
        {
            sum += a[i];
            int pos = lower_bound(all(pre), sum) - pre.begin();
            if (pre[pos]==sum and pos < i-1){
                //cout<<"true"<<endl;
                ans = max(pos+2 + n - i, ans);
                //cout<<i<<" "<<sum<<" "<<pos<<" "<<ans<<endl;
            }
        }
        cout << ans << endl;
    }
}
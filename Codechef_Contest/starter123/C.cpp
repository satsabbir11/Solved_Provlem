#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        long long a[n + 2], b[n + 2], k = 2, sum = 0;
        map<long long, long long> mp;
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        
        for (long long i = 1; i <= n; i++)
            sum += (2 * a[i]);

        while (q--)
        {
            bool f = false;
            k=2;
            long long x;
            cin >> x;
            map<long long, long long>temp=mp;

            for (long long i = 1; i < n; i++)
            {
                for (long long j = i + 1; j <= n; j++)
                    if (sum - a[i] - a[j] == x)
                    {
                       // cout<<a[i]<<" "<<a[j]<<endl;
                        b[1] = a[i];
                        b[n] = a[j];
                        temp[a[i]]--;
                        temp[a[j]]--;

                       for(auto [x, y]: mp){
                        //cout<<x<<" "<<temp[x]<<endl;
                        if(temp[x]) while(temp[x]>0) {b[k++] = x; temp[x]--;}
                       }
                       
                        f = true;
                        break;
                    }
                    if(f) break;
            }
            if (f)
                for (long long i = 1; i <= n; i++)
                    cout << b[i] << " ";
            else
                cout << -1;
            cout << endl;
        }
    }
}

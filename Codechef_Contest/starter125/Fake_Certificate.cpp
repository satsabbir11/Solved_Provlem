#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        string a;
        cin >> a;

        long long one = 0, zero = 0;
        vector<pair<long long, long long>> v;

        for (long long i = 0; i < n; i++)
        {
            if (a[i] == '1')
            {
                one++;
                if (zero)
                {
                    v.push_back({0,zero});
                    zero = 0;
                }
            }
            else
            {
                zero++;
                if (one)
                {
                    v.push_back({1, one});
                    one = 0;
                }
            }
        }
        if (zero)
        {
            v.push_back({0,zero});
            zero = 0;
        }
        if (one)
        {
             v.push_back({1, one});
            one = 0;
        }
        long long mx = v[0].second;
        if(v.size()==2) mx = v[0].second + v[1].second;
        else{
        for(int i=0;i<v.size()-2;i++){
           long long f = v[i].first, s = v[i].second;
           long long ff = v[i+2].first, ss = v[i+2].second;
           if(f==1) mx = max(mx, v[i].second+ v[i+1].second + v[i+2].second);
        }
        }
        cout<<mx<<endl;
    }
}
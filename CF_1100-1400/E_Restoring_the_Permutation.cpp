#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 2], mx[n+2]={};
        map<int, bool> mp, mp1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp[a[i]]=true;
        }
        vector<int>v;
        for (int i = 1; i <= n; i++)
        {
            if(!mp[i]) v.push_back(i);
        }

        int imi = 1;



        for (int i = 1; i <= n; i++)
        {
            if(!mp1[a[i]]){
                cout<<a[i]<<" ";
                mp1[a[i]]=true;
                mx[i]=a[i];
            }
            else{
                while(mp1[imi]) imi++;
                cout<<imi<<" ";
                mp1[imi]=true;
                imi++;
            }
        }

        cout<<endl;

        imi = 0;

        for (int i = 1; i <= n; i++)
        {
            int ans=0, pos =0;
            if(mx[i]){
                imi = mx[i];
                cout<<imi<<" ";
            }
            else{
                int l = 0, r= v.size()-1, pos=0;
                while(l<=r){
                    int mid = l + (r-l)/2;
                    if(v[mid]>imi) r=mid -1;
                    else{
                        l = mid+1;
                        if(ans<v[mid]){
                            ans = v[mid];
                            pos = mid;
                        }
                    }
                }
                cout<<ans<<" ";
                v.erase(v.begin()+pos);
            }
        }
        cout<<endl;
    }
}
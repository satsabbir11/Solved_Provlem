#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sn;
        cin >> sn;

        int i;
        bool f = false;

        for (int j = 2; j <= 1000; j++)
        {
            int p = 1;
            int ans = 1;
            for (int i = 1; i <= 30; i++)
            {
                p *= j;
                ans+=p;
                if(ans > 1e6) break;
                if(ans==sn && i>=2){
                    f=true;
                    break;
                }
            }
            if(f) break;
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, tot, c=1;
        cin >> n >> tot;
        if(n==1){
            cout<<tot<<endl;
            continue;
        }

        bool f=false;   

        while(c<=tot){
            c*=2;
        }


        long long ans = c/2 -1;

        cout<<ans<<" "<<tot-ans<<" ";
        n-=2;

        while(n--){
            cout<<0<<" "; 
        }
        cout<<endl;
    }
}
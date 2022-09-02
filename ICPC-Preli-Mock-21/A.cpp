#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first;
#define ss second;
double PI = 3.14159265358979323846;

int main()
{
    FastRead
    ll t = 1;
    //cin>>t;

    //ll p = 1;

    while(t--)
    {
        while(1)
        {
            string n;
            cin>>n;
            if(n == "0")
            {
                break;
            }


            ll p = n[n.size()-1]-'0';
            ll p1 = p*5;

            ll a = 0;

            for(ll i = 0; i < n.size()-1; i++)
            {
                ll p2 = n[i]-'0';
                a*=10;
                a+=p2;
            }
            if(abs(a-p1)%17 == 0)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }

    return 0;
}
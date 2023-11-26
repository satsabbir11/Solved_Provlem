#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long t;
    cin >> t;
    while (t--)
    {
       int a, b, c;
       cin>>a>>b>>c;
       bool f1, f2, f3;
       f1 = f2 = f3 = false;

       if(a%2==b%2) f3=true;
       if(c%2==b%2) f1=true;
       if(a%2==c%2) f2=true;

       cout<<f1<<" "<<f2<<" "<<f3<<endl;
    }
}

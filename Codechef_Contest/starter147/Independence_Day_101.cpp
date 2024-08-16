#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
         int a[3];
        for (int i = 0; i <= 2; i++)
            cin >> a[i];
        sort(a, a + 3);

        bool f=false;
        if(abs((a[0]+a[1])-a[2])<=1) f=true;
        cout<<(f?"YES":"NO")<<endl;
    }
}


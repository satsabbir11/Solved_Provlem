#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        int loop, ans;

        bool f= false;

        if (x > 1)
        {
            ans = 1;
            loop = n;
        }
        else
        { // x = 1
            if (k == 1)
            {
                cout << "NO" << endl;
                continue;
            }
            if (n % 2 == 0)
            {
                loop = n / 2;
                ans = 2;
            }
            else
            {
                if (k == 2)
                {
                    cout << "NO" << endl;
                    continue;
                }
                else{
                    ans = 2;
                    loop = (n-3)/2;
                    f = true;
                }
            }
        }

        cout<<"YES"<<endl;
        if(f) cout<<loop+1<<endl<<3<<" ";
        else cout<<loop<<endl;

        while(loop--) cout<<ans<<" ";

        cout << endl;
    }
}
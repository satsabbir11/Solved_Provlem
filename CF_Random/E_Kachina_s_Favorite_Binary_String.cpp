#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        string s;

        m = n;

        int tem = -1, in=0, val=-1;
        bool f = false;

        while (m > 1)
        {
            // 100101
            cout << "? 1 " << m << endl;
            cout.flush();
            int x;
            cin >> x;
            // cout<<x<<endl;

            if (m != n)
            {
                if (x < tem){
                    s += '1';
                    in = m+1;
                    val=tem;
                }
                else
                    s += '0';
                f = true;
            }
            if (m == 2) s += "00";
            
            tem = x;
            m--;
        }
        reverse(s.begin(), s.end());
        for(int i=0; i<n; i++) cout<<s[i];
        cout<<endl;
        cout<<in<<" "<<val<<endl;
        int z=0;
        bool g=false;
        for(int i=0; i<n; i++){
            if(s[i]=='0') z++;
            else{
                if(z){
                    g=true;
                    break;
                }
            }
        }
        if (f and g)
            cout << "! " << s << endl;
        else
            cout << "! IMPOSSIBLE" << endl;
        cout.flush();
    }
}
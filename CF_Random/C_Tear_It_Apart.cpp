#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int l = s.length(), ans=1e7;

        for (int i = 0; i < 26; i++)
        {
            char ch = 'a' + i;
            int len = 0, mx = 0;
            for (int j = 0; j < l; j++)
            {
                if (s[j] == ch)
                {
                    //cout<<len<<endl;
                    mx = max(mx, len);
                    len = 0;
                }
                else
                    len++;
            }
            mx = max(mx, len);
            ans = min(ans, mx);
        }
       int cnt=0;
       while(ans>0){
        ans/=2;
        cnt++;
       }
       cout<<cnt<<endl;
    }
}
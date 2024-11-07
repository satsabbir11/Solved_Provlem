#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int cnt1, cnt2;
        cnt1 = cnt2 = 0;

        if (s[0] == s[n - 1])
        {
            cout << n << endl;
            continue;
        }

        vector<int> v;
        int cnt, fnt;
        cnt = fnt =0;

        for (int i = 0; i < n; i++)
        {
            if(s[i]!=s[i+1]){
                if(s[i]=='a') cnt++;
                else fnt++;
            }
        }
        if(cnt>fnt){
            int x=0, y=0;
            for(int i=0; i<n; i++){
                if(s[i]=='a') x++;
                else break;
            }
            for(int i=n-1; i>=0; i--){
                if(s[i]=='b') y++;
                else break;
            }
            cout<<n-min(x, y)<<endl;
        }else{
            int x=0, y=0;
            for(int i=0; i<n; i++){
                if(s[i]=='b') x++;
                else break;
            }
            for(int i=n-1; i>=0; i--){
                if(s[i]=='a') y++;
                else break;
            }
            cout<<n-min(x, y)<<endl;
        }
    }
}

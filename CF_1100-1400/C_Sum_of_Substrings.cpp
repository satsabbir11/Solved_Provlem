#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, ll;
        string s;
        cin >> n >> k >> s;

        int cnt = 0;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1' && cnt<=k){
                swap(s[i], s[n-1]);
                k-=cnt;
                break;
            }
            cnt++;
        }

        for(int i=0;i<n-1;i++){
            if(s[i]=='1' && i<=k){
                swap(s[i], s[0]);
                break;
            }
        }

        int ans =0;

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1')
                ans++;
            else if (s[i] == '1' && s[i + 1] == '1')
                ans += 11;
            else if (s[i] == '1' && s[i + 1] == '0')
                ans += 10;
        }
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j
#define all(s) s.begin(), s.end()

#define bug(a) cout << #a << " : " << a << endl;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, X;
        cin >> n >> X >> k;

        string ss, s;
        cin >> ss;
        

        int in=n-1;

        for(int i=n-1; i>=0; i--){
            if(ss[i]=='0'){
                in = i;
                break;
            }
        }
        bool f=false;
        for(int i=0; i<=in; i++){
            if(ss[i]=='1') f=true;
            if(f) s+=ss[i];
        }
        int one = 0, zero = 0, ans = 0, balance = 0;

        for (char x : s)
        {
            if(x=='1'){
                one++;
            }
            else{
                one%=
            }
        }
        cout << ans << endl;
    }
}
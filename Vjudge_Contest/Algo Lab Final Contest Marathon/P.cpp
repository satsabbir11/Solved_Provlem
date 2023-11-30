#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f ? "YES" : "NO")
#define loj(i, j) "Case " << i << ": " << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, cnt = 0;
    string s;
    cin >> n >> s;

    int p[10] = {};

    sort(s.begin(), s.end());

    string ans;

    for (int i = n-1; i >= 0; i--)
    {
        int c = s[i] - '0';
        if(c==9){
            p[7]++;
            p[3]+=2;
            p[2]++;
        }else if(c==8){
            p[7]++;
            p[2]+=3;
        }else if(c==6){
            p[5]++;
            p[3]++;
        }
        else if(c==4){
            p[3]++;
            p[2]+=2;
        }
        else p[c]++;
    }

    for(int i=9;i>=2;i--){
        while(p[i]--) cout<<i;
    }
}
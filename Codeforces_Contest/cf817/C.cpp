
//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ

#include<bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000010
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")

#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))

#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define max5(a,b,c,d,e) max(max4(a,b,c,d),e)
#define min5(a,b,c,d,e) min(min4(a,b,c,d),e)

#define sortn(a,n,m) sort(a+m, s+m+n)
#define sortt(s) sort(s.begin(), s.end())
#define reversee(s) reverse(s.begin(), s.end())
#define reversesortt(s) sortt(s); reversee(s)
#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

// for (auto& x : a) cin >> x;

int main() {
    FastRead

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;

        vector<vector<string>>p;

        map<string, int>mp;
        
        for(int i=1;i<=3;i++){
            vector<string>g;
            for(int j=1;j<=n;j++){
                string s;
                cin>>s;
                g.push_back(s);
                mp[s]++;
            }
            p.push_back(g);
        }

        int pp[5]={};

        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
               if(mp[p[i][j]]==1) pp[i]+=3;
               else if(mp[p[i][j]]==2) pp[i]++;
            }
        }

       cout<<pp[0]<<" "<<pp[1]<<" "<<pp[2]<<endl;
    }
}
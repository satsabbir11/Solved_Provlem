#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned long long
#define con (f?"YES":"NO")

#define Dpos(n) fixed << setprecision(n)

#define CLR(a) memset(a, -1, sizeof(a))
#define CLN(a) memset(a, 0, sizeof(a))

#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define max5(a,b,c,d,e) max(max4(a,b,c,d),e)
#define min5(a,b,c,d,e) min(min4(a,b,c,d),e)

#define sortn(a,x,y) sort(a+x, a+x+y)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define reversesortv(s) sortv(s); reversev(s)

#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()+1
#define upperbound(v,x) upper_bound(v.begin(), v.end(), x)-v.begin()

#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

#define auto(x,a) for (auto& x : a)

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    string s;
    cin>>s;
    int n=s.size();

    int cnt=0;

    for(int i=0;i<n;i++){
        if(cnt==0 && s[i]=='h') cnt=1;
        else if(cnt==1 && s[i]=='e') cnt=2;
        else if(cnt==2 && s[i]=='l') cnt=3;
        else if(cnt==3 && s[i]=='l') cnt=4;
        else if(cnt==4 && s[i]=='o') cnt=5;

        if(cnt==5){
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;
}

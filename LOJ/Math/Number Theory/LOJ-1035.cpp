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

int nth_prime[105], vis[105]={};

void nthPrime(int limit=101){
    int ii=1;
    nth_prime[ii]=2;
    
    for(int i=3;i<=limit;i+=2){
        if(!vis[i]){
            nth_prime[++ii]=i;
            for(int j=i*i;j<=limit;j+=i) vis[j]=1;
        }
    }
}



int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t, tt=0;
    cin >> t;

    nthPrime(103);

    while (t--) {
        long long n;
        cin>>n;

        int nn=n,j;
        map<int, int>mp;
        set<int>s;


        for(int i=2;i<=n;i++){
            nn=i; j=1;
            while(nn>1){
                if(nn%nth_prime[j]==0){
                    s.insert(nth_prime[j]);
                    while(nn%nth_prime[j]==0){
                         mp[nth_prime[j]]++;
                         nn/=nth_prime[j];
                    }
                }
                else j++;
            }
        }

        int cnt=1;

        cout<<"Case "<<++tt<<": "<<n<<" = ";

        for(auto& x:s){
            if(cnt==1) cout<<x<<" ("<<mp[x]<<")";
            else cout<<" * "<<x<<" ("<<mp[x]<<")";
            cnt++;
        }
        cout<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define con (f?"YES":"NO")
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

#define dpos(n) fixed << setprecision(n)

#define clear1(a) memset(a, -1, sizeof(a))
#define clear0(a) memset(a, 0, sizeof(a))

#define sortn(a,x,n) sort(a+x, a+x+n)
#define sortv(s) sort(s.begin(), s.end())
#define reversev(s) reverse(s.begin(), s.end())
#define rsortv(s) sort(s.rbegin(),s.rend())
#define unik(a) unique(a.begin(), a.end()) - a.begin()
#define iotav(s, x) iota(s.begin(), s.end(), x)

#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()
#define upperbound(v,x) upper_bound(v.begin(), v.end(), x)-v.begin()

#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

#define auto(x,a) for (auto& x : a)
#define print(x) cout << #x << " = " << x << endl


long long dhara(long long start, long long gp, long long k){
    return start+gp*k;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, q;
        cin>>n>>q;

        long long tem = 0;
        
        vector<long long>v;

        bool f = true;

        long long st =2;

        while(1){
            if((n+(st/2))/st>=1) v.push_back((n+(st/2))/st);
            else break;
            //cout<<(n+(st/2))/st<<" ";
            st*=2;
        }


        long long cum[v.size()+1]={};

        for(long long i = 0; i<v.size(); i++){
            if(i==0) cum[i+1] = v[i];
            else cum[i+1] = cum[i]+v[i];
        }

        //cout<<cum[1]<<" ";

        long long target, back = 0;

        for(long long i=0; i<v.size(); i++){
            //cout<<v[i]<<" ";
            if(q<=cum[i+1]){
                target = pow(2, i);
                back = cum[i];
                break;
            }
        }

        cout<<dhara(target, target*2, q-back-1)<<endl;

        // cout<<target<<" "<<target*2<<" "<<q-back<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define MOD 1000000007
#define inf 1000000010
#define endl "\n"
#define ull unsigned long long
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

long long dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
long long dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

//k=1 , 1-9
//k=2 , 1-4
//k=3 , 1-3
//k=4 , 1-2
//k=5 , 1-1

long long pw[] = {0, 10, 5, 4, 3, 2};


long long bigMod(long long a, long long b)
{
    if (!b)
        return 1;
    long long res = bigMod(a, b >> 1);
    long long ans = (res * res) % MOD;
    if (b % 2)
        ans = (ans * a) % MOD;
    return ans;
}


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long l, r, k;
        cin>>l>>r>>k;

        if(k>=10){
            cout<<0<<endl;
            continue;
        }
        if(k>4) k=5;

        cout<<(bigMod(pw[k], r)-bigMod(pw[k], l)+MOD)%MOD<<endl;
    }
}
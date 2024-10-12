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

long long sum_of_absolute_differences_of_all_pairs_in_a_given_array(vector<int>a, long long n)
{
    long long ans = 0;
    long long m=((n-1)*n)/2;
    for (long long i = 0; i < n; i++)
        ans += a[i] * (2 * i - n + 1);
    return ans-m;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   string s; cin>>s;
   long long n = s.length();

   map<char, vector<int>>v;

   for(long long i=1; i<=n; i++){
    v[s[i-1]].push_back(i);
   }

   long long ans=0;

   for(auto &x: v){
    char c = x.first;
    long long n = x.second.size();
    long long cnt = sum_of_absolute_differences_of_all_pairs_in_a_given_array(x.second, n);
    //cout<<c<<" "<<cnt<<endl;
    ans+=cnt;
   }
   cout<<ans<<endl;
}


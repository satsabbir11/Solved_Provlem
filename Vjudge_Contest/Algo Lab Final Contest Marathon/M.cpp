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
#define unik(a) unique(a.begin(), a.end()) - a.begin()

#define lowerbound(v,x) lower_bound(v.begin(), v.end(), x)-v.begin()
#define upperbound(v,x) upper_bound(v.begin(), v.end(), x)-v.begin()

#define pb push_back
#define loj(i,j) "Case "<<i<<": "<<j
#define gap " "

#define auto(x,a) for (auto& x : a)

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool ifPossible(int n, int sum){
    return (sum>=0 && sum<=n*9);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   int m, s, sum;
   cin>>m>>sum;

   string mn, mx;

   s= sum;

   for(int i= 0 ; i<m; i++){
    for(int d = 0; d<10;d++){
        if((i>0 || d>0 || (m == 1 && d == 0)) && ifPossible(m-i-1, s-d)){
            mn+=char('0'+d);
            s-=d;
            break;
        }
    }
   }

   s= sum;

   for(int i= 0 ; i<m; i++){
    for(int d = 9; d>=0;d--){
        if((i>0 || d>0 || (m == 1 && d == 0)) && ifPossible(m-i-1, s-d)){
            mx+=char('0'+d);
            s-=d;
            break;
        }
    }
   }

   if(sum==0 && m>1){
    cout<<-1<<" "<<-1<<endl;
    return 0;
   }

   if(mn.size()==0){
    cout<<-1<<" "<<-1<<endl;
    return 0;
   }

   if(mn.size()>=2 && mn[0]==mn[1] && mn[0]=='0'){
    cout<<-1<<" "<<-1<<endl;
    return 0;
   }

   cout<<mn<<" "<<mx<<endl;
}
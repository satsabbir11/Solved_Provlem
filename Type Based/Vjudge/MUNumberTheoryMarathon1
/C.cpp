#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j
#define gcd(a, b)  __gcd(a, b)
#define lcm(a, b)  ((a)*((b)/gcd(a,b)))
#define lcm3(a, b, c) lcm(a, lcm(b, c))

long long lc(long long a, long long b, long long c){
    return (a*b*c)/__gcd(a, __gcd(b,c));
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long n, ans;
    cin>>n;

    if(n%2) ans = n*(n-1)*(n-2);
    else{
        if(lcm3(n-1, n-2, n-3)>lcm3(n, n-1, n-3)) ans = (n-1)*(n-2)*(n-3);
        else ans = (n-1)*(n)*(n-3);
    }

    cout<<max(n, ans)<<endl;
}
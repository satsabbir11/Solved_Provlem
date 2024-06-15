#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

long long getSum(string s, long long l, long long r){
    long long sum=0;
    for(long long i=l;i<r;i++){
        sum+=(s[i]-'0');
    }
    return sum;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

   long long n;
   cin>>n;
   vector<string>s(n);
   for(string &x: s) cin>>x;

   vector<vector<long long>>v(6, vector<long long>(46, 0)); //keep how many number with same length and sum

   for(string y: s){
    long long sum =0;
    for(char c: y) sum+=(c-'0');
    v[y.size()][sum]++;
   }

   sort(s.begin(), s.end(),[](string a, string b){
    return a.size()>b.size();
   });

   long long ans =0;
  
   for(string t: s){
    long long l = t.size();
    string tt= t;
    reverse(tt.begin(), tt.end());

    //suppose number is 937 46, so at first we need 9+3+7 -4-6 = 9 of length 1, secondly 9+3+7+4 -6=17 of length 3
    
    for(long long i = l%2;i<l;i+=2){
       long long sum = getSum(t, 0, (l+i)/2) - getSum(t, (l+i)/2, l); //add to right
       long long sum1 = getSum(tt, 0, (l+i)/2) - getSum(tt, (l+i)/2, l); //add to left
       ans+=v[i][max(0ll, sum)];
       ans+=v[i][max(0ll, sum1)];
    }
    ans+=v[l][getSum(t, 0, l)];
   }
   cout<<ans<<endl;
}
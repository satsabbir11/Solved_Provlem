#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

bool isMatch(string s){
    int sum1=0, sum=0;
    int l = s.size(), l1=l/2;
    for(int i=0;i<s.size();i++){
        if(i<l1) sum1+=(s[i]-'0');
        sum+=(s[i]-'0');
    }
    if(sum%2==0 && sum1==(sum/2)) return true;
    else return false;
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    t=1;
    while (t--) {
        long long n;
        cin>>n;
        
        string s[n];
        for(int i=0;i<n;i++) cin>>s[i];
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((s[i].size()+s[j].size())%2==0){
                    if(isMatch(s[i]+s[j])) cnt++;
                    if(isMatch(s[j]+s[i])) cnt++;
                }
            }
        }
        cout<<n+cnt<<endl;
    }
}
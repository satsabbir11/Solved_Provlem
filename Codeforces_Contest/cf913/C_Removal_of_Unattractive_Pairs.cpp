#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j


int numberOfMostFrequentElement(string &s) {
    map<char, int>mp;
    for(char x:s) mp[x]++;
    return max_element(mp.begin(), mp.end(),[](auto& a, auto& b){
        return a.second < b.second;
    })->second;
}
    


int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        
        string s;
        cin>>s;

        int mx = numberOfMostFrequentElement(s);

        if(mx<=n/2) cout<<n%2<<endl;
        else cout<<abs(mx-(n-mx))<<endl;
    }
}
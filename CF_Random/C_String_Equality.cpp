#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"Yes":"No")
#define loj(i,j) "Case "<<i<<": "<<j

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin>>n>>k;
        
        string s, t;
        cin>>s>>t;

        bool f=true;

        map<char, int>mp1, mp2;

       for(int c: s){
        mp1[c-'a']++;
       }
       for(int c: t){
        mp2[c-'a']++;
       }

       for(int i=0;i<26;i++){
        mp1[i]-=mp2[i];
        if(mp1[i]<0 || mp1[i]%k){
            f=false;
            break;
        }
        mp1[i+1]+=mp1[i];
       }

       cout<<con<<endl;
    }
}
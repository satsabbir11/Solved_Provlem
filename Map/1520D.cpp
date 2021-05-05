#include<bits/stdc++.h>
using namespace std;
int main()
{
    // #ifndef sabbir
    // freopen("/CP_OJ/input.txt", "r", stdin);
    // freopen("/CP_OJ/output.txt", "w", stdout);
    // #endif
    
    int t;
    cin>>t;
    while(t--){
    map<int,int>mp;
    long long int n,i,j,m,ara[2000],a,x,cnt=0;;
 
    cin>>n;
 
    for(i=1;i<=n;i++)
    {
        cin>>x;
        m=x-i;
        mp[m]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
 
        x=it->second;
      cnt+=(x*(x-1))/2;
 
 
    }
#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
    
    long long t;
    cin>>t;
    long long ar[100000][2];
       ar[0][0]=ar[0][1]=1;
       
       for(long long i=1;i<100000;i++)
       {
           ar[i][0]=ar[i-1][1];
           ar[i][1]=(ar[i-1][0]+ar[i-1][1])%(1000000007);
       }
       
   while(t--)
    {
       long long m,n;
       cin>>m>>n;
       long long a[m],b[m];
       long long as=0;
       long long bs=0;
       for(long long j=0;j<m;j++){
           cin>>a[j];
           as=(as+a[j])%1000000007;
       }
       for(long long j=0;j<m;j++){
           cin>>b[j];
           bs=(bs+b[j])%1000000007;
       }
       
       long long res=0;
       
       if(n==1){
           res=as;
       }
       else if(n==2){
           res=bs;
       }
       else if(n>=3){
               res=(ar[n-3][0]*as)%(1000000007);
               res=(res+(ar[n-3][1]*bs)%(1000000007))%1000000007;
           }
           
           res=(res*m)%1000000007;
    cout<<res<<endl;
    }
}
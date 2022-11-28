#include<bits/stdc++.h>
using namespace std;



long long int notprime[10000005]={}, prime[10000005];

void isPrime(){
   long long nn=10000005;
   long long int c=1, i, j;
   for(i=3;i*i<=nn;i+=2){
      if(!notprime[i]){
         for(j=i*i;j<=nn;j+=2*i){
            notprime[j]=1;
         }
      }
   }
}

int main()
{
   isPrime();
   
   int t;
   cin>>t;
   while(t--){
      bool f=false;
      map<long long, long long>mp;
      long long n;
      cin>>n;
      int a[n+2];
      for(long long i=1;i<=n;i++){
         cin>>a[i];
         mp[a[i]]=i;
      }
      sort(a+1, a+1+n);

      for(long long i=n;i>=1;i--){
         if(a[i]%2 && a[i] >1 && notprime[a[i]]==0){
            f=true;
            cout<<mp[a[i]]<<endl;
            break;
         }
      }
      if(!f) cout<<-1<<endl;
   }
}
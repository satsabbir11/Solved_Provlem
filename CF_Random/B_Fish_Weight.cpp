#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, m, k;
   cin>>n>>m>>k;
   int a[n+2], b[m+2];
   for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];

   sort(a+1, a+1+n);
   sort(b+1, b+1+m);

   bool f=false;

   int kk=m;

   for(int i=n; i>=1;i--){
    if(a[i]>b[kk--]) f=true;
    if(kk==0) break;
   }
   if(n>m) f=true;

   if(f) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

}
	  			 	 		 			  		  		 	  	 		
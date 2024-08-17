#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int a[n+3];
	    int zero = 0;
	    for(int i=1;i<=n;i++) {
	        cin>>a[i];
	        if(!a[i]) zero++;
	    }
	    sort(a+1, a+1+n);
	    
	    if(zero>=n-1 or a[1]==a[n]) cout<<"YES"<<endl;
	    else{
	        bool f=true;
	        for(int i=1;i<=n;i++){
	           if(a[i]==0 or a[i]==a[n]){}
               else{
	               f=false;
	               break;
	           } 
	        }
	        if(f) cout<<"YES"<<endl;
	        else cout<<"NO"<<endl;
	    }
	}

}

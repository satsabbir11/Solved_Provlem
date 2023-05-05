#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int j=1;j<=t;j++){
        string a;
        int b, i=0, rem=0;
        cin>>a>>b;
        b=abs(b);
        while(i<a.length()){
            if(a[i++]=='-') continue;
            rem = (rem*10+(a[i++]-'0'))%b;
            cout<<rem<<" ";
        }
        cout<<endl;

        cout<<"Case "<<j<<": "<<(rem?"not divisible":"divisible")<<endl;
    }
}
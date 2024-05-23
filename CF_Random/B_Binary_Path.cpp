#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        char s[3][n+1];
        for(int i=1;i<=2;i++) for(int j=1;j<=n;j++) cin>>s[i][j];
        int boundary = n, from=1;
        for(int i=1; i<n;i++) if(s[1][i+1]=='1' and s[2][i]=='0'){
            boundary = i;
            break;
        }

        for(int i=1; i<boundary;i++) if(s[1][i+1]=='0' and s[2][i]=='1'){
            from = i+1;
        }

        for(int i=1;i<=boundary;i++) cout<<s[1][i];
        for(int i=boundary;i<=n;i++) cout<<s[2][i];

        cout<<endl<<boundary-from+1<<endl;
    }
}
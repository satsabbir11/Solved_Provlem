#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        stack<int>st;
        int cnt=0;

        for(int i=0; i<n;i++){
            if(s[i]=='(' or (s[i]=='_' and st.empty())) st.push(i);
            else{
                int now = st.top();
                st.pop();

                cnt+=(i-now);
            }
        }

        cout<<cnt<<endl;
    }
}
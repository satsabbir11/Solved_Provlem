#include <bits/stdc++.h>
using namespace std;

vector<int>lps(string s){
    int n=s.size(), i=0, j=1;
    vector<int>v(n, 0);

    while(j<n){
        if(s[i]==s[j]) v[j] = ++i;
        else if(i){
            i = v[i-1];
            continue;
        }
        j++;
    }
    return v;
}

int main(){
    string s; cin>>s;
    int n = s.size();

    vector<int>v=lps(s);

    //for(int x: v) cout<<x<<" ";

    if(n<=1){
        cout<<"Just a legend"<<endl;
        return 0;
    }

    for(int i=0; i<n-1; i++){
        if(v[i]==v[n-1]){
            string f = s.substr(0, v[i]); //that means full size
            if(f.size()) cout<<f<<endl;
            else cout<<"Just a legend"<<endl;
            return 0;
        }
    }


    if(v[v[n-1]-1]) cout<<s.substr(0, v[v[n-1]-1])<<endl; // jodi full size o na hoy tahole er porer kom len er suf pref
    else cout<<"Just a legend"<<endl;
    
}
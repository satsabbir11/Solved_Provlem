#include <bits/stdc++.h>
using namespace std;

vector<int>countZeros(string s, int b){
    int cnt=0, i=0;
    vector<int>v;

    for(char c: s){
        i++;
        if(c=='0') cnt++;
        else cnt = 0;
        if(cnt==b){
            v.push_back(i);
            cnt=0;
        }
    }
    return v;
}

int main(){
    int n, a, b, k;
    cin>>n>>a>>b>>k;

    string s; cin>>s;
    vector<int>v = countZeros(s, b);
    cout<<v.size()-a+1<<endl;
    for(int i=0; i<v.size()-a+1; i++){
        cout<<v[i]<<" ";
    }
}
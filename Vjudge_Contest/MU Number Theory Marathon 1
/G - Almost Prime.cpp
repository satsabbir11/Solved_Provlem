#include <bits/stdc++.h>
using namespace std;


vector<int>generateNumberOfPrimeDivisor(int n = 1e6){
    vector<int>primeDivisor(n+1, 0);
    for(int i=2;i<=n;i++){
        if(primeDivisor[i]==0){
            for(int j=i;j<=n;j+=i){
                primeDivisor[j] ++;
            }
        }
    }
    return primeDivisor;
}

int main(){
    int n;
    cin>>n;
    int cnt =0;
    vector<int>v = generateNumberOfPrimeDivisor(n);
    for(int i=1;i<=n;i++){
        if(v[i]==2) cnt++;
    }
    cout<<cnt<<endl;
}

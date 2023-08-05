#include <bits/stdc++.h>
using namespace std;

vector<int>generateDivisor(int n){
    vector<int>divisor(n+1, 1);
    for(int i=2;i<=n;i++){
        if(divisor[i]==1){
            for(int j=i;j<=n;j+=i){
                int num = j, primeFactor = 0;
                while(num%i==0){
                    num/=i;
                    primeFactor++;
                }
                divisor[j] *= (primeFactor+1);
            }
        }
    }
    return divisor;
}

void changeChar(string& s, int i, int n) {
    int sum = 'W'+'B';
    if (n % 2) s[i] = sum - s[i];
}


int main(){
    int n;
    cin>>n;

    string s;
    s.assign(n, 'W');

    vector<int>divisor = generateDivisor(n);

    for(int i=0;i<n;i++) changeChar(s, i, divisor[i+1]);
    cout<<s<<endl;
}
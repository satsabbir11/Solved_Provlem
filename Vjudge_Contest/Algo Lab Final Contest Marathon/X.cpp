#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define con (f?"YES":"NO")
#define loj(i,j) "Case "<<i<<": "<<j

/*
    1. Generate divisor of 1 to n
    2. Time complexity: O(nlogn)
    3. maximum n = 10^6

    Usuage:
    1. Just call into main function - 
    vector<int>divisor = generateDivisor(n);
    2. divisor[12] = 6 
*/
vector<int>generateDivisor(int n = 1e6){
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

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0);

    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;

        long long mn = n;
        
        for(long long i=2;i*i<=n;i++){
            if(n%i==0){
                mn = i;
                break;
            }
        }

        cout<<mn<<endl;
    }
}
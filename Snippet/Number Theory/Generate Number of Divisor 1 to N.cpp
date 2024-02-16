#include <bits/stdc++.h>
using namespace std;

/*
    1. Generate Number of divisor of 1 to n
    2. Time complexity: O(nlogn)
    3. maximum n = 10^6

    Usuage:
    1. Just call into main function - 
    vector<int>divisor = generateNumberOfDivisor(n);
    2. divisor[12] = 6 
*/


vector<int>generateNumberOfDivisor(int n= 1e6){
    vector<int>divisor(n+1, 1); // by default all divisor number is 1
    for(int i=2;i<=n;i++){
        if(divisor[i]==1){ // that means i is prime
            for(int j=i;j<=n;j+=i){ // selet all multiple of prime j
                int num = j, primeFactor = 0;
                while(num%i==0){
                    num/=i;
                    primeFactor++; //find how many prime factor i lies in the j
                }
                divisor[j] *= (primeFactor+1); //multiple all combination of primefactor = total divisor
            }
        }
    }
    return divisor;
}

int main(){
    int n = 12;
    vector<int>divisor = generateNumberOfDivisor();
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<divisor[i]<<endl;
    }
    return 0;
}

/*
Input:
12

Output:
1 1
2 2
3 2
4 3
5 2
6 4
7 2
8 4
9 3
10 4
11 2
12 6

*/
#include<bits/stdc++.h>
using namespace std;

int minCoins(int *coin, int n, int W){
    int table[W+1];
    table[0]=0;
    for(int i=1;i<=W;i++) table[i] = INT_MAX;


    for(int i=1;i<=W;i++){
        for(int j=0;j<n;j++){
            if(coin[j]<=i){
                int sub_res = table[i-coin[j]];
                table[i] = min(sub_res+1, table[i]);
            }
        }
    }

    int WW = W;

    while(WW>0){
        int i = table[WW];
        cout<<coin[i]<<" ";
        WW-=coin[i];
    }
    cout<<endl;

    return table[W];
}

int nWays(int *coin, int n, int W){
    if(W==0) return 1;
    if(n<=0 || W<0) return 0;

    return nWays(coin, n-1, W) + nWays(coin, n, W-coin[n-1]);
}


int main() {
   int coins[] =  {9, 6, 5, 1};
    int n = sizeof(coins)/sizeof(coins[0]);
    int W = 11;
    int table[W+2];
    table[0]=0;
    for(int i=0;i<=W;i++) table[i]=INT_MAX;
    cout << "Minimum coins required is "
         << minCoins(coins, n, W)<<endl;

    cout << "Number of Way is "
         << nWays(coins, n, W);

    return 0;
}